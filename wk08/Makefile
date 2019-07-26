
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

all: testList badFib goodFib

testList: testList.c list.c
	$(CC) $(CFLAGS) -o testList testList.c list.c

badFib: badFib.c
	$(CC) $(CFLAGS) -o badFib badFib.c

goodFib: goodFib.c
	$(CC) $(CFLAGS) -o goodFib goodFib.c

.PHONY: clean
clean:
	rm -f testList badFib goodFib
