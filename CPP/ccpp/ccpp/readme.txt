1. compile c++ code to shared dynamic library
g++ -shared -o libccpp.so c.cpp stuclass.cpp

2. compiling c code by g++.
g++ -o helloc helloc.c ./libccpp.so

