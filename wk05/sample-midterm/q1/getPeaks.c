// getPeaks.c 
// Written by Ashesh Mahidadia, August 2017

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DLList.h"

/* 
    You will submit only this one file.

    Implement the function "getPeaks" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/

static DLListNode *DLListAppend(DLList L, int value);

DLList getPeaks(DLList L) {
	DLList peaksL = newDLList();

    // Because the first and last items can't be peaks, there can't be
    // any peaks if the input list has fewer than 3 items.
    if (L->nitems < 3) {
        return peaksL;
    }

    // Loop  from  the second node to the last node (why do we stop at
    // the  last  node  instead of NULL?). If current value is a peak,
    // append it to the peaks list.
    for (DLListNode *curr = L->first->next; curr->next != NULL; curr = curr->next) {
        if (curr->value > curr->prev->value && curr->value > curr->next->value) {
            DLListAppend(peaksL, curr->value);
        }
    }

    peaksL->curr = peaksL->first;
	return peaksL;
}

static DLListNode *DLListAppend(DLList L, int value) {
    DLListNode *new = newDLListNode(value);
    
    if (L->first == NULL) {
        L->first = new;
        L->last = new;
        L->curr = new;
    } else {
        L->last->next = new;
        new->prev = L->last;
        L->last = new;
    }
    L->nitems++;
    return new;
}
