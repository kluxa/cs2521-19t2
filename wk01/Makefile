
CC = gcc
CFLAGS = -Wall -Werror -std=c11
BINS = fib1 fib2 helloWorld readLine swap sumList

.PHONY: all
all: $(BINS)

fib1: fib1.c
fib2: fib2.c
helloWorld: helloWorld.c
readLine: readLine.c
swap: swap.c
sumList: sumList.c

.PHONY: clean
clean:
	rm -f $(BINS)

# What does .PHONY mean?
# https://stackoverflow.com/questions/2145590/what-is-the-purpose-of-phony-in-a-makefile

