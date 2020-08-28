
typedef struct SimpleSection {
    unsigned int section_size;
    // The data array is of size section_size
    unsigned char *section_data;
}

typedef struct CompressedSection {
    unsigned int decompressed_size;
	unsigned int compressed_size;
    unsigned int crc32_hash;
    // The data array is of size compressed_size
    unsigned char *section_data;
} CompressedSection;

typedef struct Description {
    unsigned int use_string_table;
    unsigned int string_table_index;

    // This is the same as for a CompressedSection
    unsigned int decompressed_size;
    unsigned int compressed_size;
    unsigned int crc32_hash;

    // The actual text is here, and is of size compressed_size (decompressed_size is always 1000, because nul terminated string I guess)
    unsigned char *data;
} Description;

unsigned int max_sections = 150;

typedef struct Directory {
	
	unsigned int data_size; //filesize-data_size is the offset where the data begins.
	unsigned int sections_count;
	unsigned int unknown_data[5];

    // If a SHC map, there is room for 150 sections. If a SH map, there is room for 100 sections.
    //	var max_sections = 100;
    //	if (unknown_data[0] >= 161)
    //	    max_sections = 150;

    // The size is max_sections
	unsigned int section_uncompressed_lengths[max_sections];
	// The size is max_sections
	unsigned int section_compressed_lengths[max_sections];

	// All indices are numbers between 1000 and 1200. 0's mean no section. amount of non-zeroes == sections_count
	// The size is max_sections
	unsigned int section_indices[max_sections];
	// The size is max_sections
	unsigned int section_is_compressed[max_sections];
	// The size is max_sections
	unsigned int section_offsets[max_sections];
	unsigned int unknown7;
	
} Directory;

// For every section in the Directory, check if it is compressed, before you use the data inside.
// You could first allocate the sections by making a mapping of section_indices and byte arrays of size section_compressed_lengths. And then process the sections.
struct MapSection {
	unsigned char *map_section_data;
};

// A CompressedMapSection is the same as a CompressedSection
typedef CompressedSection CompressedMapSection;

public struct Map {

    // Value is always 0xFFFFFFFF
	unsigned int magic;

	// The size of the preview section (the whole CompressedSection): uint, uint, uint, bytes
	unsigned int preview_size;
	// The map_preview image is a CompressedSection.
	CompressedSection map_preview;

	// The size of the description section (the whole section): uint, uint, uint, uint, uint, bytes
	unsigned int description_size;
	// It is like a CompressedSection, but with two uints before that.
	Description description;

    // This stuff is somewhat unknown, but contains map info such as the type, balanced or not, etcetera.
	SimpleSection u1;
	SimpleSection u2;
	SimpleSection u3;
	SimpleSection u4;
	unsigned int u5;
	
    // The size of the directory, generally 3036 for SHC maps, and 2036 for SH maps.
	unsigned int directory_size;
	Directory directory;
	
	// var Index = 0;

};

// This is how an uncompressed Map preview is structured. It is an pallette image
typedef struct MapPreview {

    unsigned short rgb15_colour_pallette[256];
    unsigned int colour_indices[200*200];

} MapPreview;

typedef struct ByteTilesSection {

    // There are 80400 tiles on a map, that is why.
    unsigned char tiles[80400];
}

typedef struct ShortTilesSection {

    unsigned short tiles[80400];
}

typedef struct IntTilesSection {

    unsigned int tiles[80400];
}

