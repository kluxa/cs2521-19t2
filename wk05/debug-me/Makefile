
CC = gcc
CFLAGS = -Wall -Werror -std=gnu99 -g

all: testStringList

testStringList: testStringList.c stringList.c
	$(CC) $(CFLAGS) -o testStringList testStringList.c stringList.c

.PHONY: clean
clean:
	rm -f testStringList
