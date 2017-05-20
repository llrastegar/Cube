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

bool compareBitstrings(bitstring one, bitstring two) {
	if (one.size()!=two.size()) return false;
	for (int i = 0; i<one.size(); i++) {
		if (one[i]!=two[i]) return false;
	}
	return true;
}

class EntryPair {
public:
	bitstring a;
	bitstring b;
	bool operator == (const EntryPair &com) {
		return compareBitstrings(a, com.a) && compareBitstrings(b, com.b);
	}
	bool operator |= (const EntryPair &com) {
		return (compareBitstrings(a, com.a) && compareBitstrings(b, com.b)) || (compareBitstrings(a, com.b) && compareBitstrings(b, com.a));
	}
	bitstring getFullBitstring(bool ord=true, bool id=false) {
		bitstring resultant;
		resultant.push_back(ord); resultant.push_back(id);
		for (int i = 0; i<a.size(); i++) {
			resultant.push_back(a[i]);
		}
		for (int i = 0; i<b.size(); i++) {
			resultant.push_back(b[i]);
		}
		return resultant;
	}
};

struct Key {
	bitstring key;
	EntryPair ab;
	EntryPair cd;
	bool first_second;
	Key() {}
	Key(bitstring k, EntryPair a, EntryPair c) : key(k), ab(a), cd(c) {}
};



