#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#define EMPTY -1

typedef struct q
{
    Element* storage;
    int front, rear, count, capacity;
}*Q;

Q createQ(int capacity);
void freeq(Q x);

void enqueue(Q x, Element data);
Element dequeue(Q x);
int isFull_Q(Q x);
int isEmpty_Q(Q x);
Element getFront(Q x);

// Stack 
typedef struct stack
{
    Q q1;
    Q q2;
}*STACK;

STACK createStack(int capacity);
void freeStack(STACK x);

// Stack Operations
STACK createStack(int capacity);
void freeStack(STACK x);

void Push(STACK x, Element data);
Element Pop(STACK x);
int isEmpty_S(STACK x);
int isFull_S(STACK x);
int peek(STACK x);

int main()
{
    // Create a stack with a capacity of 5
    STACK stack = createStack(5);

    // Test Case 1: Push elements onto the stack
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    printf("Top element after pushing 10, 20, 30: %d\n", peek(stack)); // Expected: 30

    // Test Case 2: Pop an element from the stack
    printf("Popped element: %d\n", Pop(stack)); // Expected: 30
    printf("Top element after popping: %d\n", peek(stack)); // Expected: 20

    // Test Case 3: Push another element
    Push(stack, 40);
    printf("Top element after pushing 40: %d\n", peek(stack)); // Expected: 40

    // Test Case 4: Pop all elements
    printf("Popped element: %d\n", Pop(stack)); // Expected: 40
    printf("Popped element: %d\n", Pop(stack)); // Expected: 20
    printf("Popped element: %d\n", Pop(stack)); // Expected: 10
    printf("Is stack empty? %d\n", isEmpty_S(stack)); // Expected: 1 (true)

    // Test Case 5: Peek on an empty stack
    printf("Peek on empty stack: %d\n", peek(stack)); // Expected: -1 (EMPTY)

    // Clean up
    freeStack(stack);
    return 0;
}

// Queue Operations

Q createQ(int capacity)
{
    Q x = (Q)malloc(sizeof(struct q));
    x->storage = (Element*)malloc(sizeof(Element) * capacity);
    x->front = x->rear = x->count = 0;
    x->capacity = capacity;
    return x;
}

void freeq(Q x)
{
    free(x->storage);
    free(x);
}

void enqueue(Q x, Element data)
{
    if(!isFull_Q(x))
    {
        x->storage[x->rear] = data;
        x->rear = (x->rear + 1) % x->capacity;
        x->count++;
    }
}

Element dequeue(Q x)
{
    if(!isEmpty_Q(x))
    {
        Element t = x->storage[x->front];
        x->front = (x->front + 1) % x->capacity;
        x->count--;
        return t;
    }
    else
        return EMPTY;
}

int isFull_Q(Q x)
{
    return x->count == x->capacity;
}

int isEmpty_Q(Q x)
{
    return x->count == 0;
}

Element getFront(Q x)
{
    return x->storage[x->front];
}

// Stack operations 
STACK createStack(int capacity)
{
    STACK x = (STACK)malloc(sizeof(struct stack));
    x->q1 = createQ(capacity);
    x->q2 = createQ(capacity);
    return x;
}

void freeStack(STACK x)
{
    freeq(x->q1);
    freeq(x->q2);
    free(x);
}

void Push(STACK x, Element data)
{
    enqueue(x->q2, data);
    while(!isEmpty_Q(x->q1))
        enqueue(x->q2, dequeue(x->q1));
    // Swap the pointers
    Q temp = x->q1;
    x->q1 = x->q2;
    x->q2 = temp;
}

Element Pop(STACK x)
{
    return dequeue(x->q1);
}

int isEmpty_S(STACK x)
{
    return isEmpty_Q(x->q1);
}

int isFull_S(STACK x)
{
    return isFull_Q(x->q1);
}

int peek(STACK x)
{
    return (isEmpty_S(x)) ? EMPTY : getFront(x->q1);
}