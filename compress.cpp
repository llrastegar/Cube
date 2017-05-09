#include "compress.h"


//room for the compression algorithm and other classes


int main() {
	File mp3File("Ideas.txt");
	out("Name: "); outln(mp3File.name);
	out("Type: "); outln(mp3File.type);
	out("Size: "); outln(mp3File.length);
<<<<<<< HEAD
	for(int i=0;i<5;i++)
		outln(mp3File[i].to_string());
	//outlnend(mp3File.accessBinaryStringAtIndex(1890));
=======
	outlnend(mp3File.accessBinaryStringAtIndex(1890));
	File txtFile("Ideas.txt");
	out("Name: "); outln(txtFile.name);
	out("Type: "); outln(txtFile.type);
	out("Size: "); outln(txtFile.length);
	outlnend(txtFile.accessBinaryStringAtIndex(99));
>>>>>>> 310b46c25145f41953100c0693d040c32f1af3d1
}
