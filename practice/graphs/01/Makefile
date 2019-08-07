
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

.PHONY: all
all: testGraph testGraphImproved

testGraph: testGraph.c Graph.c
	$(CC) $(CFLAGS) -o testGraph testGraph.c Graph.c

testGraphImproved: testGraph.c GraphImproved.c
	$(CC) $(CFLAGS) -o testGraphImproved testGraph.c GraphImproved.c

solution: testGraph.c solution/GraphImproved.c
	$(CC) $(CFLAGS) -o testGraphImproved testGraph.c solution/GraphImproved.c

.PHONY: clean
clean:
	rm -f testGraph testGraphImproved

