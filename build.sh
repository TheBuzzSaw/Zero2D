#!/bin/bash
cd ./source/
mkdir build
cd ./build
cmake ../
make 
cd ../../
./source/build/zero2d
