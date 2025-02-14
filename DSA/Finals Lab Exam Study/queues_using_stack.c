#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#define EMPTY -1

typedef struct stack
{
    Element* storage;
    int top, capacity;
}*STACK;

// Stack Operations
STACK createStack(int capacity);
void freeStack(STACK x);

void Push(STACK x, Element data);
Element Pop(STACK x);
int isEmpty_S(STACK x);
int isFull_S(STACK x);
Element peek(STACK x);

// Queue Part
typedef struct q
{
    STACK s1;
    STACK s2;
}*Q;

// Queue Operations
Q createQ(int capacity);
void freeq(Q x);

void enqueue(Q x, Element data);
Element dequeue(Q x);
int isFull_Q(Q x);
int isEmpty_Q(Q x);
Element getFront(Q x);

int main()
{
    // Create a queue with a capacity of 5
    Q queue = createQ(5);

    // Test enqueue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    // Expected output: Queue contains 10, 20, 30

    // Test getFront
    printf("Front element: %d\n", getFront(queue)); // Expected: 10

    // Test dequeue
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: 10
    // Expected queue now contains 20, 30

    // Test getFront again
    printf("Front element: %d\n", getFront(queue)); // Expected: 20

    // Test enqueue more elements
    enqueue(queue, 40);
    enqueue(queue, 50);
    // Expected queue now contains 20, 30, 40, 50

    // Test isFull_Q
    printf("Is full: %d\n", isFull_Q(queue)); // Expected: 0 (false)

    // Test enqueue to fill the queue
    enqueue(queue, 60);
    // Expected output: No output, but the queue should be full now

    // Test isFull_Q after filling
    printf("Is full: %d\n", isFull_Q(queue)); // Expected: 1 (true)

    // Test dequeue until empty
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: 20
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: 30
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: 40
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: 50
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: 60
    printf("Dequeued: %d\n", dequeue(queue)); // Expected: -1 (EMPTY)

    // Test isEmpty_Q
    printf("Is empty: %d\n", isEmpty_Q(queue)); // Expected: 1 (true)

    // Clean up
    freeq(queue);

    return 0;
}

STACK createStack(int capacity)
{
    STACK x =  (STACK)malloc(sizeof(struct stack));
    x->storage = (Element*)malloc(sizeof(Element) * capacity);
    x->capacity = capacity;
    x->top = 0;
    return x;
}

void freeStack(STACK x)
{
    free(x->storage);
    free(x);
}

void Push(STACK x, Element data)
{
    if(!isFull_S(x))
        x->storage[x->top++] = data;
}

Element Pop(STACK x)
{
    return (!isEmpty_S(x)) ? x->storage[--(x->top)] : EMPTY;
}

int isEmpty_S(STACK x)
{
    return x->top == 0;
}

int isFull_S(STACK x)
{
    return x->top == x->capacity;
}

Element peek(STACK x)
{
    return x->storage[x->top - 1];
}

// Queue Operations
Q createQ(int capacity)
{
    Q x = (Q)malloc(sizeof(struct q));
    x->s1 = createStack(capacity);
    x->s2 = createStack(capacity);
    return x;
}

void freeq(Q x)
{
    freeStack(x->s1);
    freeStack(x->s2);
    free(x);
}

void enqueue(Q x, Element data)
{
    while(!isEmpty_S(x->s1))
        Push(x->s2, Pop(x->s1));
    Push(x->s1, data);
    while(!isEmpty_S(x->s2))
        Push(x->s1, Pop(x->s2));
}

Element dequeue(Q x)
{
    return (!isEmpty_S(x->s1)) ? Pop(x->s1) : EMPTY;
}

int isFull_Q(Q x)
{
    return isFull_S(x->s1) || isFull_S(x->s2);
}

int isEmpty_Q(Q x)
{
    return isEmpty_S(x->s1) || isEmpty_S(x->s2);
}

Element getFront(Q x)
{
    return (!isEmpty_S(x->s1)) ? peek(x->s1) : EMPTY;
}