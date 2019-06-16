#!/bin/bash

usage()
{
	echo "Usage: $0 [-s] <function name>"
	echo "The -s option compiles the solution rather than your code."
	exit 1
}

if [ $# -eq 0 -o $# -gt 2 ] || [ $# -eq 2 -a $1 != "-s" ]
then
	usage
fi

fname="$1"
directory="exercises/"
if [ $# -eq 2 ]
then
	fname="$2"
	directory="solutions/"
fi

if [ ! -e "exercises/$fname.c" ]
then
	echo "$0: no activity named '$fname'"
	exit 1
fi

upper="${fname^}"
gcc -Wall -Werror -std=gnu99 -g -o testList list.c "testDrivers/test$upper.c" "$directory/$fname.c"

