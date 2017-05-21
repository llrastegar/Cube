#include "hardcodegen.h"

//room for the compression algorithm and other classes


int main() {
	/*File mp3File("sound.mp3");
	outf("Name: ", mp3File.name);
	outf("Type: ", mp3File.type);
	outf("Size: * bytes", mp3File.length);*/
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
														outln(a);
														a[o] = '0';
													}
												}
												outln(a);
												a[n] = '0';
											}
										}
										outln(a);
										a[m] = '0';
									}
								}
								outln(a);
								a[l] = '0';
							}
						}
						outln(a);
						a[k] = '0';
					}
				}
				outln(a);
				a[j]='0';
			}
		}
		a[i]='0';
	}
}
