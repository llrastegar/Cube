#!/bin/bash

check_for_compile_success() {
	if g++ -std=c++11 compress.cpp -o a.out; then 
		echo "Success";
	else 
		echo "Failure"; 
	fi
}

echo "Compile or compile and run? (c/r)"
read r
if [ "$r" = "c" ]; then
	echo "Compiling ... "
    check_for_compile_success
else
	echo "Compiling ..."
	check_for_compile_success
	echo "Running ..."
	./compress
fi;

# Note that this will pipe the final exe into "compress"
# Notice the whitespace everywhere
# Change the -std=c++11 to something else should we need newer and newer features
