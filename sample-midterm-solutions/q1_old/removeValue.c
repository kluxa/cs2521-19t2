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

    - DO NOT modify code in the file DLList.h. 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/



void removeValue(DLList L, int value) {
    DLListNode *curr = L->first;
    while (curr != NULL) {
        if (curr->value == value) {
            
            // What cases do we have for deletion?
            // Note we don't change L->curr because we're
            // using a separate curr pointer that is external
            // to the list. It's often better to do it this way
            
            // Only one item
            if (L->nitems == 1) {
                L->first = NULL;
                L->last = NULL;
            
            // First item
            } else if (curr == L->first) {
                L->first = L->first->next;
                L->first->prev = NULL;
            
            // Last item
            } else if (curr == L->last) {
                L->last = L->last->prev;
                L->last->next = NULL;
            
            // Otherwise
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            
            DLListNode *temp = curr; // temporary pointer
            curr = curr->next; // move curr out of the way
            free(temp);
            L->nitems--;
            
        } else {
            curr = curr->next;
        }
    }

    // As specified in the question
    L->curr = L->first;
    return;
}



