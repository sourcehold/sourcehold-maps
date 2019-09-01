
typedef struct {
	unsigned int magic;
	unsigned int u0;
	unsigned int size;
	$assert(size == 0x9E40);
	unsigned int u1;
	unsigned int u6;
	unsigned char u2;
	unsigned char u3;
	$assert(u3 == 0x06);
	unsigned char u4;
	unsigned char u5;
	unsigned char data[0x2814-24];
} MiniMap;

public struct map_structure {
	MiniMap minimap;
	
};