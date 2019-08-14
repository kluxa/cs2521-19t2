
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Removes  the  second  instance of the duplicate in the list (if there
 * is  one),  and returns the value that was deleted, or NO_DUPLICATE if
 * there  was  no  duplicate.  You  can assume that there is at most one
 * duplicate value.
 *
 * Examples:
 *       input list       |  return value  |    resulting list
 * -----------------------+----------------------------------------
 *  2 -> 4 -> 6 -> 4 -> X |       4        | 2 -> 4 -> 6 -> X
 *  4 -> 5 -> 6 -> 4 -> X |       4        | 4 -> 5 -> 6 -> X
 *  6 -> 6 -> 1 -> 8 -> X |       6        | 6 -> 1 -> 8 -> X
 *  1 -> 2 -> 3 -> 4 -> X |  NO_DUPLICATE  | 1 -> 2 -> 3 -> 4 -> X
 *  4 -> X                |  NO_DUPLICATE  | 4 -> X
 *  X                     |  NO_DUPLICATE  | X
 */
int listRemoveDuplicate(List l) {
	// TODO
	return NO_DUPLICATE;
}

