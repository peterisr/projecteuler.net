#!/bin/sh
find -name *.o -delete
find . -type f | xargs file | grep "ELF.*executable" | awk -F: '{print $1}' | xargs rm -v
if [ -f projecteuler_test ]; then 
	rm projecteuler_test
fi;
