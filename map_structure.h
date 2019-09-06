
typedef struct {
    unsigned int map_preview_decompressed_size;
	unsigned int map_preview_data_length;
    unsigned int map_preview_data_crc32;
    unsigned char data[map_preview_data_length];
} MapPreview;

typedef struct {
    unsigned int description_decompressed_size;
    unsigned int description_data_length_maybe;
    unsigned int description_crc32_maybe;
    unsigned char data[description_data_length_maybe];
} Description;

typedef struct {
    unsigned int length_of_section;
    unsigned char unknown_data[length_of_section];
} UnknownStruct1;

typedef struct {
    unsigned int unknown;
    unsigned int length_of_uncompressed_section;
    unsigned int length_of_section;
    unsigned char unknown_data[length_of_section];
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
    unsigned char unknown_data[length_of_section];
} UnknownStruct4;

public struct MapStructure {
	unsigned int magic;
	$assert(magic == 0xFFFFFFFF);
	unsigned int length_of_section_1;

	MapPreview map_preview;

	$assert(current_offset == (4 + 4 + length_of_section_1));

    unsigned int length_of_section_2;
    unsigned int unknown_4;
    unsigned int unknown_5;


    Description description;

    $assert(current_offset == (4 + 4 + length_of_section_1 + 4 + length_of_section_2));

    UnknownStruct1 u1;

    UnknownStruct1 u2;

    UnknownStruct1 u3;

    UnknownStruct1 u4;

//From here it gets a bit weird.
    UnknownStruct3 u5;

    UnknownStruct4 u6;

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
	
	unsigned char u19[160800];
	
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
	
	unsigned int u42[65654];
	
	UnknownStruct4 u43;
	
	UnknownStruct2 u44;
	
	unsigned int u45[97];
	unsigned char u46[3];
	
	UnknownStruct4 u47;
	
	unsigned int u48[18060];
	
	UnknownStruct4 u49;
	
	unsigned char u50[38];

	UnknownStruct4 u51;
	
	UnknownStruct2 u52;
	
	UnknownStruct2 u53;
	
	UnknownStruct2 u54;
	
	unsigned char u55[54];

	UnknownStruct4 u56;
	
	UnknownStruct2 u57;
	
	UnknownStruct2 u58;
	
	UnknownStruct2 u59;
	
	UnknownStruct2 u60;
	
	unsigned char u61[1172];
	
	UnknownStruct4 u62;
	
	UnknownStruct2 u63;
	
	unsigned int crc32;
	
	unsigned char noidea;
};