/*
	A place to test other files and classes
*/
#include "file2.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	
	File2 f("Ideas.txt");
	
	for(int i=0; i < f.size(); i++)
		cout << f[i];
	//show some space between outputs
	cout << endl;
	cout << endl;
	//resize file, adding 1000 additional bits
	//f.resize(f.size() - 8);

	for(int i=0; i < f.size(); i++)
		cout << f[i];
	cout << endl;

	f.close("test.txt");
	return 0;
}