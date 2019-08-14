
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Deletes  the  value  in the n'th position of the list and returns the
 * value that was deleted.
 * If  n  is 0, the value at the beginning of the list should be deleted
 * and returned.
 * If  n  is equal to N - 1 where N is the length of the list, the value
 * at the end of the list should be deleted and returned.
 * If  n  is  not between 0 and N - 1, this function should exit with an
 * an appropriate error message (not tested).
 *
 * Examples:
 *        input list      |  n  |  return value  |  resulting list
 * -----------------------+-----+----------------+------------------
 *  5 -> 2 -> 7 -> 1 -> X |  0  |       5        | 2 -> 7 -> 1 -> X
 *  5 -> 2 -> 7 -> 1 -> X |  1  |       2        | 5 -> 7 -> 1 -> X
 *  5 -> 2 -> 7 -> 1 -> X |  3  |       1        | 5 -> 2 -> 7 -> X
 *  4 -> X                |  0  |       4        | X
 */
int listDeleteNth(List l, int n) {
	// TODO
	return 0;
}

