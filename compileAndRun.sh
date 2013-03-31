#!/bin/bash
#
# Compile a g++ program and run it.
# This script supports programms that require the GMP library.
# Somehow that library does not work in my IDE.
#
echo "Compiling $1.cpp ...";
g++ -std=c++0x -lgmpxx -lgmp -o $1 $1.cpp

echo "Runing ./$1 ... ";
echo "--------------";

./$1

echo "";
echo "--------------";
