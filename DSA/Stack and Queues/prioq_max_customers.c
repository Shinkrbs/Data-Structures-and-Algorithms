#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

typedef struct event{
    int time, type;
}*EVENT;

typedef EVENT Element;

typedef struct pqnode{
    Element data;
    struct pqnode* next;
}*PQNODE;

typedef struct pqueue{
    PQNODE front, rear;
    int size;
}*PQUEUE;

PQUEUE createPQueue(){
    PQUEUE my = (PQUEUE)malloc(sizeof(struct pqueue));
    my->size = 0;
    my->front = my->rear = NULL;
    return my;
}

Element createEvent(int time, int type){
    Element newEvent = (Element)malloc(sizeof(struct pqueue));
    newEvent->type = type;
    newEvent->time = time;
    return newEvent;
}

PQNODE createPQNODE(Element data){
    PQNODE my = (PQNODE)malloc(sizeof(struct pqnode));
    my->data = data;
    my->next = NULL;
    return my;
}

int isEmpty(PQUEUE pq){
    return pq->size == 0;
}

int compareEvents(EVENT a, EVENT b){
    if (a->time != b->time)
        return a->time - b->time;
    return a->type - b->type;
}

Element dequeue(PQUEUE pq){
    if(isEmpty(pq))
        return NULL; //change
    PQNODE p = pq->front;
    Element data = p->data;
    if (pq->size == 1)
        pq->rear = pq->front = NULL;
    else
        pq->front = p->next;
    free(p);
    pq->size--;
    return data;
}

void enqueue(PQUEUE pq, int time, int type){
    EVENT newEvent = createEvent(time,type);
    PQNODE newNode = createPQNODE(newEvent);
    if (isEmpty(pq) || compareEvents(pq->front->data,newEvent) > 0){
        newNode->next = pq->front;
        pq->front = newNode;
        if (!pq->rear)
            pq->rear = newNode;
    } else {
        PQNODE p = pq->front;
        for (;p->next && compareEvents(p->data,newEvent) < 0; p = p->next);
            newNode->next = p->next;
        p->next = newNode;
        if (!newNode->next)
            pq->rear = newNode;
    }
    pq->size++;
}

Element getFront(PQUEUE pq){
    return isEmpty(pq) ? NULL : pq->front->data;
}

Element getRear(PQUEUE pq){
    return isEmpty(pq) ? NULL : pq->rear->data;
}

int queueCount(PQUEUE pq){
    return pq->size;
}

void freeQueue(PQUEUE pq){
    PQNODE p = NULL;
    while (pq->front){
        p = pq->front;
        pq->front = p->next;
        free(p);
    }
    free(pq);
}

int maxCustomers(int arr[], int dep[], int n){
    PQUEUE pq = createPQueue();
    int curr = 0, max = 0;
    for (int i = 0; i < n; i++){
        enqueue(pq,arr[i],1);
        enqueue(pq,dep[i],-1);
    }
    while(!isEmpty(pq)){
        EVENT event = dequeue(pq);
        if (event->type == 1){
            curr++;
            max = max > curr ? max : curr;
        } else
            curr--;
        free(event);
    }
    free(pq);
    return max;
}

int main() {
    int arr[] = {6,2,4,10,4,7,9};
    int dep[] = {13,7,15,17,10,11,17};
    printf("%d",maxCustomers(arr,dep,7));
    return 0;
}