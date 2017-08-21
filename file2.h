/*
The second iteration of the file class.
The main purpose of this is to know exactly how the information 
is stored(eg not using a byte in order to store a single bit)
*/
#include <string.h>
#include <fstream>
#include <stdexcept>
#pragma once

typedef unsigned long long lengthtype;

void OutofBounds(long long i){
	throw std::invalid_argument("Index " + std::to_string(i) +" Out of Bounds");
};
class File2
{
public: //switch to private after debug is done
	char* bytes;
	const char* name;
	lengthtype length; //length of file in bits
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
			length = (lengthtype)file.tellg() * 8;
			bytes = new char[ file.tellg() ];
			//read the file to memory
			file.seekg(0, std::ios::beg);
			lengthtype i = 0;
			while(file.get(bytes[i])){
				i++;
			}
		} else {
			throw std::runtime_error("File not found");
		}
		//always close the file
		file.close();
	}
	void close(std::string fname){
		std::ofstream file;
		file.open(fname.c_str(), std::ios::out);
		if( file.is_open() ){
			//write data to file
			lengthtype length_in_bytes = length / 8;
			//if the length is not a multiple of 8, add one to fit data
			if (length % 8 > 0){
				length_in_bytes++;
			}
			for(lengthtype i = 0; i < length_in_bytes; i++){
				file.put(bytes[i]);
			}
		} else {
			throw std::runtime_error("Error Writing file");
		}
		//always close the file
		file.close();
	}
	void close(){
		close((std::string)name);
	}
	~File2(){
		delete[] bytes;
	}
	//WARNING:
	//this funcion will remove any data that extends the resize length
	void resize(lengthtype len){
		//get old length of data
		lengthtype old_length_in_bytes = length / 8;
		//check if length extends past a multiple of 8
		if (length % 8 > 0){
			old_length_in_bytes++;
		}

		//set length to new length
		length = len;

		//get new length in bytes
		lengthtype length_in_bytes = length / 8;
		//if the length is not a multiple of 8, add one to fit data
		if (length % 8 > 0){
			length_in_bytes++;
		}

		//make a new array of correct size
		char * temp;
		temp = new char[length_in_bytes];
		//fill new array
		for(lengthtype i = 0; i < old_length_in_bytes; i++){
			temp[i] = bytes[i];
		}
		//remove old data
		delete[] bytes;
		//set pointer to new data
		bytes = temp;
	}
	//returns file size in bits
	lengthtype size(){
		return length;
	}
	//return bit at i in file
	bool operator[](lengthtype i) const {
		if(i >= length){
			OutofBounds(i);
		}
		return ( bytes[i / 8] >> (7 - (i % 8)) ) & 0x1;
	}
	//set bit i in file to state
	void set(lengthtype i, bool state = false){
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