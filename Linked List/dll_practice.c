#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
}*NODE;

typedef struct dll
{
    NODE head, tail;
    int size;
}*DLL;

NODE createNode();
DLL createList();

void displayList(DLL list);
void display_from_tail(DLL list);

void addLast(DLL list, int x);
void addFirst(DLL list, int x);
void insertPos(DLL list, int x, int pos);
void deletePos(DLL list, int pos);
void deleteMiddle(DLL list);
void sort(DLL list);
void reverse(DLL list);
void rev_for_rot(DLL list, NODE s, NODE e);
void rotate(DLL list, int k);
DLL remove_duplicates(DLL list);

int main()
{
    DLL x = createList();
    addFirst(x, 1);
    addFirst(x, 2);
    addFirst(x, 2);
    addFirst(x, 3);
    addFirst(x, 4);
    addFirst(x, 5);
    addFirst(x, 6);
    addFirst(x, 7);
    addFirst(x, 7);

    //reverse(x);
    displayList(x);
    // insertPos(x, 6, 2);
    // displayList(x);
    //deleteMiddle(x);
    // rotate(x, 7);
    // displayList(x);
    //display_from_tail(x);
    DLL new = remove_duplicates(x);
    displayList(new);

    //printf("%d", x->size);
    return 0;
}

DLL createList()
{
    DLL x = (DLL)malloc(sizeof(struct dll));
    x->head = x->tail = NULL;
    x->size = 0;
    return x;
}

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->next = x->prev = NULL;
    return x;
}

void displayList(DLL list)
{
    NODE p = list->head;
    while(p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void display_from_tail(DLL list)
{
    NODE p = list->tail;
    printf("NULL<-");
    while(p != NULL)
    {
        printf("%d<-", p->data);
        p = p->prev;
    }
    printf("\n");
}

void addLast(DLL list, int x)
{
    NODE new = createNode();
    new->data = x;

    // If list is empty and if one input is added, it will become both head and tail
    if(list->head == NULL && list->tail == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else 
    {
        NODE p = list->tail;
        new->prev = p;
        p->next = new;
        list->tail = new;
    }
    list->size++;
}

void addFirst(DLL list, int x)
{
    NODE new = createNode();
    new->data = x;

    if(list->head == NULL && list->tail == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        NODE p = list->head;
        new->next = p;
        p->prev = new;
        list->head = new;
    }
    list->size++;
}

void insertPos(DLL list, int x, int pos)
{
    //Special Case:
    //Empty or out of bounds
    if(list->head == NULL || pos > (list->size + 1) || pos <= 0)
        return;
    //Head 
    if(pos == 1)
    {
        addFirst(list, x);
        return;
    }
    //Tail
    if(pos == (list->size + 1))
    {
        addLast(list, x);
        return;
    }

    NODE new = createNode();
    new->data = x;
    NODE p = list->head;

    while((pos - 1) != 0)
    {
        p = p->next;
        pos--;
    }
    new->next = p;
    new->prev = p->prev;
    p->prev->next = new;
    p->prev = new;

    list->size++;
}

void deletePos(DLL list, int pos)
{
    //Special Case
    //List is empty or out of bounds
    if(list->head == NULL || pos > list->size || pos <= 0)
        return;
    NODE p = list->head;
    //Head 
    if(pos == 1)
    {
        if(p->next != NULL)
            p->next->prev = NULL;
        list->head = p->next;
        free(p);

        list->size--;
        return;
    }
    //Tail 
    if(pos == list->size)
    {
        p = list->tail;
        p->prev->next = NULL;
        list->tail = p->prev;
        free(p);

        list->size--;
        return;
    }

    while((pos - 1) != 0)
    {
        p = p->next;
        pos--;
    }
    
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);

    list->size--;
}

void deleteMiddle(DLL list)
{
    if(list->head == NULL || list->size < 3)
        return;  
    NODE p = list->head;  
    //Relate the problem to finding the median of a list
    //Case where the size is odd
    if(list->size % 2 != 0)
    {
        int pos = (list->size + 1) / 2;

        while(pos != 1)
        {
            p = p->next;
            pos--;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        list->size--;
        return;
    }
    else //Case where the size is even
    {
        int pos = list->size / 2;

        while(pos != 1)
        {
            p = p->next;
            pos--;
        }

        p->prev->next = p->next->next;
        p->next->prev = p->prev;
        free(p);
        list->size -= 2;
    }
}

void sort(DLL list)
{
    if (list->head == NULL)
        return;

    NODE p, lp = NULL;
    bool swapped;

    do
    {
        swapped = false;
        p = list->head;

        while (p->next != lp)
        {
            if (p->data > p->next->data)
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

void reverse(DLL list)
{
    if(list->head == NULL || list->size < 2)
        return;
    // Try two pointer approach
    NODE l = list->head, r = list->tail;

    while(l != r && l->prev != r)
    {
        int temp = l->data;
        l->data = r->data;
        r->data = temp;
        l = l->next;
        r = r->prev;
    }
}

void rev_for_rot(DLL list, NODE s, NODE e)
{
    if(list->head == NULL || list->size < 2)
        return;

    while(s != e && s->prev != e)
    {
        int temp = s->data;
        s->data = e->data;
        e->data = temp;
        s = s->next;
        e = e->prev;
    }
}

void rotate(DLL list, int k)
{
    //Special Case:
    //If rotation is greater than the size of the linke list
    //If rotation is equal to the size number
    if(k > list->size)
        k %= list->size;
    if(k == list->size)
        return;

    NODE s = list->head, e = list->tail;
    rev_for_rot(list, s, e);

    int temp = k - 1;
    e = list->head;
    while(temp != 0)
    {
        e = e->next;
        temp--;
    }
    rev_for_rot(list, s, e);

    e = list->tail;
    temp = k - 1;
    while(temp >= 0)
    {
        s = s->next;
        temp--;
    }
    rev_for_rot(list, s, e);
}

DLL remove_duplicates(DLL list)
{
    int *temp = (int*)malloc(sizeof(int) * list->size);
    int size = 0;
    NODE p = list->head;

    //Return if list is empty
    if(list->head == NULL || list->tail == NULL)
        return list;

    while(p != NULL)
    {
        bool isDuplicate = false;
        for(int i = 0; i < size; i++)
        {
            if(*(temp + i) == p->data)
            {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate)
        {
            *(temp + size) = p->data;
            size++;
        }
        p = p->next;
    }

    DLL x = createList();
    p = x->head;

    for(int i = 0; i < size; i++)
        addLast(x, *(temp + i));

    free(temp);
    return x;
}