#include "file.h"
#pragma once
/*

This is an implementation of the cache that we could use to better keep
all of the strings we are looking for in a system that we could easily
adapt to extract relevant information for the scoring mechanism.
An 8 bit string has 256 different possible combinations
The sum of all combinations less than 256 is 255. Therefore, we could
introduce one 8 bit string to represent the least common
8 bit string, and compress all other 8 bit strings into 7, 6, 5 ... or 1
bit strings.

*/

class Cache {
public:
	std::vector<bitstring> eightbitcombinations;
	std::vector<int> numrepeats;
	std::vector<bitstring> nbitkeys;
	File t;
	Cache(File a) : t(a) {}
	Cache() {}
	
	bool areEqual(bitstring a, bitstring b) {
		if (a.size()!=b.size()) return false;
		for (int i = 0; i<a.size(); i++) {
			if (a[i]!=b[i]) return false;
		}
		return true;
	}
	unsigned long getNumReps(File t, bitstring find) {
		int count = 0;
		for (int i = 0; i<t.length; i+=find.size()) {
			if (areEqual(t.substr(i, i+9), find)) count++;
		}
		return count;
	}
	bool contains(File a, bitstring sub) {
		if (a.length<sub.size()) return false;
		for (int i = 0; i<a.length; i++) {
			if (a[i]==sub[i] && a[i+1]==sub[i+1]) {
				if (areEqual(a.substr(i,i+sub.size()), sub)) return true;
			}
		}
		return false;
	}
};
