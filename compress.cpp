#include "compress.h"
#include "cache.h"
//#include "dynamic_bitset.h"

//room for the compression algorithm and other classes


int main() {
	/*
	File mp3File("sound.mp3");
	outf("Name: *\n", mp3File.name);
	//outf("Type: *\n", mp3File.type);
	//outf("Size: * bytes\n", mp3File.length);
	//*/

	//*
	File txtFile("Ideas.txt");
	outf("Name: *\n", txtFile.name);
	outf("Type: *\n", txtFile.type);
	outf("Size: * bytes\n", txtFile.length);
	//*/

	/*
	for(long i=0;i<mp3File.binary.size();i++){
		out(mp3File.binary[i]);
	}
	outlnend("");
	return 0;
	//*/
	txtFile.close();
	/*
	bitstring seed; //the seed bitstring
	seed.push_back(true);
	seed.push_back(true);
	seed.push_back(true);
	seed.push_back(true);
	//*/
	/*/
	outlnend("Finding repeating bitstrings");
	std::vector<bitstring> v = mp3File.getRepeatingBitstrings(seed, 100);
	//*/
	
}
