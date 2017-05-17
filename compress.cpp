#include "compress.h"
#include "cache.h"
//#include "dynamic_bitset.h"

//room for the compression algorithm and other classes


int main() {
	File mp3File("sound.mp3");
	outf("Name: ", mp3File.name);
	outf("Type: ", mp3File.type);
	outf("Size: * bytes", mp3File.length);
	/*File txtFile("Ideas.txt");
	outf("Name: *", txtFile.name);
	outf("Type: *", txtFile.type);
	outf("Size: * bytes", txtFile.length);
	*/
	/*
	for(long i=0;i<mp3File.binary.size();i++){
		out(mp3File.binary[i]);
	}
	outlnend("");
	return 0;
	*/
	bitstring b;
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	b.push_back(false);
	std::vector<bitstring> v = mp3File.getRepeatingBitstrings(b);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			out(v[i][j]);
		}
		outln("");
	}
	//*/
	//Compress c("Ideas.txt");
	
}
