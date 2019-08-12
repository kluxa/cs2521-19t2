
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

COMMON = testGetTour.c Graph.c Queue.c
QUESTION_FILES = $(COMMON) getTour.c
SOLUTION_FILES = $(COMMON) solution/getTour.c

.PHONY: all
all: testGetTour

testGetTour: $(QUESTION_FILES)
	$(CC) $(CFLAGS) -o testGetTour $(QUESTION_FILES)

.PHONY: solution
solution: $(SOLUTION_FILES)
	$(CC) $(CFLAGS) -o solution/testGetTour $(SOLUTION_FILES)

.PHONY: clean
clean:
	rm -f testGetTour solution/testGetTour

