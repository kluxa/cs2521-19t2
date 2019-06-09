// Header file for singly linked list exercises

#ifndef LIST_H
#define LIST_H

#include <stdbool.h> // Provides the constants 'true' and 'false'

typedef struct node *Node;
struct node {
	int value;
	Node next;
};

typedef struct list *List;
struct list {
	Node head;
};

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
int listDeleteLargest(List l);

/**
 * Inserts a value into the n'th position in the list.
 * If n is 0, the new value is inserted at the beginning of the list.
 * If n is equal to the length of the list, the new value is inserted at
 * the end of the list.
 * Otherwise,  the  new value should be inserted somewhere in the middle
 * of the list, depending on the value of n.
 * You can assume n is between 0 and N (inclusive).
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
void listInsertNth(List l, int value, int n);

/**
 * Deletes  the  value  in the n'th position of the list and returns the
 * value that was deleted.
 * If  n  is 0, the value at the beginning of the list should be deleted
 * and returned.
 * If  n  is equal to N - 1 where N is the length of the list, the value
 * at the end of the list should be deleted and returned.
 * You  can  assume n is between 0 and N - 1 (inclusive). You can assume
 * the list is non-empty.
 *
 * Examples:
 *        input list      |  n  |  return value  |  resulting list
 * -----------------------+-----+----------------+------------------
 *  5 -> 2 -> 7 -> 1 -> X |  0  |       5        | 2 -> 7 -> 1 -> X
 *  5 -> 2 -> 7 -> 1 -> X |  1  |       2        | 5 -> 7 -> 1 -> X
 *  5 -> 2 -> 7 -> 1 -> X |  3  |       1        | 5 -> 2 -> 7 -> X
 *  4 -> X                |  0  |       4        | X
 */
int listDeleteNth(List l, int n);

/**
 * Returns  true if the list is in ascending order, and false otherwise.
 * For  example, 2 -> 3 -> 3 -> 5 -> X is ascending, 2 -> 5 -> 3 -> X is
 * not. An empty list is considered to be ascending.
 */
bool listIsAscending(List l);

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
void listPreserveAscending(List l);

/**
 * Removes  the  second  instance of the duplicate in the list (if there
 * is  one),  and returns the value that was deleted, or NO_DUPLICATE if
 * there was no duplicate. You can assume that there is at most one
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
#define NO_DUPLICATE -42
int listRemoveDuplicate(List l);

/**
 * Reverses the given list.
 */
void listReverse(List l);

/**
 * Appends  the second list to the end of the first list. The first list
 * should end up with the values from both of the original lists and the
 * second list should end up empty.
 *
 * Examples:
 *      input l1     |     input l2     |         resulting l1       | resulting l2
 * ------------------+------------------+----------------------------+--------------
 *  4 -> 7 -> 1 -> X | 3 -> 2 -> X      | 4 -> 7 -> 1 -> 3 -> 2 -> X |       X
 *  2 -> 6 -> X      | X                | 2 -> 6 -> X                |       X
 *  X                | 2 -> 8 -> 9 -> X | 2 -> 8 -> 9 -> X           |       X
 *  1 -> X           | 1 -> X           | 1 -> 1 -> X                |       X
 */
void listAppend(List l1, List l2);

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
bool listIsKPeriodic(List l, int k);

/**
 * Returns the k'th last element in the list. You can assume that k will
 * be between 1 and N where N is the length of the list.  You can assume
 * that the list contains at least one element (i.e., it is not empty).
 */
int listKthLast(List l, int k);

/**
 * Returns  true  if the given list is palindromic, and false otherwise.
 * An empty list is considered to be palindromic.
 */
bool listIsPalindromic(List l);

