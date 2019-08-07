
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

COMMON = testVerifyHamiltonPath.c Graph.c
QUESTION_FILES = verifyHamiltonPath.c $(COMMON)
SOLUTION_FILES = solution/verifyHamiltonPath.c $(COMMON)

.PHONY: all
all: testVerifyHamiltonPath

testVerifyHamiltonPath: $(QUESTION_FILES)
	$(CC) $(CFLAGS) -o testVerifyHamiltonPath $(QUESTION_FILES)

solution: solution/verifyHamiltonPath.c $(SOLUTION_FILES)
	$(CC) $(CFLAGS) -o testVerifyHamiltonPath $(SOLUTION_FILES)

.PHONY: clean
clean:
	rm -f testVerifyHamiltonPath

