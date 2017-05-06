#include "compress.h"
#include <fstream>
#include <vector>
#include <bitset>

int main() {
	std::vector<String> lines;
	std::ifstream myfile;
	String line;
	myfile.open ("tfile.txt", std::ios::binary);
	while (getline (myfile, line) ) {
		lines.push_back(line);
		outln(line);
	}
	for (std::size_t i = 0; i<line.size(); ++i) {
		outln(std::bitset<8>(line.c_str()[i]));
	}
	myfile.close();
}
