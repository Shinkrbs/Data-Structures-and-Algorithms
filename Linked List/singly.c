#include <stdio.h>
#include <stdlib.h>

// Code implementation of singly linked list module

typedef char Item;

typedef struct node
{
    Item data;
    struct node* next;
} *NODE;

typedef struct sll
{
    NODE head;
    int size;
} *SLL;

SLL createSLL()
{
    SLL x = (SLL)malloc(sizeof(struct sll));
    x->head = NULL;
    x->size = 0;
    return x;
}

void print(SLL sll)
{
    if(sll->size > 0)
    {
        NODE p = sll->head;
        while(p != NULL)
        {
            printf("%c->", p->data);
            p = p->next;
        }
    }
}

void addLast(SLL sll, Item data)
{
    NODE p = sll->head;
    if(p == NULL)
    {
        sll->head = (NODE)malloc(sizeof(struct node));
        sll->head->data = data;
        sll->head->next = NULL;
    }
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = (NODE)malloc(sizeof(struct node));
        p->next->data = data;
        p->next->next = NULL;
    }
    sll->size++;
}

int main()
{
    SLL list = createSLL();
    addLast(list, 'A');
    addLast(list, 'B');
    addLast(list, 'C');
    addLast(list, 'D');

    print(list);

    free(list);
    return 0;
}