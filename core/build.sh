#!/bin/bash

STD_OPTS="-std=c++11 -march=native -O3"

g++ -c -o obj/core_6502.o core_6502.cpp $STD_OPTS
g++ -c -o obj/core.o core.cpp $STD_OPTS
