#include "compress.h"
#include <fstream> //file io
#include <vector>
#include <bitset> //string->binary, probably has other functions

const int CHAR_TO_INT = 48;

int filesizeInBytes(const char* filename) {
	std::ifstream in(filename, std::ios::binary | std::ios::ate);
	return in.tellg();
}

int main() {
	std::vector<String> lines;
	String fullbitset;
	std::ifstream myfile; //do not declare as "ofstream" when only reading
	String line;
	std::vector<int>bitses; //could be booleans later
	myfile.open ("ideas.txt", std::ios::binary); //std::ios::binary is optional
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
			out(a); out(" ");
			out((char)std::bitset<8>(a).to_ulong()); out(" "); //this is confusing, but
			//all it's doing is converting the bitset to an unsigned long, then to a character
			//which is what strings are made out of!
			fullbitset += a.to_string();
		}
		outln("");
		outln(fullbitset);
		for (int i = 0; i<fullbitset.size(); ++i) {
			bitses.push_back((int)(fullbitset[i]-CHAR_TO_INT));
		}
	}
	outln(" "); out("filesize: "); outln(filesizeInBytes("tfile.txt"));
	myfile.close();
	//always remember to do this!
	outln("------------------------------");
	outln("");

	std::streampos size;
	char * memblock;

	std::ifstream file ("sound.mp3", std::ios::in|std::ios::binary|std::ios::ate);
	//ios::ate puts the reader at the end of the file
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, std::ios::beg);
		file.read (memblock, size);
		file.close();

		outln("the entire file content is in memory");
		for (int i = 0; i<size; i++) {
			outln(((std::bitset<8>)memblock[i]).to_ulong());
			//outln(((char)memblock[i]));
		}
		delete[] memblock;
	}
	else outln("Unable to open file");
}
