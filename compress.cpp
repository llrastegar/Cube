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
	//txtFile.extract();

	txtFile.stats();
	txtFile.extract();
	txtFile.stats();
	
	txtFile.close();
	return 0;

	txtFile.compress();
	txtFile.stats();
	//txtFile.print();
	//txtFile.close();
	/*
	mapTokeymap(keymap);
	String a = "00000000";
	outln(a);
	for (int i = 0; i<8; i++) {
		a[i] = '1';
		for (int j = 0; j<8; j++) {
			if (i!=j) {
				a[j]='1';
				for (int k = 0; k<8; k++) {
					if (k!=j && i!=k) {
						a[k] = '1';
						for (int l = 0; l<8; l++) {
							if (l!=k && l!=j && l!=i) {
								a[l] = '1';
								for (int m = 0; m<8; m++) {
									if (m!=k && m!=j && m!=i && m!=l) {
										a[m] = '1';
										for (int n = 0; n<8; n++) {
											if (n!=k && n!=j && n!=i && n!=l && n!=m) {
												a[n] = '1';
												for (int o = 0; o<8; o++) {
													if (o!=k && o!=j && o!=i && o!=l && o!=m && o!=n) {
														a[o] = '1';
														outlnend(a);
														a[o] = '0';
													}
												}
												outlnend(a);
												a[n] = '0';
											}
										}
										outlnend(a);
										a[m] = '0';
									}
								}
								outlnend(a);
								a[l] = '0';
							}
						}
						outlnend(a);
						a[k] = '0';
					}
				}
				outlnend(a);
				a[j]='0';
			}
		}
		a[i]='0';
	}
	*/
}
