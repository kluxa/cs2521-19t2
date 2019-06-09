
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Deletes  values  from  the list that do not preserve ascending order,
 * starting from the beginning of the list.
 *
 * Examples:
 *             input list           |     resulting list
 * ---------------------------------+-----------------------
 *  2 -> 4 -> 5 -> 8 -> X           | 2 -> 4 -> 5 -> 8 -> X
 *  5 -> 7 -> 3 -> 7 -> 8 -> 2 -> X | 5 -> 7 -> 7 -> 8 -> X
 *  5 -> 2 -> 1 -> 8 -> X           | 5 -> 8 -> X
 *  5 -> 2 -> 4 -> X                | 5 -> X
 *  X                               | X
 *  3 -> 1 -> 6 -> 4 -> 8 -> 7 -> X | 3 -> 6 -> 8 -> X
 */
void listPreserveAscending(List l) {
	(void) l;
}

