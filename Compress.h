#include "File.h"
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
class Compress
{
public:
	File f;
	Compress(String fname){
		f = File(fname);
		f.print();
	}
	
};