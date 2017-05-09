#include "compress.h"


//room for the compression algorithm and other classes


int main() {
	File mp3File("sound.mp3");
	out("Name: "); outln(mp3File.name);
	out("Type: "); outln(mp3File.type);
	out("Size: "); outln(mp3File.length);
	outlnend(mp3File.accessBinaryStringAtIndex(1890));
}
