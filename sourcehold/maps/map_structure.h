typedef struct {
    unsigned int decompressed_size;
	unsigned int compressed_size;
    unsigned int crc32;
    unsigned char data[compressed_size];
} CompressedSection;

typedef CompressedSection MapPreview;

typedef struct {
    unsigned int use_string_table;
    unsigned int string_table_index;

    unsigned int decompressed_size;
    unsigned int compressed_size;
    unsigned int crc32;
    unsigned char data[compressed_size];
} Description;

typedef struct {
	
	unsigned int data_size; //filesize-data_size is the offset where the data begins.
	unsigned int sections_count;
	unsigned int unknown_data[5];

	var max_sections = 100;
	if (unknown_data[0] <= 170 && unknown_data[0] >= 161)
	    max_sections = 150;

	unsigned int subsection_uncompressed_lengths[max_sections];
	unsigned int subsection_compressed_lengths[max_sections];
	unsigned int subsection_indices[max_sections];
	unsigned int compressed[max_sections];
	unsigned int offsets[max_sections];
	unsigned int unknown6;
	
} Directory;

struct Section {
	
	if (Index >= directory.sections_count)
		$break_array(false);
	
	var l = directory.subsection_compressed_lengths[Index];
	
	unsigned char data[l];
	
	Index = Index + 1;
};

public struct MapStructure {

	unsigned int magic;
	
	unsigned int preview_size;
	MapPreview map_preview;
	
	unsigned int description_size;
	Description description;


	unsigned int u1_size;
	unsigned char u1[u1_size];
	
	unsigned int u2_size;
	unsigned char u2[u2_size];
	
	unsigned int u3_size;
	unsigned char u3[u3_size];
	
	unsigned int u4_size;
	unsigned char u4[u4_size];
	
	unsigned int u5;
	
	unsigned int directory_size; //This number is actually 4 bytes too large (cross-validated with section information inside Directory). Don't know why.
	Directory directory;
	
	var Index = 0;
	
	Section sections[*];

	char padding[1];
};