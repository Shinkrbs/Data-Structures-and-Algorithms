#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct node
{
    int data;
    struct node* next;
}*NODE;

typedef struct cll
{
    NODE tail;
    int size;
}*CLL;

NODE createNode();
CLL createCLL();

void addFirst(CLL list, Element data);
void addLast(CLL list, Element data);
void dispList(CLL list);

void rot_left(CLL list, int k);
void rev(int* x, int l, int r);
int check_three_cons_n(CLL list, Element target);
void rem_duplicates(CLL list);
int isDuplicate(int* temp, Element data, int size);

int main()
{
    CLL list = createCLL();
    addFirst(list, 10);
    addFirst(list, 10);
    addFirst(list, 10);
    addFirst(list, 20);
    addFirst(list, 5);

    dispList(list);
    rot_left(list, 1);
    dispList(list);
    printf("%d\n", check_three_cons_n(list, 10));
    rem_duplicates(list);
    dispList(list);
    return 0;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->next = NULL;
    return x;
}

CLL createCLL()
{
    CLL x = (CLL)malloc(sizeof(struct cll));
    x->tail = NULL;
    x->size = 0;
    return x;
}

void addFirst(CLL list, Element data)
{
    NODE new = createNode();
    new->data = data;

    if(list->tail == NULL)
    {
        list->tail = new;
        new->next = new;
    }
    else
    {
        NODE p = list->tail->next;
        list->tail->next = new;
        new->next = p;
    }
    list->size++;
}

void addLast(CLL list, Element data)
{
    NODE new = createNode();
    new->data = data;

    if(list->tail == NULL)
    {
        list->tail = new;
        new->next = new;
    }
    else
    {
        new->next = list->tail->next;
        list->tail->next = new;
        list->tail = new;
    }
    list->size++;
}

void dispList(CLL list)
{
    NODE p = list->tail->next;

    do
    {
        printf("%d-> ", p->data);
        p = p->next;
    } while (p != list->tail->next);
    printf("\n");
}

void rot_left(CLL list, int k)
{
    if(list->tail == NULL || k == 0) return;

    int* temp = (int*)malloc(sizeof(int) * list->size);

    k = k % list->size;
    if(k == 0) return;

    int i = 0;
    NODE p = list->tail->next;

    do
    {
        temp[i] = p->data;
        i++;
        p = p->next;
    } while (p != list->tail->next);
    
    // Rotating
    rev(temp, 0, list->size - 1);
    rev(temp, 0, list->size - k - 1);
    rev(temp, list->size - k, list->size - 1);

    // Add Values Back
    p = list->tail->next; 
    for (i = 0; i < list->size; i++, p = p->next)
        p->data = temp[i];
    free(temp);        
}

void rev(int* x, int l, int r)
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

int check_three_cons_n(CLL list, Element target)
{
    NODE p = list->tail->next;
    int ctr = 0;
    do
    {
        if(p->data == target)
        {
            ctr++;
            if(ctr == 3)
                return 1;
        }
        else
            ctr = 0;
        p = p->next;
    } while (p != list->tail->next);
    return 0;    
}

void rem_duplicates(CLL list)
{
    int* temp = (int*)malloc(sizeof(int) * list->size);
    int ctr = 0;
    NODE p = list->tail->next;

    // Check the duplicates and store it in the temp array
    do
    {
        if(!isDuplicate(temp, p->data, ctr))
        {
            temp[ctr] = p->data;
            ctr++;
        }
        p = p->next;
    } while (p != list->tail->next);
    
    CLL new = createCLL();
    for(int i = 0; i < ctr; i++)
        addLast(new, temp[i]);
    
    // Redirect to point into the new array
    // You need to free the list tho first lol
    list->tail = new->tail;
    list->size = new->size;

    free(temp);
}

int isDuplicate(int* temp, Element data, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(temp[i] == data)
            return 1;
    }
    return 0;
}