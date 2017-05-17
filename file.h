#include "debug_utils.h"
#include <fstream> //file io
#include <vector>
#include <bitset>
#pragma once
typedef std::string String;
typedef std::vector<bool> bitstring;

class File {
private:
	std::ifstream file;
public:
	/*
	These variables should stay public
	*/
	String name; //path to file (name)
	String type; //file extension
	unsigned long length; //# of chars in file
	bitstring binary; //binary contents of the file

	File() : name(""), length(0), type(""){}

	File(String fname) : name(fname) {
		//open file with cursor at the end (ate)
		file.open(name.c_str(), std::ios::in|std::ios::ate);
		if( file.is_open() ){
			type = name.substr(name.find_last_of(".") + 1);
			length = file.tellg();
			file.seekg(0, std::ios::beg);
			char c;
			while( file.get(c) ){
				for(int b = 0; b < 8; b++){
					binary.push_back(c >> (7 - b) & 1);
				}
			}
		} else {
			outln("File " + name + " not found");
			length = 0;
			type = "";
		}
		file.close();
	}
	bitstring substr(long start){
		return substr(start, binary.size());
	}
	bitstring substr(long start, long end){
		bitstring v;
		for(long i = start; i < end; i++){
			v.push_back(binary[i]);
		}
		return v;
	}
	void print(){
		std::bitset<8> c;
		for(unsigned long i = 0; i < length; i++){
			for(int j = 0; j < 8; j++){
				c.set(7 - j, binary[i * 8 + j]);
			}
			out( (char)(c.to_ulong()) );
		}
		outlnend("");
	}
};
