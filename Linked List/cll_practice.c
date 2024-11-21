#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int data;

typedef struct node
{
    int data;
    struct node *next;
}*NODE;

typedef struct cll
{
    NODE head;
    int size;
}*CLL;

CLL createList();
NODE createNode();

void displayList(CLL list);
void addFirst(CLL list, data x);
void addLast(CLL list, data x);
void sort(CLL list);
void reverse(CLL list);
void reverse_rot(CLL list, int s, int e);
void CLL_rotateRight(CLL list, int n);
CLL merge(CLL list1, CLL list2);

int main()
{
    // CLL x = createList();
    // addLast(x, 1);
    // //addLast(x, 2);
    // addLast(x, 2);
    // addLast(x, 3);
    // addLast(x, 4);
    // addLast(x, 5);
    // addLast(x, 6);
    // addLast(x, 6);
    // addLast(x, 7);

    // displayList(x);
    // reverse(x);
    // displayList(x);

    CLL x = createList();
    addLast(x, 2);
    addLast(x, 3);
    addLast(x, 4);
    addLast(x, 5);
    addLast(x, 6);
    addLast(x, 6);
    addLast(x, 7);

    CLL y = createList();
    addLast(y, 8);
    addLast(y, 9);
    addLast(y, 10);
    addLast(y, 11);
    addLast(y, 12);
    addLast(y, 13);
    addLast(y, 14);

    displayList(x);
    displayList(y);
    CLL new = merge(x, y);
    displayList(new);
    displayList(x);
    displayList(y);
    printf("%d %d %d", x->size, y->size, new->size);

    return 0;
}

CLL createList()
{
    CLL x = (CLL)malloc(sizeof(struct cll));
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

void displayList(CLL list)
{
    NODE p = list->head;

    if(list->head != NULL)
    {
        do
        {
            printf("%d->", p->data);
            p = p->next;
        } while (p != list->head);
    }
    printf("\n");
}

void addFirst(CLL list, data x)
{
    NODE new = createNode();
    new->data = x;

    if(list->head == NULL)
    {
        new->next = new;
        list->head = new;
    }
    else
    {
        NODE p = list->head;

        while(p->next != list->head)
            p = p->next;
        
        new->next = list->head;
        p->next = new;
        list->head = new;
    }
    list->size++;
}

void addLast(CLL list, data x)
{
    NODE new = createNode();
    new->data = x;

    if(list->head == NULL)
    {
        new->next = new;
        list->head = new;
    }
    else
    {
        NODE p = list->head;

        while(p->next != list->head)
            p = p->next;
        
        new->next = list->head;
        p->next = new;
    }
    list->size++;
}

void sort(CLL list)
{
    if(list->head == NULL)
        return;

    NODE p, lp = list->head;
    bool swap;
    do
    {
        p = list->head;
        swap = false;

        while(p->next != lp)
        {
            if(p->data > p->next->data)
            {    
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swap = true;
            }
            p = p->next;
        }
    } while (swap);
}

void reverse(CLL list)
{
    if(list->head == NULL || list->size == 1)
        return;

    int* temp = (int*)malloc(sizeof(int) * list->size);
    NODE p = list->head;
    int k = 0;

    do
    {
        *(temp + k) = p->data;
        k++;
        p = p->next;
    } while (p != list->head);

    int s = 0, e = list->size - 1;

    while(s < e)
    {
        int t = *(temp + s);
        *(temp + s) = *(temp + e);
        *(temp + e) = t;
        s++;
        e--;
    }

    p = list->head;
    k = 0;

     do
    {
        p->data = *(temp + k);
        k++;
        p = p->next;
    } while (p != list->head);
    
    free(temp);

    //Two pointer approach but has problem
    // NODE s = list->head, e = list->head;

    // //Ralocate the e to tail
    // while(e->next != list->head)
    //     e = e->next;
    
    // //Two pointer approach
    // while(s != e && s->next != e)
    // {
    //     int temp = s->data;
    //     s->data = e->data;
    //     e->data = temp;

    //     s = s->next;

    //     NODE prev = list->head;
    //     while(prev->next != e)
    //         prev = prev->next;
    //     e = prev;
    // }
}

CLL merge(CLL list1, CLL list2)
{
    CLL new = createList();

    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    if(list1->head == NULL && list2->head == NULL)
        return new;

    new->head = list1->head;
    NODE p = new->head;

    // Traverse to the end of list1
    while(p->next != list1->head)
        p = p->next;

    // Link the end of list1 to the head of list2
    p->next = list2->head;

    // Traverse to the end of list2
    NODE q = list2->head;
    while(q->next != list2->head)
        q = q->next;

    // Link the end of list2 to the head of the new list
    q->next = new->head;

    // Update the size of the new list
    new->size = list1->size + list2->size;

    // Set list1 and list2 to NULL and their sizes to 0
    list1->head = NULL;
    list1->size = 0;
    list2->head = NULL;
    list2->size = 0;

    return new;
}

void reverse(CLL list, int s, int e)
{
    int* temp = (int*)malloc(sizeof(int) * list->size);
    NODE p = list->head;
    
    int size = 0;
    do
    {
        *(temp + size) = p->data;
        size++;
        p = p->next;
    }while(p != list->head);
    
    while(s < e)
    {
        int t = *(temp + s);
        *(temp + s) = *(temp + e);
        *(temp + e) = t;
        s++;
        e--;
    }
    
    p = list->head;
    int i = 0;
    do
    {
        p->data = *(temp + i);
        i++;
        p = p->next;
    }while(p != list->head);
    free(temp);
}

void CLL_rotateRight(CLL list, int n)
{
	if(n == list->size || list->size < 2 || list->head == NULL)
	    return;
    if(n > list->size)
	    n %= list->size;
	
	int s = 0, e = list->size - 1;
	reverse_rot(list, s, e);
	reverse_rot(list, s, n - 1);
	reverse_rot(list, n, e);
}