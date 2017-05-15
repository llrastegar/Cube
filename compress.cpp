#include "Compress.h"
#include "dynamic_bitset.h"

//room for the compression algorithm and other classes


int main() {
	/*File mp3File("sound.mp3");
	outf("Name: ", mp3File.name);
	outf("Type: ", mp3File.type);
	outf("Size: * bytes", mp3File.length);

	File txtFile("Ideas.txt");
	outf("Name: *", txtFile.name);
	outf("Type: *", txtFile.type);
	outf("Size: * bytes", txtFile.length);
	txtFile.print();*/
	//Compress c("Ideas.txt");
	dynamic_bitset b;
	outln(b.size());
	b.set(5, true);
	outln(b.size());
	b.remove(5);
	outln(b.size());
}
