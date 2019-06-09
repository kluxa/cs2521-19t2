
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Delete all values in the list that are an integer multiple of another
 * value in the list.
 *
 * Examples:
 *             input list           |       resulting list
 * ---------------------------------+-----------------------------
 *  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> X | 1 -> X
 *  2 -> 4 -> 8 -> 6 -> 3 -> X      | 2 -> 3 -> X
 *  5 -> 5 -> 3 -> 3 -> 7 -> 7 -> X | X
 *  1 -> 1 -> 8 -> 123 -> -42 -> X  | X
 *  0 -> X                          | 0 -> X
 *  1 -> X                          | 1 -> X
 *  1 -> 0 -> X                     | 1 -> X
 *  2 -> 3 -> 5 -> 7 -> 11 -> X     | 2 -> 3 -> 5 -> 7 -> 11 -> X
 *  X                               | X
 */
void listDeleteMultiples(List l) {
	(void) l;
}

