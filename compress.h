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
  //This reduces time and optimizes the program
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
	unsigned long length; //we dont need a negative size
	char *contents;
	std::ifstream file;
	File() : name("") {
		contents = new char[0];
		length = 0;
		type = "";
	}
	File(String fname) : name(fname) {
		file.open(name.c_str(), std::ios::in|std::ios::binary|std::ios::ate); //maybe not all necessary?
		if( file.is_open() ){
			length = file.tellg();
			type = name.substr(name.find_last_of(".")+1);
			contents = new char [length]; //length may totally blow up with gig sized files
			file.seekg (0, std::ios::beg);
			file.read (contents, length);
		} else {
			outln("File " + name + " not found");
			contents = new char[0];
			length = 0;
			type = "";
		}
		file.close();
	}
	~File() {
		if (file.is_open()) file.close();
		delete[] contents;
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
