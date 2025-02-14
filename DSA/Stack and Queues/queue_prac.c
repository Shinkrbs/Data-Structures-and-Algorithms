#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int Element;
#define EMPTY_STACK -1

typedef struct q
{
    Element* storage;
    int front, rear, count, capacity;
}*Q;

Q createQ(int capacity);
void freeQ(Q x);

void enqueue(Q x, Element data);
Element dequeue(Q x);
int isFull(Q x);
int isEmpty(Q x);
Element getFront(Q x);

// Stack
typedef struct stack
{
    Element* storage;
    int top, capacity;
}*STACK;

STACK createStack(int capacity);
void freeStack(STACK x);

// Stack Operations
void Push(STACK x, Element data);
Element Pop(STACK x);
int isEmptyStack(STACK x);
int isFullStack(STACK x);
int peek(STACK x);

// problems
Q stack_to_queue(STACK x);
STACK queue_to_stack(Q x);
void reverse(Q x);

int main()
{
    // Q q = createQ(10);

    // enqueue(q, 1);
    // enqueue(q, 2);
    // enqueue(q, 3);
    // enqueue(q, 4);
    // enqueue(q, 5);

    // printf("%d", dequeue(q));

    // STACK stack = createStack(10);
    // Q queue;

    // // Push elements onto the stack
    // Push(stack, 1);
    // Push(stack, 2);
    // Push(stack, 3);

    // // Convert stack to queue
    // queue = stack_to_queue(stack);

    // // Dequeue elements from the queue and print them
    // printf("Queue elements: ");
    // while (!isEmpty(queue)) 
    //     printf("%d ", dequeue(queue));
    // printf("\n");
    // // Expected output: 3 2 1

    // // Free memory
    // freeStack(stack);
    // freeQ(queue);

    // Q queue = createQ(10);
    // STACK stack;

    // // Enqueue elements into the queue
    // enqueue(queue, 1);
    // enqueue(queue, 2);
    // enqueue(queue, 3);

    // // Convert queue to stack
    // stack = queue_to_stack(queue);

    // // Pop elements from the stack and print them
    // printf("Stack elements: ");
    // while (!isEmptyStack(stack)) 
    //     printf("%d ", Pop(stack));
    // printf("\n");

    // // Free memory
    // freeQ(queue);
    // freeStack(stack);

    Q queue = createQ(10);

    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Reverse the queue
    reverse(queue);

    // Dequeue elements from the queue and print them
    printf("Reversed queue elements: ");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    // Free memory
    freeQ(queue);

    return 0;
}

Q createQ(int capacity)
{
    Q x = (Q)malloc(sizeof(struct q));
    x->storage = (Element*)malloc(sizeof(Element) * capacity);
    x->front = x->rear = x->count = 0;
    x->capacity = capacity;
    return x;
}

void enqueue(Q x, Element data)
{
    if(!isFull(x))
    {
        x->storage[x->rear] = data;
        x->rear = (x->rear + 1) % x->capacity;
        x->count++;
    }
}

Element dequeue(Q x)
{
    if(!isEmpty(x))
    {
        Element t = x->storage[x->front];
        x->front = (x->front + 1) % x->capacity;
        x->count--;
        return t;
    }
    else
        return EMPTY_STACK;
}

int isFull(Q x)
{
    return x->count == x->capacity;
}

int isEmpty(Q x)
{
    return x->count == 0;
}

Element getFront(Q x)
{
    return x->storage[x->front];
}

void freeQ(Q x)
{
    free(x->storage);
    free(x);
}

// Stack
STACK createStack(int capacity)
{
    STACK x = (STACK)malloc(sizeof(struct stack));
    x->storage = (Element*)malloc(sizeof(Element) * capacity);
    x->top = 0;
    x->capacity = capacity;
    return x;
}

void freeStack(STACK x)
{
    free(x->storage);
    free(x);
}

void Push(STACK x, Element data)
{
     if(!isFullStack(x))
        x->storage[x->top++] = data;
}

Element Pop(STACK x)
{
    return (!isEmptyStack(x)) ? x->storage[--(x->top)] : EMPTY_STACK;
}

int isEmptyStack(STACK x)
{
    return x->top == 0;
}

int isFullStack(STACK x)
{
    return x->top == x->capacity;
}

int peek(STACK x)
{
    return x->storage[x->top - 1];
}

// problems
Q stack_to_queue(STACK x)
{
    Q q1 = createQ(x->capacity), q2 = createQ(x->capacity);

    while(!isEmptyStack(x))
        enqueue(q1, Pop(x));
    
    while(!isEmpty(q1))
        enqueue(q2, dequeue(q1));
    
    freeQ(q1);
    return q2;
}

STACK queue_to_stack(Q x)
{
    STACK x1 = createStack(x->capacity), x2 = createStack(x->capacity);

    while(!isEmpty(x))
        Push(x1, dequeue(x));
    
    while(!isEmptyStack(x1))
        Push(x2, Pop(x1));
    
    freeStack(x1);
    return x2;
}

void reverse(Q x)
{
    Element* temp = (Element*)malloc(sizeof(Element) * x->capacity);
    int i = 0;

    while(!isEmpty(x))
    {
        temp[i] = dequeue(x);
        i++;
    }

    int l = 0, r = i- 1;

    while(l < r)
    {
        Element t = temp[l];
        temp[l] = temp[r];
        temp[r] = t;
        l++; 
        r--;
    }

    int j = 0;
    while(j < i)
    {
        enqueue(x, temp[j]);
        j++;
    }
    free(temp);
}