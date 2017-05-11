#include "compress.h"


//room for the compression algorithm and other classes


int main() {
	std::bitset<8> id('a');
	boost::dynamic_bitset<> value(16);
	key k(id, value); //the key class
	k.print();
	File mp3File("sound.mp3");
	out("Name: "); outln(mp3File.name);
	out("Type: "); outln(mp3File.type);
	out("Size: "); outln(mp3File.length);
	outlnend(mp3File[1]);
	//mp3File.compress();
	File txtFile("Ideas.txt");
	out("Name: "); outln(txtFile.name);
	out("Type: "); outln(txtFile.type);
	out("Size: "); outln(txtFile.length);
	outlnend(txtFile[-2]); //-1 should be last char in file
	//txtFile.compress();
}
