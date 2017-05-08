#include <iostream>
#include <fstream> //file io
#include <vector>
#include <bitset> //string->binary, probably has other functions
//include only those libraries and files that are actually used in the header
//all else should be put into compress.cpp
//in case we build a class that handles i/o, we should put it into the header
//and then include all the libraries/headers that we need to.

typedef std::string String;

const int CHAR_TO_INT = 48; //if you every convert a character to an integer,
//you have to subtract this number from it

//using "T" is not necessary, you could use "E" just as well
template<class T>
void out(T a) {
  std::cout<<a;
}

template<class T>
void outln(T a) {
  std::cout<<a<<'\n';
  //std::endl was not used because this "flushes" the stream
  //This reduces performance and optimization
}

template<class T>
void outlnend(T a) {
  std::cout<<a<<std::endl;
  //here it is used so that the programmer can flush and end the stream in case
  //the programmer is completely finished outputing things.
}



int filesize(const char* filename) {
	std::ifstream in(filename, std::ios::binary | std::ios::ate);
	return in.tellg();
}



class File {
public:
	//all public for now
	String name;
	String type;
	long length;
	char *contents;
	std::ifstream file;
	String fullbitset; //not used for now
	File() : name("") {
		contents = new char[0];
	}
	File(String fname) : name(fname) {
		file.open(name, std::ios::in|std::ios::binary|std::ios::ate); //maybe not all necessary?
		length = filesize(name.c_str()); //c_str makes a String or std::string into char*
		type = name.substr(name.find_last_of("."));
		contents = new char [length]; //length may totally blow up with gig sized files
		file.seekg (0, std::ios::beg);
		file.read (contents, length);
		file.close();
	}
	~File() {
		delete[] contents; //for every "new" there must be a delete or else you clog memory
	}
	String accessBinaryStringAtIndex(long i) {
		//long datatype for now, may need to be long long
		if (i > length) return "Out of bounds!"; //later add a try/catch error statement
		return ((std::bitset<8>)contents[i]).to_string(); //cast from char -> bitset<8> -> string
	}
	void compress(){
		outln(name + " compressed");
	}
	void decompress(){
		outln(name + " decompressed");
	}
};
