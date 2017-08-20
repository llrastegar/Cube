/*
The second iteration of the file class.
The main purpose of this is to know exactly how the information 
is stored(eg not using a byte in order to store a single bit)
*/
#include <string.h>
#include <fstream>
#include <stdexcept>
#pragma once

void OutofBounds(long long i){
	throw std::invalid_argument("Index " + std::to_string(i) +" Out of Bounds");
};
class File2
{
public: //switch to private after debug is done
	char* bytes;
	const char* name;
	unsigned long long length; //length of file in bits
public:
	File2(){
		length = 0;
		bytes = new char[0];
		name = "DEFAULT NAME";
	}
	File2(std::string fname){
		name = fname.c_str();
		//open the file
		std::ifstream file;
		file.open(name, std::ios::in | std::ifstream::ate);
		if( file.is_open() ){
			//get the length and setup memory
			length = (long long)file.tellg() * 8;
			bytes = new char[ file.tellg() ];
			//read the file to memory
			file.seekg(0, std::ios::beg);
			long i = 0;
			while(file.get(bytes[i])){
				i++;
			}
		} else {
			throw std::runtime_error("File not found");
		}
		//always close the file
		file.close();
	}
	~File2(){
		delete[] bytes;
	}
	//WARNING
	//this funcion will remove any data that extends the resize length
	void resize(unsigned long long len){
		//store len for later
		long long new_len = len;
		//set len to len of data in bytes
		if (len % 8 > 0){
			len = len / 8 + 1;
		} else {
			len = len / 8;
		}
		//set length to length of data in bytes
		if (length % 8 > 0){
			length = length / 8 + 1;
		} else {
			length = length / 8;
		}
		//make a new array of correct size
		char * temp;
		temp = new char[len];
		//fill new array
		for(unsigned long i = 0; i < length; i++){
			temp[i] = bytes[i];
		}
		//remove old data
		delete[] bytes;
		//set pointer to new data
		length = new_len;
		bytes = temp;
	}
	//returns file size in bits
	unsigned long long size(){
		return length;
	}
	//return bit at i in file
	bool operator[](unsigned long long i) const {
		if(i >= length){
			OutofBounds(i);
		}
		return ( bytes[i / 8] >> (7 - (i % 8)) ) & 0x1;
	}
	//set bit i in file to state
	void set(unsigned long long i, bool state = false){
		if(i >= length){
			OutofBounds(i);
		}
		if(state){
			bytes[i / 8] |= true << (7 - (i % 8));
		} else {
			bytes[i / 8] &= ~( true << (7 - (i % 8)) );
		}
	}
};