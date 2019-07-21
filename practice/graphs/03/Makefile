
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g
SRC_FILES = testVerifyHamiltonPath.c verifyHamiltonPath.c Graph.c

.PHONY: all
all: testVerifyHamiltonPath

testVerifyHamiltonPath: $(SRC_FILES)
	$(CC) $(CFLAGS) -o testVerifyHamiltonPath $(SRC_FILES)

.PHONY: clean
clean:
	rm -f testVerifyHamiltonPath

