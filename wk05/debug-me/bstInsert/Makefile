
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

all: testBst

testBst: testBst.c BSTree.c
	$(CC) $(CFLAGS) -o testBst testBst.c BSTree.c

.PHONY: clean
clean:
	rm -f testBst
