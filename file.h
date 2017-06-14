#include "debug_utils.h"
#include <fstream> //file io
#include <vector>
#include <bitset>
#pragma once

typedef std::string String;
typedef std::vector<bool> bitstring;
int to_int(bitstring b){
	int result = 0;
	for(int i = 0; i < b.size(); i++){
		result |= b[i];
		result << 1;
	}
	return result;
};
bitstring from_int(int n){
	bitstring b;
	for(int i = 0; i < 32; i++){
		b.push_back(n >> (31 - i) & 1);
	}
	return b;
};
class File {
public: //switch to private after debug
	short extrabits;
public:
	/*
	These variables should stay public
	*/
	String name; //path to file (name)
	String type; //file extension
	bitstring binary; //binary contents of the file
	bool isCompressed;
	File() : name(""), type(""), isCompressed(false){}
	/*TODO:
		make a header file that holds all possible keys
	*/
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
			if( substr(i, i + b.size()) == b ){ //== checks size then members of a vector for equality
				if(first)
					return true;
				first = true;
				i+= b.size() - 1; //no overlap
			}
		}
		return false;
	}
	std::vector<bitstring> getRepeatingBitstrings(bitstring seed, int number=100){
		//will not return exactly "number" bitstrings
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
			if(bits.size() >= number){ //timeout
				return bits;
			}
			b = bits[i];
			b.push_back(false);
			if( has2(b) ){
				bits.push_back(b);
				/*
				for(int j=0;j<b.size();j++){
					out(b[j]);
				}
				outlnend("");
				//*/
			}
			b.pop_back();
			b.push_back(true);
			if( has2(b) ){
				bits.push_back(b);
				/*
				for(int j=0;j<b.size();j++){
					out(b[j]);
				}
				outlnend("");
				//*/
			}
		}
		return bits;
	}
	void stats(){
		outln("File:");
		outf("\tName: *\n", name);
		outf("\tType: *\n", type);
		outf("\tSize: * bytes\n", binary.size() / 8);
		outf("\tExtrabits: * bits", extrabits);
		outln();
	}
	void print(){
		if(isCompressed) return;
		std::bitset<8> c;
		for(unsigned long i = 0; i < binary.size() / 8; i++){
			for(int j = 0; j < 8; j++){
				c.set(7 - j, binary[i * 8 + j]);
			}
			out( (char)(c.to_ulong()) );
		}
		outlnend("");
	}
	void compress(){
		if(isCompressed) return;
		isCompressed = true;
		name += ".compress";
		type = "compress";
	}
	void extract(){
		if(!isCompressed) return;
		isCompressed = false;
		name = name.substr(0, name.rfind(".compress"));
		type = name.substr(name.find_last_of(".") + 1);
	}
	void open(String filename) {
		std::ifstream file;
		binary.clear();
		name = filename;
		//open file with cursor at the end (ate)
		file.open(name.c_str(), std::ios::in|std::ios::ate);
		if( file.is_open() ){
			type = name.substr(name.find_last_of(".") + 1);
			if(type == "compress"){
				isCompressed = true;
				//outln("you opened a compressed file");
				file.seekg(0, std::ios::beg);
				char c;
				//read header
				if(file.get(c)){
					extrabits = 0;
					extrabits |= c >> 7 & 1;
					extrabits << 1;
					extrabits |= c >> 6 & 1;
					extrabits << 1;
					extrabits |= c >> 5 & 1;
					//use extra 5 bits as a check that the data is a compressed format?
				} else {
					outln("WARNING: Empty Compressed File");
				}
				//read in actual data
				while( file.get(c) ){
					for(int b = 0; b < 8; b++){
						binary.push_back(c >> (7 - b) & 1);
					}
				}
				//remove extra bits from end
				for(short i=0; i < extrabits; i++){
					binary.pop_back();
				}

			} else {
				extrabits = 0;
				outln("you opened a normal file");
				file.seekg(0, std::ios::beg);
				char c;
				while( file.get(c) ){
					for(int b = 0; b < 8; b++){
						binary.push_back(c >> (7 - b) & 1);
					}
				}
			}
		} else {
			outln("File " + name + " not found");
			type = "";
			extrabits = 0;
		}
		file.close();
	}
	void close(){ //write the file to storage, will create new file if none exists
		std::ofstream outfile;
		if(isCompressed){ //write a compressed file if file isCompressed
			outfile.open(name, std::ofstream::out);
			if( outfile.is_open() ){
				std::bitset<8> c;
				extrabits = binary.size() % 8;
				//write file header, first 3 bits are the extra bits, next 5 are unused
				c.set(7, extrabits >> 2 & 1);
				c.set(6, extrabits >> 1 & 1);
				c.set(5, extrabits & 1);
				outfile.put( (char)(c.to_ulong()) );
				//write data to file
				for(unsigned long long i = 0; i < binary.size(); i++) {
					c.set(7 - (i % 8), binary[i]);
					if(i % 8 == 7) {
						outfile.put( (char)(c.to_ulong()) );
					}
				}
				//write extra bits
				if(binary.size() % 8 != 0){
					//set remaining bits in c to zero and write to file
					for(int i = binary.size() % 8; i < 8; i++){
						c.set(7 - i, false);
					}
				}
			} else {
				outlnend("error writing file"); //never runs?
			}
		} else {
			outfile.open(name, std::ofstream::out);
			if( outfile.is_open() ){
				std::bitset<8> c;
				//write no header
				//write data to file
				for(unsigned long long i = 0; i < binary.size(); i++) {
					c.set(7 - (i % 8), binary[i]);
					if(i % 8 == 7) {
						outfile.put( (char)(c.to_ulong()) );
					}
				}
				//don't write extra bits
			} else {
				outlnend("error writing file"); //never runs?
			}
		}
		outfile.close();
	}
};
