#include "file.h"
#pragma once
/*

This is an implementation of the cache that we could use to better keep
all of the strings we are looking for in a system that we could easily
adapt to extract relevant information for the scoring mechanism.
You can use an 11 bit key to encode 16 bits of information
You do this by assigning an 8 bit key to two 8 bit strings
These strings could be identical, or the reverse pair of another
pair, and therefore get the same key. A single key also needs to
represent some other combination or else there will not be enough
keys to go around. The three things described above are simple
boolean values assigned to each key which is hardcoded in both
the compression and decompression software. As a result, you need
keylength + 3 bits to encode information, for a total of 11 bits
per 16. Obviously, you can compound this over and over again until
you've compressed it n times into (11/16)^n of its original size.
Note that this fraction becomes tiny very quickly.

*/

bool checkLength(bitstring a, bitstring b) {
	return a.size()==b.size();
}

bool compareBitstrings(bitstring one, bitstring two) {
	if (!checkLength(one, two)) return false;
	for (int i = 0; i<one.size(); i++) {
		if (one[i]!=two[i]) return false;
	}
	return true;
}

class EntryPair {
public:
	bitstring a;
	bitstring b;
	EntryPair() {}
	EntryPair(bitstring ar, bitstring br) {
		if (ar.size()==br.size()) {
			for (int i = 0; i<ar.size(); i++) {
				a.push_back(ar[i]);
				b.push_back(br[i]);
			}
		} else {
			outln("Warning! Bitstrings not the same length!");
		}
	}
	bool operator == (const EntryPair &com) {
		return compareBitstrings(a, com.a) && compareBitstrings(b, com.b);
	}
	bool operator |= (const EntryPair &com) {
		return *this==com && (compareBitstrings(a, com.b) && compareBitstrings(b, com.a));
	}
	bitstring getFullBitstring(bool ord=true, bool id=false) {
		bitstring resultant;
		for (int i = 0; i<a.size(); i++) {
			resultant.push_back(a[i]);
		}
		for (int i = 0; i<b.size(); i++) {
			resultant.push_back(b[i]);
		}
		resultant.push_back(ord); resultant.push_back(id);
		return resultant;
	}
};

struct Key {
	bitstring key;
	EntryPair ab;
	EntryPair cd;
	Key() {}
	Key(bitstring k, EntryPair a, EntryPair c) : key(k), ab(a), cd(c) {}
	bitstring getFullBitstring(bool which=true) {
		bitstring resultant, insert;
		if (which)
			insert = ab.getFullBitstring();
		else
			insert = cd.getFullBitstring();
		resultant.insert(resultant.end(), insert.begin(), insert.end());
		resultant.push_back(which);
		return resultant;
	}
};



