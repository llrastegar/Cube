#include "compress.h"


//room for the compression algorithm and other classes


int main() {
	File mp3File("sound.mp3");
	outf("Name: ", mp3File.name);
	outf("Type: ", mp3File.type);
	outf("Size: * bytes", mp3File.length);

	File txtFile("Ideas.txt");
	outf("Name: *", txtFile.name);
	outf("Type: *", txtFile.type);
	outf("Size: * bytes", txtFile.length);
	txtFile.print();

}
