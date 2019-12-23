

struct SectionUp {
	
	unsigned int header[2];
	
	//$assert(header[0]==1);
	//$assert(header[1]==1);
	
	if(0>4)
		$break_array(false);
	unsigned int data[array_index*2];
	
	unsigned int footer[2];
	
};

struct SectionDown {
	
	unsigned int header[2];
	
	//$assert(header[0]==1);
	//$assert(header[1]==1);
	
	if(0>4)
		$break_array(false);
	unsigned int data[2*(198-array_index)];
	
	unsigned int footer[2];
	
};

public struct section_1003 {
	unsigned int header[2];
	
	SectionUp data1[198];
	
	SectionDown data2[1];
	
	SectionDown data3[199];
	
	unsigned int footer[2];
	
};