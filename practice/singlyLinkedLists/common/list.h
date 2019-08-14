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
 */
int listDeleteNth(List l, int n);

/**
 * Returns  true if the list is in ascending order, and false otherwise.
 * For  example, 2 -> 3 -> 3 -> 5 -> X is ascending, 2 -> 5 -> 3 -> X is
 * not. An empty list is considered to be ascending.
 */
bool listIsAscending(List l);

/**
 * Removes  the  second  instance of the duplicate in the list (if there
 * is  one),  and returns the value that was deleted, or NO_DUPLICATE if
 * there  was  no  duplicate.  You  can assume that there is at most one
 * duplicate value.
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
 */
void listAppend(List l1, List l2);

/**
 * Returns true if the given list is k-periodic,  and false otherwise. A
 * list is k-periodic if the list repeats itself every k-values. If k is
 * greater  than  or equal to the list length, the list is automatically
 * k-periodic. You can assume k is positive.
 */
bool listIsKPeriodic(List l, int k);

/**
 * Deletes  values  from  the list that do not preserve ascending order,
 * starting from the beginning of the list.
 */
void listPreserveAscending(List l);

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
 */
void listDeleteEveryKth(List l, int k);

/**
 * Deletes  all  duplicate  values from the list. If the list contains a
 * duplicate  value,  the first instance  of  that  value  should remain
 * in the list, while all other instances should be removed.
 */
void listDeleteDuplicates(List l);

/**
 * Creates  a  new  list that is formed from zipping values from the two
 * given lists. The original lists should remain unchanged. Zip means to
 * take  values  from alternating lists. If one list is exhausted before
 * the  other,  repeatedly take values from the non-exhausted list until
 * both lists are exhausted.
 */
List listZip(List l1, List l2);

/**
 * Merges  the  values from two sorted lists into a new sorted list. The
 * original  lists  should remain unchanged. The lists can be assumed to
 * be sorted (in ascending order).
 */
List listMergeSorted(List l1, List l2);

////////////////////////////////////////////////////////////////////////
// Utility Functions

// You shouldn't use any of these functions in your code. (You shouldn't
// need to.)

void listPrint(List l);

List strToList(char *s);

List readList(void);

#endif

