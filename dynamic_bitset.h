#include <vector>
#include "debug_utils.h"
class dynamic_bitset
{
private:
	std::vector<bool> bits;
public:
	dynamic_bitset(){}
	long long size(){
		return bits.size();
	}
	bool operator[](unsigned long long i){
		if(i<bits.size()){
			return bits[i];
		}
		return false;
	}
	void set(unsigned long long i, bool bit=false){
		if(i >= bits.size()){
			while(bits.size() < i+1){
				bits.push_back(false);
			}
		}
		bits[i] = bit;
	}
	void remove(unsigned long long i){
		if(i>=bits.size()){
			return;
		}
		bits.erase(bits.begin()+i);
	}
	
};