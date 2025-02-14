#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct node
{
    Element data;
    struct node* next;
}*NODE;

typedef struct sll
{
    NODE head;
    int size;
}*SLL;

SLL createSLL();
NODE createNode();
void freeList(SLL list); // THis shit has a problem

void addFirst(SLL list, Element data);
void addLast(SLL list, Element data);
void dispSLL(SLL list);

// Problems
void deleteNode(SLL list, Element target);
void rotSLL(SLL list, int rot);
int check_three_consecutive(SLL list, Element target);
void remove_duplicates(SLL list);

// Helper Functions
void reverse(int* x, int l, int r);
int isDuplicate(int* x, Element data, int size);


int main()
{
    // Create a new singly linked list
    SLL list = createSLL();

    // Add elements to the list
    addFirst(list, 5);
    addFirst(list, 2);
    addFirst(list, 1);
    addFirst(list, 1);
    addFirst(list, 1);

    // Display the original list
    printf("Original list: ");
    dispSLL(list);

    // Rotate the list by 2 positions
    int rotation = 2;
    rotSLL(list, rotation);

    // Display the rotated list
    printf("List after rotating by %d positions: ", rotation);
    dispSLL(list);

    // Check Consecutives
    printf("Three Consecutive Ones: %d\n", check_three_consecutive(list, 1));

    // Duplicates
    printf("Removing Duplicates: ");
    remove_duplicates(list);
    dispSLL(list);

    printf("Deleting 2 from the List: ");
    deleteNode(list, 2);
    dispSLL(list);

    //freeList(list);

    return 0;
}

SLL createSLL()
{
    SLL x = (SLL)malloc(sizeof(struct sll));
    x->head = NULL;
    x->size = 0;
    return x;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->next = NULL;
    return x;
}

void freeList(SLL list)
{
    if(list ==  NULL)
        return;

    NODE current = list->head;
    NODE next;

    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
    list = NULL;
}

void addFirst(SLL list, Element data)
{
    NODE new = createNode();
    new->data = data;

    if(list->head == NULL)
        list->head = new;
    else
    {
        new->next = list->head;
        list->head = new;
    }
    list->size++;
}

void addLast(SLL list, Element data)
{
    NODE new = createNode();
    new->data = data;
    
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

void dispSLL(SLL list)
{
    NODE p = list->head;
    while( p != NULL)
    {
        printf("%d-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void deleteNode(SLL list, Element target)
{
    NODE p = list->head;
    if(list->head == NULL)
        return;
    else if(p->data == target)
    {
        list->head = p->next;
        list->size--;
        free(p);
        return;
    }

    while(p->next != NULL && p->next->data != target)
        p = p->next;
    if(p->next != NULL)
    {
        NODE temp =  p->next;
        p->next = temp->next;
        free(temp);
        list->size--;
    }
}

void rotSLL(SLL list, int rot)
{
    if(list->head == NULL || rot == 0)
        return;

    int* temp = (int*)malloc(sizeof(int) * list->size);
    NODE p = list->head;

    for(int i = 0; p != NULL; i++, p = p->next)
        temp[i] = p->data;


    // Rotating 
    rot = rot % list->size; // Ensure that rotation will not go out of bounds
    reverse(temp, 0, list->size - 1);
    reverse(temp, rot, list->size - 1);
    reverse(temp, 0, rot - 1);

    // Add Values to SLL
    p = list->head;
    for(int i = 0; p != NULL; i++, p = p->next)
        p->data = temp[i];
    free(temp);
}

void reverse(int* x, int l, int r)
{
    while(l < r)
    {
        int temp = x[l];
        x[l] = x[r];
        x[r] = temp;
        l++;
        r--;
    }
}

int check_three_consecutive(SLL list, Element target)
{
    NODE p = list->head;
    int count = 0;

    while(p != NULL)
    {
        if(p->data == target)
        {
            count++;
            if(count == 3)
                return 1;
        }
        else
            count = 0;
        p = p->next;
    }
    return 0;
}

void remove_duplicates(SLL list)
{
    if(list->head == NULL)
        return;

    int* temp = (int*)malloc(sizeof(int) * list->size);
    int counter = 0;
    NODE p = list->head;

    while(p != NULL)
    {
        if(!isDuplicate(temp, p->data, counter))
        {
            temp[counter] = p->data;
            counter++;
        }
        p = p->next;
    }

    // Make new SLL
    SLL new = createSLL();
    for(int i = 0; i < counter; i++)
        addLast(new, temp[i]);

    // Redirecting the addresses
    //freeList(list);
    list->head = new->head;
    list->size = new->size;

    //freeList(new);
    free(temp);
}

int isDuplicate(int* x, Element data, int size)
{
    for(int i = 0; i < size; i++)
        if(x[i] == data)
            return 1;
    return 0;
}