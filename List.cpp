
#include <iostream>
#include <stdio.h>

template<class T>
void out(T a) { std::cout<<a; }

template<class T>
void outln(T a) {std::cout<<a<<"\n";}

template<class T> class List {
public:
	T * fullList;
	int size;
	List<T>() :size(0) {}
	List<T>(const int s) : size(s) {
		fullList = new T[size];
	}
	T operator [] (const int &index) {
		return fullList[index];
	}
	void operator += (T a) {
		T *copyList = new T[size];
		memcpy(copyList, fullList, sizeof(T)*size);
		size++;
		fullList = new T[size];
		memcpy(fullList, copyList, sizeof(T)*size);
		fullList[size] = a;
	}
};

int main() {
	List<int> vector (3);
	outln(vector[0]);
	vector+=3;
	outln(vector[3]);
}
