#include "file.h"
#pragma once
/*

This is an implementation of the cache that we could use to better keep
all of the strings we are looking for in a system that we could easily
adapt to extract relevant information for the scoring mechanism.
The cache consists of two parts: a collection of entries, where
an entry is a (bit string, score, and phase). Several caches may
be instantiated with different length of bitstrings
One would look over to the cache to calculate the score

*/

class Entry {
public:
	bitstring binary;
	unsigned long length;
	Entry() {}
	Entry(bitstring string) : binary(string), length(string.size()) {}
	bool operator==(const Entry &a) {
		if (a.length!=length) return false;
		for (int i = 0; i<length; i++) {
			if (a.binary[i]!=binary[i]) return false;
		}
		return true;
	}
};
struct EntryPair {
	bool identical; //this means the pairs themselves are identical
	Entry key, two;
	unsigned long length;
	EntryPair() {}
	EntryPair(Entry o, Entry t) : key(o), two(t), length(o.length) {
		if (o==t) identical = true;
		else identical = false;
	}
	bool isReverseOf(EntryPair a) {
		//not reverse bits, reverse order of being saved!
		if (a.key == two && a.two == key) return true;
		return false; //this means the two pairs being considered are exact copies of each other

	}
	bool operator==(EntryPair &a) {
		//no idea why a is not declared const--compiler gives an error
		if (a.key == key && a.two == two) return true;
		return false;
	}
};
class Cache {
public:
	unsigned long length;
	unsigned long keylength;
	std::vector<EntryPair> entries;
	Cache() : length(0) {}
	Cache(std::vector<EntryPair> e) : length(e[0].length) {
		keylength = length+2; // b1, b2, key
	}
	void addPair(EntryPair e) {
		entries.push_back(e); length++; keylength++;
	}
	bool contains(EntryPair e) {
		for (int i = 0; i<entries.size(); i++) {
			if (e==entries[i]) return true;
		}
		return false;
	}
	bitstring compress() {
		bitstring resultant;
		//first bit tells us whether the bits are equal
		//second bit tells us which of the two strings are being used as a key
		//then fill up the bitstring with the appropriate amount of repeats
		//in their correct indices.
		return resultant;
	}
};
