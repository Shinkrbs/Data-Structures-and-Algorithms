#include <stdio.h>
#include <stdlib.h>

typedef struct _cnode 
{ 
    int data; 
    struct _cnode* next; 
} *CNODE;

typedef struct _cll 
{ 
    CNODE tail;
    int size; 
} *CLL;


void CLL_rotateRight(CLL list, int n) 
{
    if (!list->tail || list->size <= 1 || n == 0) 
        return;

    n = n % list->size;

    if (n == 0) 
        return;

    CNODE newTail = list->tail;
    int s = list->size - n; 

    while (s--)
        newTail = newTail->next;

    list->tail = newTail; 
    list->tail->next = newTail->next;
}
