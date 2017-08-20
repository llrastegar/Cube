/*
	A place to test other files and classes
*/
#include "file2.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	
	File2 f("Ideas.txt");
	//cout << f.bytes << endl;
	for(int i=0; i < f.size(); i++)
		cout << f[i];
	cout << endl;
	
	f.set(f.size() - 1, true);

	//cout << f.bytes << endl;
	for(int i=0; i < f.size(); i++)
		cout << f[i];
	cout << endl;
	return 0;
}