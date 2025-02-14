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



DLL DLL_removeDuplicates(DLL list) 
{
    if (!list->head) return list;

    DNODE current = list->head;

    while (current) 
    {
        DNODE p = current->next;

        while (p) 
        {
            if (p->data == current->data) 
            {
                DNODE nextP = p->next;

                if (p->prev) 
                    p->prev->next = p->next;
                else 
                    list->head = p->next;

                if (p->next) 
                    p->next->prev = p->prev;
                else 
                    list->tail = p->prev;

                free(p);
                list->size--;

                p = nextP;
            } 
            else 
                p = p->next;

        }

        current = current->next;
    }

    return list;
}

int main()
{
    return 0;
}