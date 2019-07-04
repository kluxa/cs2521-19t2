// removeValue.c 
// Written by Ashesh Mahidadia, August 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"


/* 
    You will submit only this one file.

    Implement the function "removeValue" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/



void removeValue(DLList L, int value) {
    DLListNode *curr = L->first;
    while (curr != NULL) {
        if (curr->value == value) {
            DLListNode *toDelete = curr;
            // What cases do we have for deletion?
            if (L->nitems == 1) {
                L->first = NULL;
                L->last = NULL;
                L->curr = NULL;
            
            } else if (curr == L->first) {
                L->first = L->first->next;
                L->first->prev = NULL;
                L->curr = L->first;
            
            } else if (curr == L->last) {
                L->last = L->last->prev;
                L->last->next = NULL;
                L->curr = L->last;
            
            } else {
                L->curr->prev->next = L->curr->next;
                L->curr->next->prev = L->curr->prev;
                L->curr = L->curr->next;
            }

            L->nitems--;
            free(toDelete);
        }
        curr = curr->next;
    }

    // As specified in the qusetion
    L->curr = L->first;
	return;
}