/**
 * Deletes  every  kth value from the list. If k is 1, all values should
 * be deleted. You can assume k is positive.
 *
 * Examples:
 *             input list           |  k  |    resulting list
 * ---------------------------------+-----+-----------------------
 *  2 -> 4 -> 7 -> 1 -> X           |  1  | X
 *  2 -> 4 -> 7 -> 1 -> X           |  2  | 2 -> 7 -> X
 *  2 -> 4 -> 7 -> 1 -> X           |  3  | 2 -> 4 -> 1 -> X
 *  2 -> 4 -> 7 -> 1 -> X           |  4  | 2 -> 4 -> 7 -> X
 *  2 -> 4 -> 7 -> 1 -> X           |  5  | 2 -> 4 -> 7 -> 1 -> X
 *  2 -> 8 -> 1 -> 9 -> 0 -> 2 -> X |  3  | 2 -> 8 -> 9 -> 0 -> X
 */
void listDeleteEveryKth(List l, int k);

/**
 * Deletes  all  duplicate  values from the list. If the list contains a
 * duplicate  value,  the first instance  of  that  value  should remain
 * in the list, while all other instances should be removed.
 *
 * Examples:
 *             input list           |     resulting list
 * ---------------------------------+-----------------------
 *  4 -> 3 -> 5 -> 4 -> 3 -> X      | 4 -> 3 -> 5 -> X
 *  8 -> 2 -> 1 -> 3 -> X           | 8 -> 2 -> 1 -> 3 -> X
 *  4 -> 5 -> 4 -> 4 -> 7 -> 7 -> X | 4 -> 5 -> 7 -> X
 */
void listDeleteDuplicates(List l);

/**
 * Creates  a  new  list that is formed from zipping values from the two
 * given lists. The original lists should remain unchanged. Zip means to
 * take  values  from alternating lists. If one list is exhausted before
 * the  other,  repeatedly take values from the non-exhausted list until
 * both lists are exhausted.
 *
 * Examples:
 *        input l1        |       input l2        |          returned list       
 * -----------------------+-----------------------+---------------------------------
 *  1 -> 4 -> 7 -> X      | 8 -> 5 -> 6 -> X      | 1 -> 8 -> 4 -> 5 -> 7 -> 6 -> X
 *  6 -> 2 -> X           | 1 -> 9 -> 5 -> 3 -> X | 6 -> 1 -> 2 -> 9 -> 5 -> 3 -> X
 *  8 -> 1 -> 5 -> 5 -> X | 7 -> 3 -> X           | 8 -> 7 -> 1 -> 3 -> 5 -> 5 -> X
 *  X                     | 3 -> 7 -> 2 -> X      | 3 -> 7 -> 2 -> X
 *  5 -> 3 -> 5 -> 3 -> X | 4 -> X                | 5 -> 4 -> 3 -> 5 -> 3 -> X
 *  X                     | X                     | X
 */
List listZip(List l1, List l2);

/**
 * Merges  the  values from two sorted lists into a new sorted list. The
 * original  lists  should remain unchanged. The lists can be assumed to
 * be sorted (in ascending order).
 *
 * Examples:
 *        input l1        |       input l2        |               returned list
 * -----------------------+-----------------------+-------------------------------------------
 *  1 -> 4 -> 7 -> 9 -> X | 2 -> 3 -> 4 -> 5 -> X | 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 7 -> 9 -> X
 *  1 -> 2 -> 3 -> X      | 7 -> 8 -> 9 -> X      | 1 -> 2 -> 3 -> 7 -> 8 -> 9 -> X
 *  4 -> 5 -> X           | 3 -> 6 -> X           | 3 -> 4 -> 5 -> 6 -> X
 *  2 -> 8 -> 9 -> X      | X                     | 2 -> 8 -> 9 -> X
 *  X                     | X                     | X
 */
List listMergeSorted(List l1, List l2);

/**
 * Deletes all values that occur in both lists from both lists.
 */
void listDeleteIntersection(List l1, List l2);

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
void listDeleteMultiples(List l);

////////////////////////////////////////////////////////////////////////
// Utility Functions

void listPrint(List l);

List strToList(char *s);

List readList(void);

#endif

