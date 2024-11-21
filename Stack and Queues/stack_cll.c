#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int Element;
#define EMPTY_STACK -1

typedef struct node
{
    int data;
    struct node *next;
}*NODE;

typedef struct cll
{
    NODE tail;
    int size;
}*CLL;

typedef struct stack
{
    CLL storage;
    NODE top;
}*STACK;

// Circular Linked List Functions
CLL createCLL();
NODE createNode();
void addFirst(CLL x, Element d);
void addLast(CLL x, Element d);
void displayCll(CLL x);

// Stack Functions
STACK createStack();
void freeStack(STACK x);

// Stack Operations
void Push(STACK x, Element data);
Element Pop(STACK x);
int isEmpty(CLL x);
// int isFull(STACK x); // Not Applicable??
Element peek(STACK x);

// Free Mem Functions
void freeCLL(CLL x);
void freeStack(STACK x);

int main() 
{
    STACK stack = createStack();
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    Push(stack, 50);
    Push(stack, 40);

    printf("Stack elements: ");
    displayCll(stack->storage);

    printf("\nPopped element: %d\n", Pop(stack));
    printf("Popped element: %d\n", Pop(stack));
    printf("Popped element: %d\n", Pop(stack));
    printf("Popped element: %d\n", Pop(stack)); // This will show underflow

    printf("%d", peek(stack));

    //freeStack(stack);
    return 0;
}

STACK createStack()
{
    STACK x = (STACK)malloc(sizeof(struct stack));
    x->storage = createCLL();
    x->top = NULL;
    return x;
}

CLL createCLL()
{
    CLL x = (CLL)malloc(sizeof(struct cll));
    x->tail = NULL;
    x->size = 0;
    return x;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->next = NULL;
    return x;
}

void addFirst(CLL x, Element d)
{
    NODE head = createNode(); 
    head->data = d;

    if(x->tail == NULL)
    {
        head->next = head;
        x->tail = head;
    }
    else
    {
        head->next = x->tail->next;
        x->tail->next = head;
    }
    x->size++;
}

void addLast(CLL x, Element d)
{
    NODE head = createNode();
    head->data = d;

    if(x->tail == NULL)
    {
        head->next = head;
        x->tail = head;
    }
    else
    {
        head->next = x->tail->next;
        x->tail->next = head;
        x->tail = head;
    }
    x->size++;
}

void displayCll(CLL x)
{
    if(x->tail == NULL)
        return;

    NODE p = x->tail->next;

    do
    {
        printf("%d->", p->data);
        p = p->next;
    } while (p != x->tail->next);
}

void Push(STACK x, Element data)
{
    addLast(x->storage, data);
    x->top = x->storage->tail;
}

Element Pop(STACK x)
{
    if(!isEmpty(x->storage))
    {
        Element data_to_pop = x->storage->tail->data;
        NODE p = x->storage->tail;
    
        if(p->next == p)
        {
            x->storage->tail->next = NULL;
            x->storage->tail = NULL;
            free(p);
        }
        else
        {
            while(p->next != x->storage->tail)
            p = p->next;
        
            p->next = x->storage->tail->next;
            free(x->storage->tail);
            x->storage->tail = p;
            x->top = p;
        }
        return data_to_pop;
    }
    return EMPTY_STACK;
}

int isEmpty(CLL x)
{
    return x->tail == NULL;
}

Element peek(STACK x)
{
    return x->top->data;
}

void freeStack(STACK x)
{
    freeCLL(x->storage);    
    free(x->top);
    free(x);
}

void freeCLL(CLL x)
{
    if(x->tail != NULL)
    {
        NODE p = x->tail->next, n;

        do
        {
            n = p->next;
            free(p);
            p = n;
        } while (p != x->tail->next);
        free(x->tail);
    }
    free(x);
}