
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g
SRC_FILES = testGetTour.c getTour.c Graph.c Queue.c

.PHONY: all
all: testGetTour

testGetTour: $(SRC_FILES)
	$(CC) $(CFLAGS) -o testGetTour $(SRC_FILES)

.PHONY: clean
clean:
	rm -f testGetTour

