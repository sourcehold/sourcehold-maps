
function test_decompress() {
    console.log(decompress([0, 6, 130, 36, 37, 15, 2, 254, 1], 100));
}

function crc32_pklib(data) {
    crc32_pklib_wasm = Module.cwrap('crc32_pklib', 'number', ['number', 'number', 'number']);
    var indata = new Uint8Array(data);
    var indatalen = indata.length;

    var pbInBuff = allocate(indata, 'i8', ALLOC_NORMAL);
    var pbInBuffEnd = allocate([indatalen], 'i32', ALLOC_NORMAL);

    var oldCrc = 0;
    var pboldCrc = allocate([oldCrc], 'i32', ALLOC_NORMAL);

    var result = crc32_pklib_wasm(pbInBuff, pbInBuffEnd, pboldCrc);

    Module._free(pbInBuff);
    Module._free(pbInBuffEnd);
    Module._free(pboldCrc);

    return result;
}

function crc32(data) {
    var hash = CRC32.buf(data);
    while(hash < 0) {
        hash += (2**32);
    }
    return hash;
}

function decompress(data, decompressed_size) {

    var OUTBUFFERSIZE = decompressed_size || 31 * 1000 * 1000;

    explode_nocb = Module.cwrap('explode_nocb', 'number', ['number', 'number', 'number', 'number']);
    var indata = new Uint8Array(data);
    var indatalen = indata.length;

    var pbInBuff = allocate(indata, 'i8', ALLOC_NORMAL);
    var pbInBuffEnd = indatalen;

    var outdata = new Uint8Array(OUTBUFFERSIZE);
    var outdatalen = outdata.length;

    var pbOutBuff = allocate(outdata, 'i8', ALLOC_NORMAL);
    var pbOutBuffEnd = allocate([outdatalen], 'i32', ALLOC_NORMAL);

    // Call function and get result
    var result = explode_nocb(pbOutBuff, pbOutBuffEnd, pbInBuff, pbInBuffEnd);

    var decompressed = new Uint8Array(Module.HEAP8.subarray(pbOutBuff, pbOutBuff + getValue(pbOutBuffEnd, 'i32')));

    Module._free(pbInBuff);
    Module._free(pbOutBuff);
    Module._free(pbOutBuffEnd);

    return decompressed;
}

function test_compress() {
    console.log(compress(decompress([0, 6, 130, 36, 37, 15, 2, 254, 1], 100)));
}

function compress(data, level) {
    level = level || 6;

    var OUTBUFFERSIZE = data.length || 31 * 1000 * 1000;

    implode_nocb = Module.cwrap('implode_nocb', 'number', ['number', 'number', 'number', 'number', 'number', 'number']);
    var indata = new Uint8Array(data);
    var indatalen = indata.length;

    var pbInBuff = allocate(indata, 'i8', ALLOC_DYNAMIC);
    var pbInBuffEnd = indatalen;

    var outdata = new Uint8Array(OUTBUFFERSIZE);
    var outdatalen = outdata.length;

    var pbOutBuff = allocate(outdata, 'i8', ALLOC_DYNAMIC);
    var pbOutBuffEnd = allocate([outdatalen], 'i32', ALLOC_DYNAMIC);

    level = level - 3;
    var type = 0;

    var result = implode_nocb(pbOutBuff, pbOutBuffEnd, pbInBuff, pbInBuffEnd, type, level);

    var compressed = new Uint8Array(Module.HEAP8.subarray(pbOutBuff, pbOutBuff + getValue(pbOutBuffEnd, 'i32')));

    Module._free(pbInBuff);
    Module._free(pbOutBuff);
    Module._free(pbOutBuffEnd);

    return compressed;
}

async function load_map_buffer() {
    var data = await localforage.getItem('mapfile').then((filehandle) => filehandle.arrayBuffer());
    var buffer = new InterpretationBuffer(data);
    return buffer;
}

async function store_map_zip(map) {
    return await map.export_to_zip().generateAsync({type: "blob"}).then((blob) => localforage.setItem('zipfile', blob));
}

async function convert_map_to_zip() {
    var file = document.querySelector('#mapfileselect').files[0];
    var buffer = await file.arrayBuffer().then((buffer) => new InterpretationBuffer(buffer));
    var map = new Map().deserialize_from(buffer);
    map.unpack();
    var zip = await map.export_to_zip().generateAsync({type: "blob"});
    download_blob(zip, file.name + ".zip");
}