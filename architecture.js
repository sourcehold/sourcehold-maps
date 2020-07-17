

var LITTLE_ENDIAN = true;


class InterpretationBuffer {
    constructor(buffer) {
        //this.data = new Uint8Array(data);
        this.buffer = buffer || new ArrayBuffer(32000000); //32MB
        this.view = new DataView(this.buffer);
        this.index = 0;
        this.size = this.buffer.byteLength;
    }

    readShort() {
        var value = this.view.getUint16(this.index, LITTLE_ENDIAN);
        this.index += 2;
        return value;
    }

    readShorts(n) {
        return new Uint16Array([...Array(n).keys()].map(() => this.readShort()));
    }

    readInt() {
        var value = this.view.getUint32(this.index, LITTLE_ENDIAN);
        this.index += 4;
        return value;
    }

    readInts(n) {
        return new Uint32Array([...Array(n).keys()].map(() => this.readInt()));
    }

    readByte() {
        var value = this.view.getUint8(this.index);
        this.index += 1;
        return value;
    }

    readBytes(n) {
        return new Uint8Array([...Array(n).keys()].map(() => this.readByte()));
    }

    hasRemaining() {
        return this.index < this.size;
    }

    writeInt(value) {
        this.ensureSize();
        // var buffer = new ArrayBuffer(4);
        // var view = new DataView(buffer);
        this.view.setUint32(this.index, value, LITTLE_ENDIAN);
        // for(var i = 0; i < 4; i++) {
        //     this.data[this.index + i] = view.getUint8(i);
        // }
        this.index += 4;
        this.size += 4;
    }

    writeInts(data) {
        data.forEach(v => this.writeInt(v));
    }

    writeByte(value) {
        this.ensureSize();
        this.view.setUint8(this.index, value);
        this.index += 1;
        this.size += 1;
    }

    writeBytes(data) {
        data.forEach(v => this.writeByte(v));
    }

    ensureSize(n) {
        var diff = this.size - this.index ;
        n = n || 16000000; //16MB
        if(diff < n) {
            var newBuffer = new ArrayBuffer(this.size + n);
            new Uint8Array(newBuffer).set(new Uint8Array(this.buffer));
            this.buffer = newBuffer;
            this.view = new DataView(this.buffer);
        }
    }

    truncate() {
        var newBuffer = new ArrayBuffer(this.index);
        new Uint8Array(newBuffer).set(new Uint8Array(this.buffer).subarray(0, this.index));
        this.buffer = newBuffer;
        this.view = new DataView(this.buffer);
    }

    getValue() {
        return this.buffer;
    }
}


class Structure {
    deserialize_from(buffer) {
        throw "not implemented";
    }
    serialize_to(buffer) {
        throw "not implemented";
    }
    pack() {
        //throw "not implemented";
    }
    unpack() {
        //throw "not implemented";
    }
    get_data() {
        throw "not implemented";
    }
    set_data(data) {
        throw "not implemented";
    }
}




class SizePrefixedSection extends Structure {
    constructor() {
        super()
    }

    serialize_to(buffer) {
        buffer.writeInt(this.data_size);
        buffer.writeBytes(this.data);

        return this;
    }

    deserialize_from(buffer) {
        this.data_size = buffer.readInt();
        this.data = buffer.readBytes(this.data_size);

        return this;
    }

    pack() {
        this.data_size = this.data.length;
    }

    unpack() {
        this.validate();
    }

    validate() {
        if(this.data_size != this.data.length) {
            throw "size not equal to data length";
        }
    }

    get_data() {
        return this.data;
    }

    set_data(data) {
        this.data = data;
    }
}


class Section extends Structure {
    constructor() {
        super()
    }

    get size() {
        throw "not implemented";
    }
}

class DataSection extends Section {
    constructor(length) {
        super()
        this.length = length;
    }

    get size() {
        return this.length;
    }

    pack() {
        this.length = this.data.length;
    }

    unpack() {
        this.validate();
    }

    validate() {
        if(this.length != this.data.length) {
            throw "invalid length specified";
        }
    }

    serialize_to(buffer) {
        buffer.writeBytes(this.data);
        return this;
    }

    deserialize_from(buffer) {
        this.data = buffer.readBytes(this.length);
        return this;
    }

    get_data() {
        return this.data;
    }

    set_data(data) {
        this.data = data;
    }
}

class CompressedSection extends Section {

