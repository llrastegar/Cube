#include "debug_utils.h"
#include <vector>
typedef std::vector<bool> bitstring;
class fileheader
{
public:
	/* header format?
	HEADER
		3 bits <extrabits>
		n bits <keys>
	END OF HEADER
		n bits data

	*/
	unsigned short extrabits; //# of extra bits at the end of the file
	//some sort of vector to store keys? do we want to store keys in the header?
	fileheader() : extrabits(0) {
	};
	fileheader(unsigned short ebits) : extrabits(ebits) {
	};
	bitstring getHeader(){
		bitstring b;
		//I think this would be better hardcoded (no for loop)
		b.push_back(extrabits >> 2 & 1);
		b.push_back(extrabits >> 1 & 1);
		b.push_back(extrabits & 1);
		return b;
	}

	
};