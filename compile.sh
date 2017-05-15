#!/bin/bash
echo "Compile or compile and run? (c/r)"
read r
if [ "$r" = "c" ]; then
	echo "Compiling ... "
	g++ -std=c++11 compress.cpp
else
	echo "Compiling ..."
	g++ -std=c++11 compress.cpp
	echo "Running ..."
	./a.out
fi;

# Note that this will pipe the final exe into "a.out"
# Notice the whitespace everywhere
# Change the -std=c++11 to something else should we need newer and newer features
