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
typedef boost::dynamic_bitset<> dbitset;

const int CHAR_TO_INT = 48; //if you every convert a character to an integer,
//you have to subtract this number from it
const std::bitset<8> empty(0);

//using "T" is not necessary, you could use "E" just as well
template<class T>
void out(T a) {
  std::cout<<a;
}
template<class T>
void outf(String s, T a) { //formated out, replace first '*' with a else just put a after s
	if((signed)s.find("*") >=0)
  		std::cout<<s.substr(0,s.find("*"))<<a<<s.substr(s.find("*")+1)<<"\n";
  	else
  		std::cout<<s<<a<<"\n";
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
  //the programmer is completely finished outputting things.
}

class key
{
public:
	std::bitset<8> id; //for now a 8 bit id string
	dbitset value; //contains the binary value identified by id
	key(){
		id = std::bitset<8> (0);
		value = dbitset (0);
	}
	key(std::bitset<8> i, dbitset v): id(i), value(v) {}
	void print(){ //debug output
		outln("Key:");
		out("\t>"); outln(id);
		out("\t>"); outln(value);
	}
};
class File {
public:
	String name;
	String type; //file extension
	unsigned long length; //# of chars in file
	dbitset binary; //binary contents of the file
	std::ifstream file;
	File() : name(""), length(0), type(""), binary(dbitset(0)){}
	File(String fname) : name(fname) {
		file.open(name.c_str(), std::ios::in|std::ios::ate); //maybe not all necessary?
		if( file.is_open() ){
			type = name.substr(name.find_last_of(".") + 1);
			length = file.tellg(); //set length of the file
			binary = dbitset(length * 8); //make binary the correct size
			char c;
			file.seekg(0, std::ios::beg);
			for(long i = 0; i < length; i++){
				file.get(c);
				for(int b = 0; b < 8; b++){
					binary[i * 8 + b] = c >> (7 - b) & 1;
				}
			}
		} else {
			outln("File " + name + " not found");
			length = 0;
			type = "";
			binary = dbitset(0);
		}
		file.close();
	}
	bool operator[](signed long i){
		if ((i >= (signed)length * 8) || (i < (signed)length * -8)) {
			outln("WARNING: out of bounds");
			return false;
		}
		if (i >= 0)
			return (bool)binary[i];
		else
			return (bool)binary[length * 8 + i];
	}
	void print(){
		std::bitset<8> c;
		for(unsigned long i = 0; i < length; i++){
			for(int j = 0;j < 8; j++){
				c.set(7 - j, binary[i * 8 + j]);
			}
			out( (char)(c.to_ulong()) );
		}
		outlnend("");
	}
	void compress(){ //maybe make a new class?
		outln(name + " compressed");
	}
	void decompress(){
		outln(name + " decompressed");
	}
};
