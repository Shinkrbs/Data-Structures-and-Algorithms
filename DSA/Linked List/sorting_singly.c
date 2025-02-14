#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 100000

typedef int item;

typedef struct node
{
    int data;
    struct node* next;
}*NODE;

typedef struct sll
{
    NODE head;
}*SLL;

SLL createSLL();
NODE createNode();

void addFirst(SLL list, item x);
void addLast(SLL list, item x);
void b_sortSLL(SLL list);
void removeDuplicates(SLL list);
void reversal(SLL list);
void rotate(SLL list, int k);
void duplicateRemover(SLL l);

void display(SLL list);

int main()
{
    SLL list = createSLL();

    addLast(list, 5);
    addLast(list, 1);
    addLast(list, 4);
    addLast(list, 2);
    addLast(list, 8);
    addLast(list, 8);
    addLast(list, 7);
    addLast(list, 5);

    display(list);
    // b_sortSLL(list);
    // display(list);
    // removeDuplicates(list);
    // display(list);
    // reversal(list);
    // display(list);
    // rotate(list, 3);
    duplicateRemover(list);
    display(list);
    return 0;
}

SLL createSLL()
{
    SLL x = (SLL)malloc(sizeof(struct sll));
    x->head = NULL;
    return x;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->data = 0;
    x->next = NULL;
    return x;
}

void addFirst(SLL list, item x)
{
    NODE new = createNode();
    new->data = x;

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

void addLast(SLL list, item x)
{
    NODE new = createNode();
    new->data = x;  
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

void display(SLL list)
{
    NODE p = list->head;
    while(p != NULL)
    {
        printf(" %d->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
}

void b_sortSLL(SLL list)
{
    if(list->head == NULL)
        return;

    bool swapped;
    NODE p, lp = NULL;

    do
    {
        swapped = false;
        p = list->head;
        
        while(p->next != lp)
        {
            if(p->data > p->next->data)
            {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = true;
            }
            p = p->next;
        }
        lp = p;
    } while (swapped);
}

void removeDuplicates(SLL list)
{
    if(list->head == NULL)
        return;
    NODE c = list->head, p = NULL;

    while(c != NULL)
    {
        p = c;
        NODE runner = c->next;
        
        while(runner != NULL)
        {
            if(c->data == runner->data)
            {
                p->next = runner->next;
                free(runner);
                runner = p->next;
            }
            else
            {
                p = runner;
                runner = runner->next;
            }
        }
        c = c->next;
    }
}

//Jake Code
void duplicateRemover(SLL l) {
    if(l->head == NULL) return;
    int* seen = (int*)malloc(sizeof(int) * ( MAX_NUM * 2 + 1 ));
    
    SLL new = (SLL)malloc(sizeof(struct sll));
    new->head = NULL;
    NODE p = l->head;
    NODE toDelete = NULL;

    while(p != NULL) {
        if(!seen[p->data + MAX_NUM]){
            addLast(new, p->data);
            seen[p->data + MAX_NUM] = 1; 
        }
        toDelete = p;
        p = p->next;
        free(toDelete);
    }

    l->head = new->head;
    free(seen);
    free(new);
}

void reversal(SLL sll)
{
    if(sll->head == NULL) return;

    NODE prev = NULL;
    NODE current = sll->head;
    NODE next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    sll->head = prev;
}

void rotate(SLL list, int k)
{
    if (list->head == NULL || k == 0)
        return; // No need to rotate if list is empty or k is 0

    // Find the length of the list
    NODE current = list->head;
    int length = 1;
    while (current->next != NULL)
    {
        current = current->next;
        length++;
    }

    // If k is greater than the length, take the modulus
    k = k % length;
    if (k == 0) 
        return; // No change if k is a multiple of length

    // Find the (length - k)th node
    current = list->head;
    for (int i = 1; i < length - k; i++)
        current = current->next;

    // `current` is now the (length - k)th node
    NODE newHead = current->next;
    current->next = NULL; // Break the list at (length - k)th node

    // Move to the last node of the new list
    NODE tail = newHead;
    while (tail->next != NULL)
        tail = tail->next;

    // Connect the end of the new list to the old head
    tail->next = list->head;

    // Update the head of the list
    list->head = newHead;
}