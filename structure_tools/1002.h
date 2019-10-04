

struct SectionUp {
	
	unsigned short header[2];
	
	//$assert(header[0]==1);
	//$assert(header[1]==1);
	
	if(0>4)
		$break_array(false);
	unsigned short data[array_index*2];
	
	unsigned short footer[2];
	
};

struct SectionDown {
	
	unsigned short header[2];
	
	//$assert(header[0]==1);
	//$assert(header[1]==1);
	
	if(0>4)
		$break_array(false);
	unsigned short data[2*(198-array_index)];
	
	unsigned short footer[2];
	
};

public struct section_1002 {
	unsigned short header[2];
	
	SectionUp data1[198];
	
	SectionDown data2[1];
	
	SectionDown data3[199];
	
	unsigned short footer[2];
	
};