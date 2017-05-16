#!/bin/bash
echo "Compile or compile and run? (c/r)"
read r
if [ "$r" = "c" ]; then
	echo "Compiling ... "
	g++ -std=c++11 compress.cpp -o compress
else
	echo "Compiling ..."
	g++ -std=c++11 compress.cpp -o compress
	echo "Running ..."
	./compress
fi;

# Note that this will pipe the final exe into "compress"
# Notice the whitespace everywhere
# Change the -std=c++11 to something else should we need newer and newer features
