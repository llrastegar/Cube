//#include "hardcodegen.h"
#include "file.h"
//room for the compression algorithm and other classes


int main() {
	/*File mp3File;
	mp3File.open("sound.mp3");
	outf("Name: *\n", mp3File.name);
	outf("Type: *\n", mp3File.type);
	outf("Size: * bytes\n", mp3File.binary.size() / 8);
	outln();
	*/
	File txtFile;
	txtFile.open("Ideas.txt.compress");
	txtFile.stats();
	txtFile.extract();
	txtFile.stats();
	txtFile.close();
}
