#include <iostream>
#include <fstream> //file io
#include <vector>
#include <bitset> //string->binary, probably has other functions
//include only those libraries and files that are actually used in the header
//all else should be put into compress.cpp
//in case we build a class that handles i/o, we should put it into the header
//and then include all the libraries/headers that we need to.
#include <boost/dynamic_bitset.hpp>

typedef std::string String;

const int CHAR_TO_INT = 48; //if you every convert a character to an integer,
//you have to subtract this number from it
const std::bitset<8> empty(0);

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
class key
{
public:
	std::bitset<8> id; //8 bit id string
	boost::dynamic_bitset<> value; //contains the binary value identified by id
	key(){
		id = std::bitset<8> (0);
		value = boost::dynamic_bitset<> (0);
	}
	key(std::bitset<8> i, boost::dynamic_bitset<> v): id(i), value(v) {}
	void print(){ //debug output
		outln("Key:");
		out("\t>"); outln(id);
		out("\t>"); outln(value);
	}
};
class File {
public:
	//all public for now
	String name;
	String type;
	unsigned long length; //we dont need a negative size
	char *contents;
	std::ifstream file;
	File() : name(""), length(0), type(""){
		contents = new char[0];
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
		delete[] contents;
	}
	std::bitset<8> operator[](signed long i){
		if ((i>=0 && i > length) || (i<0 && i < -1 * length)) { //0000
			outln("WARNING: out of bounds");
			return empty;
		}
		if (i>=0)
			return (std::bitset<8>)contents[i];
		else
			return (std::bitset<8>)contents[length+i]; //contents[-1] should equal last char in file
	}
	void compress(){
		for(char id=48;id<123;id++){ //limit on the # of keys (range) for now
			//go through file and check for a binary string equal to that of the id
				//for each found string compare the bits comming after and push that into the key value
				//remove the common bits after each id string, leaving the id bits in for decompress
		}
		outln(name + " compressed");
	}
	void decompress(){
		outln(name + " decompressed");
	}
};
