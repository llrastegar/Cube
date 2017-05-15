#include <iostream>
#pragma once //only allows one include
//using "T" is not necessary, you could use "E" just as well
template<class T>
void out(T a) {
  std::cout << a;
}
template<class T>
void outf(std::string s, T a) { //formated out, replace first '*' with a else just put a after s
  if((signed)s.find("*") >= 0)
      std::cout << s.substr(0, s.find("*")) << a << s.substr(s.find("*") + 1) << '\n';
    else
      std::cout << s << a << "\n";
}

template<class T>
void outln(T a) {
  std::cout << a <<'\n';
  //std::endl was not used because this "flushes" the stream
  //This reduces performance and optimization
}

template<class T>
void outlnend(T a) {
  std::cout << a << std::endl;
  //here it is used so that the programmer can flush and end the stream in case
  //the programmer is completely finished outputting things.
}