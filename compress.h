#include "file.h"
#include "debug_utils.h"
#include <bitset>
class Compress
{
public:
	File f;
	Compress(String fname){
		f = File(fname);
		f.print();
	}
	void shrink(){
		std::vector<bool> str = f.substr(0);
		for(int i=0;i<str.size();i++){
			out(str[i]);
		}
		outln("");
	}

	void extract(){

	}
	
};