#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode 
{ 
    int data; 
    struct _dnode *prev, *next; 
} *DNODE;

typedef struct _dll 
{ 
    DNODE head, tail; 
    int size; 
} *DLL;


void DLL_deleteThreeMaxOccurrenceOfY(DLL list, int y) 
{
    if (!list->tail) 
        return;

    DNODE current = list->tail;
    int deleted = 0;

    while (current && deleted < 3) 
    {
        if (current->data == y)
        {
            DNODE toDelete = current;
            current = current->prev;

            if (toDelete->prev) 
                toDelete->prev->next = toDelete->next;
            else 
                list->head = toDelete->next;
            
            if (toDelete->next)
                toDelete->next->prev = toDelete->prev;
            else 
                list->tail = toDelete->prev;

            free(toDelete);
            list->size--;
            deleted++;
        }
        else 
            current = current->prev;
    }
}

int main()
{
    return 0;
}