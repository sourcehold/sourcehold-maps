
javascript {
	function get_map_width(x) {
		x = x - 512;
		x = Math.round(Math.sqrt(x));
		return x;
	}
};

javascript {
	function get_magic_length_1(width) {
		return ((4*width) + 4)*width;
	}
};

typedef struct {
    unsigned int map_preview_decompressed_size;
	unsigned int map_preview_data_length;
    unsigned int map_preview_data_crc32;
    unsigned char data[map_preview_data_length];
} MapPreview;

typedef struct {
    unsigned int unknown_4;
    unsigned int unknown_5;

    unsigned int description_decompressed_size;
    unsigned int description_data_length;
    unsigned int description_crc32;
    unsigned char data[description_data_length];
} Description;

typedef struct {
    unsigned int length_of_section;
    unsigned char unknown_data[length_of_section];
} UnknownStruct1;

typedef struct {
	unsigned int length_of_section; //3036
	unsigned int data_size; //filesize-data_size is the offset where the data begins.
	unsigned int sections_count;
	unsigned int unknown_data[5];
	unsigned int subsection_uncompressed_lengths[122];
	unsigned int unknown[28];
	unsigned int subsection_compressed_lengths[122];
	unsigned int unknown2[28];
	unsigned int subsection_inidices[122];
	unsigned int unknown3[28];
	unsigned int compressed[122];
	unsigned int unknown4[28];
	unsigned int offsets[122];
	unsigned int unknown5[28];
	//unsigned int unknown6;
	
} MetaStruct1;

typedef struct {
    unsigned int unknown;
    unsigned int length_of_uncompressed_section;
    unsigned int length_of_section;
	unsigned int crc32;
    unsigned char unknown_data[length_of_section-4];
} UnknownStruct2;

typedef struct {
    unsigned int unknown;
    //unsigned int length_of_uncompressed_section;
    unsigned int length_of_section;
    unsigned char unknown_data[length_of_section-4];
} UnknownStruct3;

typedef struct {
    //unsigned int unknown;
    unsigned int length_of_uncompressed_section;
    unsigned int length_of_section;
	unsigned int crc32;
    unsigned char unknown_data[length_of_section-4];
} UnknownStruct4;

public struct MapStructure {
	unsigned int magic;
	$assert(magic == 0xFFFFFFFF);
	unsigned int length_of_section_1;

	MapPreview map_preview;

	//$assert(current_offset == (4 + 4 + length_of_section_1));

    unsigned int length_of_section_2;


    Description description;

    //$assert(current_offset == (4 + 4 + length_of_section_1 + 4 + length_of_section_2));

    UnknownStruct1 u1;

    UnknownStruct1 u2;

    UnknownStruct1 u3;

    UnknownStruct1 u4;
	
	unsigned int unknown_1;

//From here it gets a bit weird.
    MetaStruct1 u5;

    UnknownStruct2 u6;

//The repetition of chunks is wrong here, as the next int is too high to be a size indicator.
    UnknownStruct2 u7; //PKware compressed!

    //The repetition of chunks is wrong here, as the next int is too high to be a size indicator.
    UnknownStruct2 u8;


    UnknownStruct2 u9;

    UnknownStruct2 u10;

    UnknownStruct2 u11;

    UnknownStruct2 u12;
	
	UnknownStruct2 u13;
	
	UnknownStruct2 u14;
	
	UnknownStruct2 u15;
	
	UnknownStruct2 u16;
	
	UnknownStruct2 u17;
	
	UnknownStruct2 u18;
	
	unsigned char u19[get_magic_length_1(get_map_width(map_preview.map_preview_decompressed_size))];
	
	UnknownStruct2 u20;
	
	UnknownStruct2 u21;
	
	UnknownStruct2 u22;
	
	UnknownStruct2 u23;
	
	UnknownStruct2 u24;
	
	UnknownStruct2 u25;
	
	UnknownStruct2 u26;
	
	UnknownStruct2 u27;
	
	UnknownStruct2 u28;
	
	UnknownStruct2 u29;
	
	UnknownStruct2 u30;
	
	UnknownStruct2 u31;
	
	UnknownStruct2 u32;
	
	UnknownStruct2 u33;
	
	UnknownStruct2 u34;
	
	UnknownStruct2 u35;
	
	UnknownStruct2 u36;
	
	UnknownStruct2 u37;
	
	UnknownStruct2 u38;
	
	unsigned int u39[7];
	
	UnknownStruct2 u40;
	
	UnknownStruct2 u41;
	
	unsigned char u42[262608];
	
	unsigned char u43[4];
	
	UnknownStruct2 u44;
	
	unsigned char u45[4];
	
	unsigned char u46[4];
	
	unsigned char u47[4];
	
	UnknownStruct2 u48;
	
	unsigned char u49[4];
	
	unsigned char u50[4];

	unsigned char u51[4];
	
	unsigned char u52[4];
	
	unsigned char u53[4];
	

	
	unsigned char u54[100];
	unsigned char u55[80];
	unsigned char u56[28];
	unsigned char u57[4];
	unsigned char u58[200];
	unsigned char u59[4];

	
	UnknownStruct2 u60;
	
	unsigned char u61[32000];
	
	unsigned char u62[100];
	
	unsigned char u63[40016];
	
	unsigned char u64[4];
	unsigned char u65[4];
	unsigned char u66[4];
	unsigned char u67[4];
	unsigned char u68[4];
	unsigned char u69[4];
	unsigned char u70[4];
	unsigned char u71[4];
	unsigned char u72[4];
	unsigned char u73[4];
	unsigned char u74[4];
	unsigned char u75[4];
	unsigned char u76[4];
	unsigned char u77[4];
	unsigned char u78[4];
	unsigned char u79[4];
	unsigned char u80[4];
	unsigned char u81[4];
	unsigned char u82[4];
	unsigned char u83[4];
	unsigned char u84[4];
	unsigned char u85[4];
	unsigned char u86[4];
	
	UnknownStruct2 u87;
	
	unsigned char u88[4];
	unsigned char u89[4];
	unsigned char u90[14];
	unsigned char u91[2];
	unsigned char u92[2];
	unsigned char u93[2];
	unsigned char u94[2];
	unsigned char u95[2];
	unsigned char u96[2];
	
	UnknownStruct2 u97;
	
	UnknownStruct2 u98;
	
	UnknownStruct2 u99;
	
	UnknownStruct2 u100;
	
	unsigned char error4[54];
	
	UnknownStruct4 u104;
	
	UnknownStruct2 u105;
	
	UnknownStruct2 u106;
	
	UnknownStruct2 u107;
	
	UnknownStruct2 u108;
	
	unsigned char error5[1172];
	
	UnknownStruct4 u125;
	
	UnknownStruct2 u126;
	
	unsigned char error6[4];
	
	unsigned char u127;
};