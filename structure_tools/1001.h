
javascript
{
	function GetDocumentSize()
	{
		return document.FileSize;
	}
};


struct Section {
	
	if(current_offset >= GetDocumentSize())
		$break_array(false);
	
	unsigned short numbers[2*array_index];
	
	unsigned short data[244];
	
};

struct Section2 {
	
	//if(current_offset >= GetDocumentSize())
	//	$break_array(false);
	
	unsigned short numbers[2*(78-array_index)];
	
	unsigned short data[244];
	
};

public struct section_1001 {
	unsigned short u1[14884];
	Section sections_buildup[78];
	Section2 section_middle[1];
	Section2 sections2_diminish[78];
	unsigned short u2[14884];
};

struct Section_v2 {
	
	if(current_offset >= GetDocumentSize())
		$break_array(false);
	
	unsigned short numbers[2*array_index];
	
	unsigned short data[4];
	
};

struct Section2_v2 {
	
	//if(current_offset >= GetDocumentSize())
	//	$break_array(false);
	
	unsigned short numbers[2*(198-array_index)];
	
	unsigned short data[4];
	$assert(data[0] == 2);
	$assert(data[1] == 1);
	$assert(data[2] == 1);
	//$assert(data[3] == 2);
	
};

public struct section_1001_v2 {
	unsigned short u1[4];
	
	Section_v2 sections_buildup[198];
	Section2_v2 sections_middle[1];
	Section2_v2 sections_diminsh[198];
	
	unsigned short u2[4];
};