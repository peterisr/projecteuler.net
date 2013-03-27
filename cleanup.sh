#!/bin/sh
find -name *.o -delete
if [ -f projecteuler_test ]; then 
	rm projecteuler_test
fi;
