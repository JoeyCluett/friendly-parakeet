#!/bin/bash

STD_OPTS="-std=c++11 -Wall -O3 -march=native"
INC_OPTS="-I./"

# generate object code for main.cpp
g++ -g -c -o main/main.o main/main.cpp $STD_OPTS $INC_OPTS

LINK_STRING="" # empty string to start

# generate linkage string
OBJ=( "core_6502" "core" )
for i in "${OBJ[@]}"
do
    LINK_STRING+=" ./core/obj/$i.o" # add every object file needed
done

# generate final executable for main.o
g++ -o main/main main/main.o $LINK_STRING $STD_OPTS
