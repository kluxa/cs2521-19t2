
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

COMMON = testHasCycle.c Queue.c Stack.c
EXERCISE_FILES = $(COMMON) Graph.c
SOLUTION_FILES = $(COMMON) solution/Graph.c

.PHONY: all
all: testHasCycle

testHasCycle: $(EXERCISE_FILES)
	$(CC) $(CFLAGS) -o testHasCycle $(EXERCISE_FILES)

.PHONY: solution
solution: $(SOLUTION_FILES)
	$(CC) $(CFLAGS) -o solution/testHasCycle $(SOLUTION_FILES)

.PHONY: clean
clean:
	rm -f testHasCycle solution/testHasCycle

