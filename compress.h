
#include <iostream>
//include only those libraries and files that are actually used in the header
//all else should be put into compress.cpp
//in case we build a class that handles i/o, we should put it into the header
//and then include all the libraries/headers that we need to.
typedef std::string String;

template<class T>
void out(T a) {
  std::cout<<a;
}

template<class T>
void outln(T a) {
  std::cout<<a<<'\n';
  //std::endl was not used because this "flushes" the stream
  //This reduces performance and optimization
}

template<class T>
void outlnend(T a) {
  std::cout<<a<<std::endl;
  //here it is used so that the programmer can flush and end the stream in case
  //the programmer is completely finished outputing things.
}
