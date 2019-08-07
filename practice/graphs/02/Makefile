
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

COMMON = testGetTour.c Graph.c Queue.c
QUESTION_FILES = getTour.c $(COMMON)
SOLUTION_FILES = solution/getTour.c $(COMMON)

.PHONY: all
all: testGetTour

testGetTour: $(QUESTION_FILES)
	$(CC) $(CFLAGS) -o testGetTour $(QUESTION_FILES)

solution: $(SOLUTION_FILES)
	$(CC) $(CFLAGS) -o solution/testGetTour $(SOLUTION_FILES)

.PHONY: clean
clean:
	rm -f testGetTour solution/testGetTour