    constructor() {
        super()
    }

    get size() {
        return 4 + 4 + 4 + this.compressed_size;
    }
    
    deserialize_from(buffer) {
        this.uncompressed_size = buffer.readInt();
        this.compressed_size = buffer.readInt();
        this.hash = buffer.readInt();
        this.data = buffer.readBytes(this.compressed_size);

        return this;
    }

    serialize_to(buffer) {
        buffer.writeInt(this.uncompressed_size);
        buffer.writeInt(this.compressed_size);
        buffer.writeInt(this.hash);
        buffer.writeBytes(this.data);

        return this;
    }

    unpack() {
        this.compression_level = this.data[1];
        this.processed_data = decompress(this.data, this.uncompressed_size);
        this.validate();
    }

    validate() {
        if(crc32(this.processed_data) != this.hash) {
            throw "invalid crc32, check decompression algorithm";
        }
        if(this.processed_data.length != this.uncompressed_size) {
            throw "invalid size spec"
        }
    }

    pack() {
        this.uncompressed_size = this.processed_data.length;
        this.data = compress(this.processed_data, this.compression_level || 6);
        this.hash = crc32(this.processed_data);
        this.compressed_size = this.data.length;
    }

    get_data() {
        return this.processed_data;
    }

    set_data(data) {
        this.processed_data = data;
    }

}


class Preview extends CompressedSection {
    
    constructor() {
        super()
    }

    deserialize_from(buffer){
        this.preview_size = buffer.readInt();
        super.deserialize_from(buffer);
        return this;
    }

    serialize_to(buffer){
        buffer.writeInt(this.preview_size);
        super.serialize_to(buffer);
        return this;
    }

    pack() {
        super.pack();
        this.preview_size = this.size;
    }

    validate() {
        if(this.preview_size != this.size) {
            throw "invalid size";
        }
    }

}

class Description extends CompressedSection {
    constructor() {
        super()
    }

    deserialize_from(buffer) {
        this.description_size = buffer.readInt();
        this.use_string_table = buffer.readInt();
        this.string_table_index = buffer.readInt();
        super.deserialize_from(buffer);

        return this;
    }

    serialize_to(buffer) {
        buffer.writeInt(this.description_size);
        buffer.writeInt(this.use_string_table);
        buffer.writeInt(this.string_table_index);
        super.serialize_to(buffer);

        return this;
    }

    validate() {
        if(this.description_size != this.compressed_size + (5 * 4)) {
            throw "invalid size";
        }
        super.validate();
    }

    unpack() {
        super.unpack();
    }

    pack() {
        super.pack();
        this.description_size = this.compressed_size + (5 * 4);
    }
}


class Directory extends Structure {
    constructor() {
        super()
    }

    get max_sections_count() {
        return this.u1 >= 161 ? 150 : 100;
    }

    deserialize_from(buffer) {
        this.directory_size = buffer.readInt();
        this.total_data_size = buffer.readInt();
        this.sections_count = buffer.readInt();
        this.u1 = buffer.readInt();
        this.u2 = buffer.readInt();
        this.u3 = buffer.readInt();
        this.u4 = buffer.readInt();
        this.u5 = buffer.readInt();
        this.section_uncompressed_lengths = buffer.readInts(this.max_sections_count);
        this.section_lengths = buffer.readInts(this.max_sections_count);
        this.section_indices = buffer.readInts(this.max_sections_count);
        this.section_compressed = buffer.readInts(this.max_sections_count);
        this.section_offsets = buffer.readInts(this.max_sections_count);
        this.u6 = buffer.readInt();

        this.sections = [];
        for(var i =0; i < this.sections_count; i++) {
            var compressed = this.section_compressed[i] == 1;
            var length = this.section_lengths[i];
            var index = this.section_indices[i];
            var cls = getSectionClassForIndex(index, compressed);
            this.sections.push(new cls(length).deserialize_from(buffer));
        }

        return this;
    }

    serialize_to(buffer) {

        buffer.writeInt(this.directory_size);
        buffer.writeInt(this.total_data_size);
        buffer.writeInt(this.sections_count);
        buffer.writeInt(this.u1);
        buffer.writeInt(this.u2);
        buffer.writeInt(this.u3);
        buffer.writeInt(this.u4);
        buffer.writeInt(this.u5);
        buffer.writeInts(this.section_uncompressed_lengths);
        buffer.writeInts(this.section_lengths);
        buffer.writeInts(this.section_indices);
        buffer.writeInts(this.section_compressed);
        buffer.writeInts(this.section_offsets);
        buffer.writeInt(this.u6);

        for(let section of this.sections) {
            section.serialize_to(buffer);
        }

        return this;

    }

