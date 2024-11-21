#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
} *NODE;

typedef struct sll
{
    NODE head;
} *SLL;

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->val = 0;
    x->next= NULL;
    return x;
}

void addLast(SLL list, int x)
{
    NODE new = createNode();
    new->val = x;
    new->next = NULL;

    if(list->head == NULL)
        list->head = new;
    else
    {
        NODE p = list->head; 
        while(p->next != NULL)
            p = p->next;
        p->next = new;
    }
}

void addFirst(SLL list, int x)
{
    NODE new = createNode();
    new->val = x;
    
    if(list->head == NULL)
    {
        new->next = NULL;
        list->head = new;
    }
    else
    {
        new->next = list->head;
        list->head = new;
    }
}

void disp(SLL list)
{
    NODE p = list->head;
    while(p != NULL)
    {
        printf(" %d ->", p->val);
        p = p->next;
    }
    printf("\n");
}

SLL add_Two_Numbers(SLL list1, SLL list2)
{
    SLL res = (SLL)malloc(sizeof(struct sll));
    res->head = NULL;

    int dig1 = 0, dig2 = 0, sum = 0;
    NODE p = list1->head;

    while(p != NULL)
    {
        dig1 *= 10;
        dig1 += p->val;
        p = p->next;
    }
    p = list2->head;
    while(p != NULL)
    {
        dig2 *= 10;
        dig2 += p->val;
        p = p->next;
    }

    sum = dig1 + dig2;

    while(sum != 0)
    {
        addFirst(res, sum % 10);
        sum /= 10;
    }
    return res;
}

int main()
{
    SLL list1 = (SLL)malloc(sizeof(struct sll));
    list1->head = NULL;
    SLL list2 = (SLL)malloc(sizeof(struct sll));
    list2->head = NULL;

    addLast(list1, 1);
    addLast(list1, 2);
    addLast(list1, 3);
    addLast(list1, 4);
    addLast(list1, 5);
    addLast(list1, 4);

    addLast(list2, 9);
    addLast(list2, 4);
    addLast(list2, 9);
    addLast(list2, 9);
    addLast(list2, 9);
    addLast(list2, 9);

    disp(list1);
    disp(list2);

    SLL two = add_Two_Numbers(list1, list2);
    disp(two);
    return 0;
}