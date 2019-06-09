
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Deletes  the  largest  value from the list and returns the value that
 * was deleted.
 * If  the  list  is empty, the function should exit with an appropriate
 * error message (not tested).
 * If  the  largest  value  occurs more than once, delete only the first
 * instance.
 *
 * Examples:
 *        input list      | expected return value |  resulting list
 * -----------------------+-----------------------+------------------
 *  3 -> 7 -> 2 -> 7 -> X |           7           | 3 -> 2 -> 7 -> X
 *  4 -> 5 -> 7 -> 1 -> X |           7           | 4 -> 5 -> 1 -> X
 *  8 -> 4 -> 1 -> X      |           8           | 4 -> 1 -> X
 *  5 -> X                |           5           | X
 */
int listDeleteLargest(List l) {
	(void) l; // This is to prevent 'unused variables' errors when
	          // compiling. Delete this after you add code.
	
	return 0;
}

