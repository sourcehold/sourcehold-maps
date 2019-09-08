
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