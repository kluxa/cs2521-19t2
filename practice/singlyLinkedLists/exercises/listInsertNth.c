
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Inserts a value into the n'th position in the list.
 * If n is 0, the new value is inserted at the beginning of the list.
 * If n is equal to the length of the list, the new value is inserted at
 * the end of the list.
 * Otherwise,  the  new value should be inserted somewhere in the middle
 * of the list, depending on the value of n.
 * If n is not between 0 and the length of the list, the function should
 * exit with an appropriate error message (not tested).
 *
 * Examples:
 *        input list      |  value  |  n  |       resulting list
 * -----------------------+---------+-----+----------------------------
 *  4 -> 6 -> 1 -> 8 -> X |    5    |  0  | 5 -> 4 -> 6 -> 1 -> 8 -> X
 *  4 -> 6 -> 1 -> 8 -> X |    5    |  2  | 4 -> 6 -> 5 -> 1 -> 8 -> X
 *  4 -> 6 -> 1 -> 8 -> X |    5    |  4  | 4 -> 6 -> 1 -> 8 -> 5 -> X
 *  1 -> X                |    8    |  0  | 8 -> 1 -> X
 *  1 -> X                |    4    |  1  | 1 -> 4 -> X
 *  X                     |    3    |  0  | 3 -> X
 */
void listInsertNth(List l, int value, int n) {
	// TODO
}

