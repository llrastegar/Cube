//#include "hardcodegen.h"
#include "file.h"
#include <math.h>
//room for the compression algorithm and other classes
const float base = 16.01202676f;

int main() {
	std::cout.precision(25);
	//10 bit string
	bitstring b;
	b.push_back(true);
	b.push_back(true);
	b.push_back(true);
	b.push_back(true);
	b.push_back(true);

	b.push_back(true);
	b.push_back(true);
	b.push_back(true);
	b.push_back(true);
	b.push_back(true);
	//convert b to float
	float a = b[0];
	for(int i = 1; i < 10; i++){
		a += b[i] * pow(2, -i);
	}
	outln(a);
	//raise 16.01202676 to the power of the bin of the string
	float result = pow(base, a);
	outln(result);
	//rounding might be tricky
	std::bitset<8> bin(round(result));
	outln(bin);
	//gets 8 bit string
	//do that for the entire file



	/*File mp3File;
	mp3File.open("sound.mp3");
	outf("Name: *\n", mp3File.name);
	outf("Type: *\n", mp3File.type);
	outf("Size: * bytes\n", mp3File.binary.size() / 8);
	outln();
	/
	File txtFile;
	txtFile.open("Ideas.txt");
	//txtFile.stats();
	int value = 0;
	for(long long i = 0; i < txtFile.binary.size(); i += 16){
		for(int bit)
		
	}
	*/
}
