#include "compress.h"
#include <fstream> //file io
#include <vector>
#include <bitset> //string->binary, probably has other functions

const int CHAR_TO_INT = 48; //if you every convert a character to an integer, you have to subtract this number from it

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

int main() {
	File mp3File("playingaround.mp3"); //courtesy of Alex Bohm
	out("Name: "); outln(mp3File.name);
	outln(mp3File.type);
	out("Size: "); outln(mp3File.length);
	outlnend(mp3File.accessBinaryStringAtIndex(1890));
}
