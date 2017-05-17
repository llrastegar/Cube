#include "file.h"
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
	unsigned long score;
	unsigned long phase;
	unsigned long length;
	Entry() {}
	Entry(bitstring string, int p=0) : binary(string), phase(p), length(string.size()) {}
	int calculateRelativeScore() { return 0; } //use the calculate score function described
	//in Ideas.txt. If you find a problem, bring it up and fix it
};



class Cache {
public:
	std::vector<Entry> entries;
	unsigned long length;
	Cache() {}
	Cache(std::vector<Entry> e) : entries(e), length(e[0].length) {} //assume that all entries
	//have the same length, eventually guard for the possibility that this isn't true
	Entry calculateTotalScoreForEntries() { return 0; } //find the max score of the entries
	//and return a COPY of that entry
};
