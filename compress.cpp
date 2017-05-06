#include "compress.h"
#include <fstream> //file io
#include <vector>
#include <bitset> //string->binary, probably has other functions

int main() {
	std::vector<String> lines;
	std::ifstream myfile; //do not declare as "ofstream" when only reading
	String line;
	myfile.open ("tfile.txt", std::ios::binary); //std::ios::binary is optional
	while (getline (myfile, line) ) {
		lines.push_back(line);
		outln(line);
	}
	for (std::size_t i = 0; i<line.size(); ++i) {
		//size_t is very similar to an int
		//stackoverflow.com claims that one should prefer ++i over i++
		//as long as that ++i/i++ statement is used at the top of a for loop,
		//just don't worry about it
		outln(std::bitset<8>(line.[i])); //convert every character to binary
		//note that you could write line.c_str()[i] instead of the more condensed version above
	}
	myfile.close();
	//always remember to do this!
}
