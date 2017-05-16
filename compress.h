#include "file.h"
#include "debug_utils.h"
class Compress
{
public:
	File f;
	Compress(String fname){
		f = File(fname);
		f.print();
	}
	
};