    pack() {
        for(let section of this.sections) {
            section.pack();
        }

        var accumulator = 0;

        this.sections_count = this.sections.length;
        for(let i in this.sections) {
            var section = this.sections[i]
            if(section instanceof CompressedSection) {
                this.section_uncompressed_lengths[i] = section.uncompressed_size;
                this.section_lengths[i] = section.size;
                this.section_compressed[i] = 1;
            } else if(section instanceof DataSection) {
                this.section_uncompressed_lengths[i] = section.size;
                this.section_lengths[i] = section.size;
                this.section_compressed[i] = 0;
            }

            this.section_offsets[i] = accumulator;
            accumulator += this.section_lengths[i];
        }

        for(var i = this.sections_count; i < this.max_sections_count; i++) {
            this.section_lengths[i] = 0;
            this.section_uncompressed_lengths[i] = 0;
            this.section_compressed[i] = 0;
            this.section_indices[i] = 0;
            this.section_offsets[i] = 0;  // TODO check this
        }

        this.total_data_size = accumulator;
        this.directory_size = (20*this.max_sections_count) + 36;
    }

    section_for_index(index) {
        var i = this.section_indices.index(index);
        if(i == -1) {
            throw "index not found in directory";
        }
        return this.sections[i];
    }

    unpack() {
        for(let section of this.sections) {
            section.unpack();
        }
    }
}



class Map extends Structure {
    constructor() {
        super()
    }

    deserialize_from(buffer) {
        this.magic = buffer.readInt();
        this.preview = new Preview().deserialize_from(buffer);
        this.description = new Description().deserialize_from(buffer);
        this.u1 = new MapPropertySection1().deserialize_from(buffer);
        this.u2 = new MapPropertySection2().deserialize_from(buffer);
        this.u3 = new MapPropertySection3().deserialize_from(buffer);
        this.u4 = new MapPropertySection4().deserialize_from(buffer);
        this.ud = buffer.readInt();
    
        this.directory = new Directory().deserialize_from(buffer);
        return this;
    }

    serialize_to(buffer) {
        buffer.writeInt(this.magic);
        this.preview.serialize_to(buffer);
        this.description.serialize_to(buffer);
        this.u1.serialize_to(buffer);
        this.u2.serialize_to(buffer);
        this.u3.serialize_to(buffer);
        this.u4.serialize_to(buffer);
        buffer.writeInt(this.ud);

        this.directory.serialize_to(buffer);

        return this;
    }

    unpack() {
        this.preview.unpack();
        this.description.unpack();
        this.directory.unpack();
    }

    pack() {
        this.magic = 0xFFFFFFFF;
        this.preview.pack();
        this.description.pack();
        this.directory.pack();
        this.u1.pack();
        this.u2.pack();
        this.u3.pack();
        this.u4.pack();
    }

    export_to_zip() {
        this.unpack();

        var zip = new JSZip();

        var preview_folder = zip.folder("preview");
        preview_folder.file("processed_data", this.preview.processed_data);

        var description_folder = zip.folder("description");
        description_folder.file("processed_data", this.description.processed_data);
        description_folder.file("use_string_table", this.description.use_string_table.toString());
        description_folder.file("string_table_index", this.description.string_table_index.toString());

        var directory_folder = zip.folder("directory");
        var compressed = this.directory.section_compressed.join(",");
        var indices = this.directory.section_indices.join(",");
        directory_folder.file("section_compressed", compressed);
        directory_folder.file("section_indices", indices);

        for(let index in this.directory.sections) {
            var section = this.directory.sections[index];
            var key = this.directory.section_indices[index];

            directory_folder.file(key, this.directory.sections[index].get_data());
        }

        directory_folder.file("u1", this.directory.u1.toString());
        directory_folder.file("u2", this.directory.u2.toString());
        directory_folder.file("u3", this.directory.u3.toString());
        directory_folder.file("u4", this.directory.u4.toString());
        directory_folder.file("u5", this.directory.u5.toString());
        directory_folder.file("u6", this.directory.u6.toString());


        zip.file("u1", this.u1.get_data());
        zip.file("u2", this.u2.get_data());
        zip.file("u3", this.u3.get_data());
        zip.file("u4", this.u4.get_data());
        zip.file("ud", this.ud.toString());

        return zip;
    }

