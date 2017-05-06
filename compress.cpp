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
		for (std::size_t i = 0; i<line.size(); ++i) {
			//size_t is very similar to an int
			//stackoverflow.com claims that one should prefer ++i over i++
			//as long as that ++i/i++ statement is used at the top of a for loop,
			//just don't worry about it
			std::bitset<8> a = std::bitset<8>(line[i]); //convert every character to binary, save it in a
			//note that you could write line.c_str()[i] instead of the more condensed version above
			out("bits "); outln(a);
			out("string "); outln((char)std::bitset<8>(a).to_ulong()); //this is confusing, but
			//all it's doing is converting the bitset to an unsigned long, then to a character
			//which is what strings are made out of!
		}
	}
	
	myfile.close();
	//always remember to do this!
}
