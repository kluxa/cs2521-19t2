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

void DLListAppend(DLList L, int value);

DLList getPeaks(DLList L) {
    DLList peaksL = newDLList();

    // Because the first and last items can't be peaks, there can't be
    // any peaks if the input list has fewer than 3 items.
    if (L->nitems < 3) {
        return peaksL;
    }

    // The first value can't be a peak, so start at the second value.
    // Loop  from  the  second node to the second last node (why do we
    // stop  at  the last node instead of NULL?). If the current value
    // is a peak, append it to the peaks list.
    for (DLListNode *curr = L->first->next; curr->next != NULL; curr = curr->next) {
        if (curr->value > curr->prev->value && curr->value < curr->next->value) {
            // You should break your code up into functions
            DLListAppend(peaksL, curr->value);
        }
    }

    // Just to be safe
    peaksL->curr = peaksL->first;
    return peaksL;
}

void DLListAppend(DLList L, int value) {
    DLListNode *new = malloc(sizeof(*new));
    
    if (L->first == NULL) {
        L->first = new;
        L->last = new;
        L->curr = new;

    } else {
        new->prev = L->last;
        L->last = new;
        L->last->next = new;
    }
}
