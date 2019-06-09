#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Usage: $0 <function name>"
	exit 1
fi

fname="$1"
upper="${fname^}"
gcc -Wall -Werror -std=gnu99 -o testList list.c "testDrivers/test$upper.c" "exercises/$fname.c"