    async import_from_zip(zip) {

        var preview_folder = zip.folder("preview");
        this.preview = new Preview();
        this.preview.processed_data = await preview_folder.file("processed_data").async("uint8array");

        var description_folder = zip.folder("description");
        this.description = new Description();
        this.description.processed_data = await description_folder.file("processed_data").async("uint8array");
        this.description.use_string_table = parseInt(await description_folder.file("use_string_table").async("string"));
        this.description.string_table_index = parseInt(await description_folder.file("string_table_index").async('string'));

        var directory_folder = zip.folder("directory");
        this.directory = new Directory();
        var compressed = await directory_folder.file("section_compressed").async("string");
        this.directory.section_compressed = compressed.split(",").map((v) => parseInt(v));
        var indices = await directory_folder.file("section_indices").async("string");
        this.directory.section_indices = indices.split(",").map((v) => parseInt(v));

        this.directory.sections = [];
        this.directory.section_offsets = [];
        this.directory.section_lengths = [];
        this.directory.section_uncompressed_lengths = [];


        var count = 0;

        for(let index in this.directory.section_indices) {
            var key = this.directory.section_indices[index];
            var compressed = this.directory.section_compressed[index];

            if(key == 0) {
                this.directory.section_offsets.push(0);
                this.directory.section_lengths.push(0);
                this.directory.section_uncompressed_lengths.push(0);
            } else {
                count += 1;
                var cls = getSectionClassForIndex(key, compressed);
                var data = await directory_folder.file(key).async("uint8array");
                var length = data.length;
                var section = new cls(length);
                section.set_data(data);
    
                this.directory.sections.push(section);
                this.directory.section_offsets.push(0); //These values will be set later when pack() is called;
                this.directory.section_lengths.push(0); //These values will be set later when pack() is called;
                this.directory.section_uncompressed_lengths.push(0); //These values will be set later when pack() is called;
            }


        }

        this.directory.sections_count = count;

        this.directory.u1 = parseInt(await directory_folder.file("u1").async("string"));
        this.directory.u2 = parseInt(await directory_folder.file("u2").async("string"));
        this.directory.u3 = parseInt(await directory_folder.file("u3").async("string"));
        this.directory.u4 = parseInt(await directory_folder.file("u4").async("string"));
        this.directory.u5 = parseInt(await directory_folder.file("u5").async("string"));
        this.directory.u6 = parseInt(await directory_folder.file("u6").async("string"));


        this.u1 = new MapPropertySection1();
        this.u1.set_data(await zip.file("u1").async("uint8array"));
        this.u2 = new MapPropertySection2();
        this.u2.set_data(await zip.file("u2").async("uint8array"));
        this.u3 = new MapPropertySection3();
        this.u3.set_data(await zip.file("u3").async("uint8array"));
        this.u4 = new MapPropertySection4();
        this.u4.set_data(await zip.file("u4").async("uint8array"));
        this.ud = parseInt(await zip.file("ud").async("string"));
        

        return this;
    }
}

const _BUFFER = new ArrayBuffer(4);
const _VIEW = new DataView(_BUFFER);

function intToBytes(value) {
    _VIEW.setUint32(0, value, LITTLE_ENDIAN);
    return new Uint8Array(_BUFFER);
}

function bytesToInt(values) {
    values = values.subarray(0, 4);
    _BUFFER = values.buffer;
    return _VIEW.getUint32(0, LITTLE_ENDIAN);
}

class Section1001 extends CompressedSection {
    constructor() {
        super()
    }
}

MAP_SECTIONS = {
    1001: Section1001
};

function getSectionClassForIndex(index, compressed) {
    if(Object.keys(MAP_SECTIONS).includes(index)) {
        return MAP_SECTIONS[index];
    }
    if(compressed) {
        return CompressedSection;
    }
    return DataSection;
}


class MapPropertySection1 extends SizePrefixedSection {
    constructor() {
        super()
    }


}

class MapPropertySection2 extends SizePrefixedSection {
    constructor() {
        super()
    }


}

class MapPropertySection3 extends SizePrefixedSection {
    constructor() {
        super()
    }


}


class MapPropertySection4 extends SizePrefixedSection {
    constructor() {
        super()
    }


}

