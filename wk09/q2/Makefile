
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g
SRC_FILES = testIsStableSort.c helpers.c isStableSort.c Item.c

.PHONY: all
all: testIsStableSort

testIsStableSort: $(SRC_FILES)
	$(CC) $(CFLAGS) -o testIsStableSort $(SRC_FILES)
