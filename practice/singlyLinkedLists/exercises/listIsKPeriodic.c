
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * Returns true if the given list is k-periodic,  and false otherwise. A
 * list is k-periodic if the list repeats itself every k-values. If k is
 * greater  than  or equal to the list length, the list is automatically
 * k-periodic. You can assume k is positive.
 *
 * Examples:
 *              input list               |    k    |   return value
 * --------------------------------------+---------+-------------------
 *  2 -> 2 -> 2 -> 2 -> 2 -> 2 -> 2 -> X |    1    |       true
 *  2 -> 2 -> 2 -> 2 -> 2 -> 2 -> 2 -> X |    5    |       true
 *  2 -> 2 -> 2 -> 2 -> 2 -> 2 -> 2 -> X |    9    |       true
 *  2 -> 3 -> 4 -> 2 -> 3 -> 4 -> 2 -> X |    3    |       true
 *  2 -> 3 -> 4 -> 2 -> 3 -> 4 -> 2 -> X |    2    |       false
 *  2 -> 3 -> 4 -> 2 -> 3 -> 6 -> 2 -> X |    3    |       false
 *  2 -> 6 -> 2 -> 6 -> 2 -> 6 -> 2 -> X |    2    |       true
 *  2 -> 6 -> 2 -> 6 -> 2 -> 6 -> 2 -> X |    3    |       false
 *  2 -> 6 -> 2 -> 6 -> 2 -> 6 -> 2 -> X |    4    |       true
 *  2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> X |    6    |       false
 *  2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> X |    7    |       true
 */
bool listIsKPeriodic(List l, int k) {
	(void) l;
	(void) k;
	return false;
}

