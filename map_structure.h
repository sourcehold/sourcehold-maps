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
	
	unsigned int data_size; //filesize-data_size is the offset where the data begins.
	unsigned int sections_count;
	unsigned int unknown_data[5];
	unsigned int subsection_uncompressed_lengths[122];
	unsigned int unknown[28];
	unsigned int subsection_compressed_lengths[122];
	unsigned int unknown2[28];
	unsigned int subsection_indices[122];
	unsigned int unknown3[28];
	unsigned int compressed[122];
	unsigned int unknown4[28];
	unsigned int offsets[122];
	unsigned int unknown5[28];
	
} Meta;

struct Section {
	
	if (Index >= meta.sections_count)
		$break_array(false);
	
	var l = meta.subsection_compressed_lengths[Index];
	
	unsigned char data[l];
	
	Index = Index + 1;
};

public struct MapStructure2 {

	unsigned int magic;
	
	unsigned int preview_length;
	MapPreview map_preview;
	
	unsigned int description_length;
	Description description;

	
	unsigned int unknown_section_2_length;
	unsigned char unknown_section_2_data[unknown_section_2_length];
	
	unsigned int unknown_section_3_length;
	unsigned char unknown_section_3_data[unknown_section_3_length];
	
	unsigned int unknown_section_4_length;
	unsigned char unknown_section_4_data[unknown_section_4_length];
	
	unsigned int unknown_section_5_length;
	unsigned char unknown_section_5_data[unknown_section_5_length];
	
	unsigned char unknown_section_6_data[4];
	
	unsigned int meta_size;
	Meta meta;
	
	unsigned int unknown7;
	
	var Index = 0;
	
	Section sections[*];
	
};