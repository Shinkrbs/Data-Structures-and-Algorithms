#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Still not done i will go back here later!!

typedef int element;
#define EMPTY 0

typedef struct q
{
    element* storage;
    int front, rear, capacity, count;
}*Q;

Q createQ(int capacity);
void freeq(Q x);

void enq(Q x, element data);
element deq(Q x);
bool isEmpty(Q x);
bool isFull(Q x);
element getFront(Q x);

void sortArr(int* arr, int n);
int maxCust(int* arr, int* exit, int n);
void rev(Q q);

// Test Cases
void test_maxCust(int *arr, int *exit, int n, int expected);

int main()
{
    // // Test case 1: Simple scenario
    // int arr1[] = {1, 2, 3};
    // int exit1[] = {2, 3, 4};
    // int expected1 = 2;
    // test_maxCust(arr1, exit1, 3, expected1);

    // // Test case 2: Increasing arrivals and departures
    // int arr2[] = {1, 2, 3, 4};
    // int exit2[] = {2, 3, 4, 5};
    // int expected2 = 2;
    // test_maxCust(arr2, exit2, 4, expected2);

    // // Test case 3: Decreasing arrivals and departures
    // int arr3[] = {4, 3, 2, 1};
    // int exit3[] = {5, 4, 3, 2};
    // int expected3 = 1;
    // test_maxCust(arr3, exit3, 4, expected3);

    // // // Test case 4: Empty input
    // // int arr4[] = {};
    // // int exit4[] = {};
    // // int expected4 = 0;
    // // test_maxCust(arr4, exit4, 0, expected4);

    // // Test case 5: Single arrival and departure
    // int arr5[] = {1};
    // int exit5[] = {2};
    // int expected5 = 1;
    // test_maxCust(arr5, exit5, 1, expected5);

    // // Test case 6: All arrivals before departures
    // int arr6[] = {1, 2, 3};
    // int exit6[] = {4, 5, 6};
    // int expected6 = 3;
    // test_maxCust(arr6, exit6, 3, expected6);

    // // Test case 7: All departures before arrivals
    // int arr7[] = {4, 5, 6};
    // int exit7[] = {1, 2, 3};
    // int expected7 = 0;
    // test_maxCust(arr7, exit7, 3, expected7);

    // // Test case 8: Interleaved arrivals and departures
    // int arr8[] = {1, 3, 5, 7, 9};
    // int exit8[] = {2, 4, 6, 8, 10};
    // int expected8 = 2;
    // test_maxCust(arr8, exit8, 5, expected8);

    // // Test case 9: Complex scenario with multiple peaks
    // int arr9[] = {10, 21, 3, 15, 19};
    // int exit9[] = {20, 30, 7, 17, 25};
    // int expected9 = 3;
    // test_maxCust(arr9, exit9, 5, expected9);

    //{5, 24, 9, 6, 8, 4, 1, 8, 3, 6};
    Q q = createQ(10);
    enq(q, 5);
    enq(q, 24);
    enq(q, 9);
    enq(q, 6);
    enq(q, 8);
    enq(q, 4);
    enq(q, 1);
    enq(q, 8);
    enq(q, 3);
    enq(q, 6);

    rev(q);
    
    // Expected: [6, 3, 8, 1, 4, 8, 6, 9, 24, 5]
    while(!isEmpty(q))
        printf("%d ", deq(q));
    printf("\n");

    return 0;
}

Q createQ(int capacity)
{
    Q x = (Q)malloc(sizeof(struct q));
    x->storage = (element*)malloc(sizeof(element) * capacity);
    x->front = x->rear = x->count = 0;
    x->capacity = capacity;
    return x;
}

void freeq(Q x)
{
    free(x->storage);
    free(x);
}

void enq(Q x, element data)
{
    if(!isFull(x))
    {
        x->storage[x->rear] = data;
        x->rear = (x->rear + 1) % x->capacity;
        x->count++;
    }
}

element deq(Q x)
{
    if(!isEmpty(x))
    {
        element t = x->storage[x->front];
        x->front = (x->front + 1) % x->capacity;
        x->count--;
        return t;
    }
    else    
        return EMPTY;
}

bool isEmpty(Q x)
{
    return x->count == 0;
}

bool isFull(Q x)
{
    return x->count == x->capacity;
}

element getFront(Q x)
{
    return x->storage[x->front];
}

void sortArr(int* arr, int n)
{
    for(int i = 0; i < n -1 ; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int maxCust(int* arr, int* exit, int n)
{
    // Sort Entrance and Exit
    sortArr(arr, n);
    sortArr(exit, n);

    // Make a Q
    Q q = createQ(n);
    int maxSize = 0;

    for(int i = 0; i < n; i++)
    {
        while(!isEmpty(q) && getFront(q) <= arr[i])
            deq(q);
        enq(q, exit[i]);
        maxSize = fmax(q->count, maxSize);
    }
    return maxSize;
}

void test_maxCust(int *arr, int *exit, int n, int expected) 
{
    int actual = maxCust(arr, exit, n);
    if (actual == expected)
        printf("Test case passed.\n");
    else 
        printf("Test case failed. Expected %d, got %d.\n", expected, actual);
    
}

void rev(Q q)
{
    if(isEmpty(q)) return;
    element data = deq(q);
    rev(q);
    enq(q, data);
}