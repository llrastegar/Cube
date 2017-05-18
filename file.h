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
		return bitstring(binary.begin()+start, binary.end());
	}
	bitstring substr(long start, long end){
		return bitstring(binary.begin()+start, binary.begin()+end);
	}
	int getNumRepeat(bitstring b){ //returns the number of times the bitstring repeats(no overlap)
		int count = 0;
		for(long i = 0; i < binary.size() - b.size(); i++){
			if( substr(i, i + b.size()) == b ){
				count++;
				i+= b.size() - 1; //no overlap
			}
		}
		return count;
	}
	bool has2(bitstring b){
		bool first = false;
		for(long i = 0; i < binary.size() - b.size(); i++){
			if( substr(i, i + b.size()) == b ){ //== checks length then members of a vector for equality
				if(first)
					return true;
				first = true;
				i+= b.size() - 1; //no overlap
			}
		}
		return false;
	}
	std::vector<bitstring> getRepeatingBitstrings(bitstring seed){
		std::vector<bitstring> bits;
		bits.push_back(seed);
		bitstring b;
		/*
		b.push_back(false);
		bits.push_back(b);
		b.clear();
		b.push_back(true);
		bits.push_back(b);
		b.clear();
		//*/
		for(long i = 0; i < bits.size(); i++){
			if(bits.size() > 10000){ //timeout if
				return bits;
			}
			b = bits[i];
			b.push_back(false);
			if( has2(b) ){
				bits.push_back(b);
				for(int j=0;j<b.size();j++){
					out(b[j]);
				}
				outlnend("");
			}
			b.pop_back();
			b.push_back(true);
			if( has2(b) ){
				bits.push_back(b);
				for(int j=0;j<b.size();j++){
					out(b[j]);
				}
				outlnend("");
			}
		}
		return bits;
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
