//You can add additional definitions but don't delete any default definitions

typedef struct node
{
    STUDENT student;
    struct node* next;
}*NODE;

typedef struct _priorityqueue
{
	//define this structure on your own here
	NODE front;
} * PRIORITYQUEUE;

PRIORITYQUEUE createPriorityQueue();
void enqueue(PRIORITYQUEUE pq, STUDENT student);
void dequeue(PRIORITYQUEUE pq);
STUDENT getFront(PRIORITYQUEUE pq);
int isEmpty(PRIORITYQUEUE pq);
int helper(STUDENT a, STUDENT b);

NODE createNode(STUDENT student)
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->student = student;
    x->next = NULL;
    return x;
}

PRIORITYQUEUE createPriorityQueue()
{
	//TODO: initialize a priority queue dynamic structure and return its reference
	PRIORITYQUEUE x = (PRIORITYQUEUE)malloc(sizeof(struct _priorityqueue));
    x->front = NULL;
	return x; 
}

int helper(STUDENT a, STUDENT b) 
{
    // Compare GPA
    if (a->GPA != b->GPA) 
        return (a->GPA > b->GPA) ? -1 : 1;

    // Compare lowest grades
    float aLowest = fmin(fmin(a->sci_grade, a->mat_grade), a->eng_grade);
    float bLowest = fmin(fmin(b->sci_grade, b->mat_grade), b->eng_grade);
    if (aLowest != bLowest) 
        return (aLowest > bLowest) ? -1 : 1;

    // Compare highest grades
    float aHighest = fmax(fmax(a->sci_grade, a->mat_grade), a->eng_grade);
    float bHighest = fmax(fmax(b->sci_grade, b->mat_grade), b->eng_grade);
    if (aHighest != bHighest) 
        return (aHighest > bHighest) ? -1 : 1;

    // Compare by lastname
    int lnameComparison = strcmp(a->lastname, b->lastname);
    if (lnameComparison != 0) 
        return lnameComparison;

    // Compare by firstname
    return strcmp(a->firstname, b->firstname);
}

void enqueue(PRIORITYQUEUE pq, STUDENT student)
{
	//TODO: enqueue the student in pq following the prioritization rules stated above
	NODE new = createNode(student);
	
	if(pq->front == NULL)
    {
        pq->front = new;
        return;
    }
    
    if(helper(student, pq->front->student) < 0)
    {
        new->next = pq->front;
        pq->front = new;
        return;
    }
    
    NODE p = pq->front;
    while(p->next != NULL && helper(student, p->next->student) >= 0)
        p = p->next;
    new->next = p->next;
    p->next = new;
    return;
}

void dequeue(PRIORITYQUEUE pq)
{
	//TODO: remove the student data at the front of the pq
	if(pq->front == NULL)
	    return; 
	NODE temp = pq->front;
	pq->front = pq->front->next;
	free(temp);
}

STUDENT getFront(PRIORITYQUEUE pq)
{
	//TODO: return the reference of the student data at the front of the pqs
	return pq->front->student;
}

int isEmpty(PRIORITYQUEUE pq)
{
	//TODO: return 1 if the pq is empty and 0 otherwise
	return pq->front == NULL;
}