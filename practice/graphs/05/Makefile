
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

COMMON = testGetDistance.c Graph.c Queue.c
EXERCISE_FILES = $(COMMON) getDistance.c
SOLUTION_FILES = $(COMMON) solution/getDistance.c

.PHONY: all
all: testGetDistance

testGetDistance: $(EXERCISE_FILES)
	$(CC) $(CFLAGS) -o testGetDistance $(EXERCISE_FILES)

.PHONY: solution
solution: $(SOLUTION_FILES)
	$(CC) $(CFLAGS) -o solution/testGetDistance $(SOLUTION_FILES)

.PHONY: clean
clean:
	rm -f testGetDistance solution/testGetDistance

