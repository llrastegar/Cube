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
