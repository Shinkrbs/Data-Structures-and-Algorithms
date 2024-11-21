#include <stdio.h>
#include <stdlib.h>

typedef int item;

typedef struct node
{
    item data;
    struct node* next;
} *NODE;

typedef struct sll
{
    NODE head;
    int size;
} *SLL;

NODE createNode();
void deleteNODE(SLL list, item data);
SLL createSLL();
void deleteSLL(SLL list);
void dispSLL(SLL list);

void addLast(SLL list, item x);
void addFirst(SLL list, item x);
void insert_bet_XY(SLL list, item x, item y, item d);

//Test Cases
void testAddLast(SLL list);
void testAddFirst(SLL list);
void testSizeAfterOperations(SLL list);
void testDeleteNode(SLL list);
void testInsert(SLL list);

int main()
{
    SLL list = createSLL();
    //testAddFirst(list);
    //testAddLast(list);
    //testSizeAfterOperations(list);
    //testDeleteNode(list);
    testInsert(list);

    return 0;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->data = 0;
    x->next = NULL;
    return x;
}

void deleteNODE(SLL list, item data)
{
    NODE p = list->head;

    if(list->head == NULL) 
        return;
    else if(p->data == data)
    {
        list->head = p->next;
        list->size--;
        free(p);
        return;
    }

    NODE prev = NULL;
    while(p != NULL && p->data != data)
    {
        prev = p;
        p = p->next;
    }
    
    if(p != NULL)
    {
        prev->next = p->next;
        list->size--;
        free(p);
    }
}

SLL createSLL()
{
    SLL x = (SLL)malloc(sizeof(struct sll));
    x->head = NULL;
    x->size = 0;
    return x;
}

void deleteSLL(SLL list)
{
    NODE curr = list->head;
    NODE next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
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
    list->size++;
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
    list->size++;
}

void insert_bet_XY(SLL list, item x, item y, item d)
{
    NODE new = createNode();
    NODE p = list->head;
    new->data = d;
    
    while(p != NULL)
    {
        if(p->next != NULL && p->data == x && p->next->data == y)
        {
            new->next = p->next;
            p->next = new;
        }
        p = p->next;
    }
    list->size++;
}

void dispSLL(SLL list)
{
    NODE p = list->head;
    while(p != NULL)
    {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
}

// Test cases
void testAddFirst(SLL list) 
{
    printf("Testing addFirst:\n");
    addFirst(list, 10);
    dispSLL(list); // Expected: 10 -> NULL

    addFirst(list, 20);
    dispSLL(list); // Expected: 20 -> 10 -> NULL

    addFirst(list, 30);
    dispSLL(list); // Expected: 30 -> 20 -> 10 -> NULL

    deleteSLL(list);
}

void testAddLast(SLL list) 
{
    printf("Testing addLast:\n");
    addLast(list, 10);
    dispSLL(list); // Expected: 10 -> NULL

    addLast(list, 20);
    dispSLL(list); // Expected: 10 -> 20 -> NULL

    addLast(list, 30);
    dispSLL(list); // Expected: 10 -> 20 -> 30 -> NULL

    deleteSLL(list);
}

void testSizeAfterOperations(SLL list) 
{
    printf("Testing size after operations:\n");
    
    addFirst(list, 1);
    printf("Size after adding first element: %d (Expected: 1)\n", list->size); // Expected size: 1
    dispSLL(list);

    addLast(list, 2);
    printf("Size after adding last element: %d (Expected: 2)\n", list->size); // Expected size: 2
    dispSLL(list);

    addLast(list, 3);
    printf("Size after adding another last element: %d (Expected: 3)\n", list->size); // Expected size: 3
    dispSLL(list);

    deleteSLL(list);
}

void testDeleteNode(SLL list) 
{
    printf("Testing deleteNODE:\n");

    // Adding some nodes
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 4);

    printf("Initial list: ");
    dispSLL(list); // Expected: 1 -> 2 -> 3 -> 4 -> NULL

    // Test deleting a middle node
    deleteNODE(list, 3);
    printf("After deleting 3: ");
    dispSLL(list); // Expected: 1 -> 2 -> 4 -> NULL

    // Test deleting the head node
    deleteNODE(list, 1);
    printf("After deleting 1 (head): ");
    dispSLL(list); // Expected: 2 -> 4 -> NULL

    // Test deleting the last node
    deleteNODE(list, 4);
    printf("After deleting 4 (last node): ");
    dispSLL(list); // Expected: 2 -> NULL

    // Test deleting a node that doesn't exist
    deleteNODE(list, 10);
    printf("After trying to delete non-existent 10: ");
    dispSLL(list); // Expected: 2 -> NULL
}

void testInsert(SLL list)
{
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 4);
    addLast(list, 5);
    addLast(list, 4);

    printf("Initial List:\n");
    dispSLL(list);

    insert_bet_XY(list, 2, 3, 0);
    printf("List After Inserting:\n");
    dispSLL(list);

    insert_bet_XY(list, 4, 5, 0);
    printf("List After Inserting:\n");
    dispSLL(list);
}