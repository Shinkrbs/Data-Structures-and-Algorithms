#include <stdio.h>
#include <stdlib.h>

typedef struct _cnode 
{ 
    char data; 
    struct _cnode* next; 
} *CNODE;

typedef struct _cll 
{ 
    CNODE head; 
    int size; 
} *CLL;

CLL createCLLHex(int n) 
{
    if (n < 0)
        return NULL;

    CLL cll = (CLL)malloc(sizeof(struct _cll));
    if (!cll)
        return NULL;

    cll->head = NULL;
    cll->size = 0;

    if (n == 0) 
    {
        CNODE newNode = (CNODE)malloc(sizeof(struct _cnode));
        if (newNode) 
        {
            newNode->data = '0';
            newNode->next = newNode;
            cll->head = newNode;
            cll->size = 1;
        }
        return cll;
    }

    char hex[20];
    int index = 0;

    while (n > 0) 
    {
        int remainder = n % 16;
        if (remainder < 10)
            hex[index++] = '0' + remainder;
        else
            hex[index++] = 'A' + (remainder - 10);
        n /= 16;
    }

    for (int i = index - 1; i >= 0; i--) 
    {
        CNODE newNode = (CNODE)malloc(sizeof(struct _cnode));
        if (!newNode)
            return NULL;

        newNode->data = hex[i];

        if (cll->head == NULL) 
        {
            cll->head = newNode;
            cll->head->next = cll->head;
        } 
        else 
        {
            CNODE temp = cll->head;
            while (temp->next != cll->head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = cll->head;
        }
        cll->size++;
    }
    return cll;
}

int main()
{
    return 0;
}