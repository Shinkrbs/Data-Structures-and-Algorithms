#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Element;
#define EMPTY_STACK -1

typedef struct stack
{
    Element* storage;
    int top, capacity;
}*STACK;

STACK createStack(int capacity);
void freeStack(STACK x);

void push(STACK x, Element data);
Element pop(STACK x);
int isEmpty(STACK x);
int isFull(STACK x);
Element Peek(STACK x);

/*Problem: You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

- Every open bracket is closed by the same type of close bracket.
- Open brackets are closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
- Return true if s is a valid string, and false otherwise.*/

bool isValid_Parenthesis(char* s);
int isValid_P(char l, char r);

int main()
{
    char *s = "{}([))";
    (isValid_Parenthesis(s)) ? printf("true") : printf("false");

    return 0;
}

STACK createStack(int capacity)
{
    STACK x = (STACK)malloc(sizeof(struct stack));
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

void push(STACK x, Element data)
{
    if(!isFull(x))
        x->storage[x->top++] = data;
}

Element pop(STACK x)
{
    return (!isEmpty(x)) ? x->storage[--(x->top)] : EMPTY_STACK;
}

int isEmpty(STACK x)
{
    return x->top == 0;
}

int isFull(STACK x)
{
    return x->top == x->capacity;
}

Element Peek(STACK x)
{
    return x->storage[x->top - 1];
}

int isValid_P(char l, char r)
{
    return l == '(' && r == ')' || l == '[' && r == ']' || l == '{' && r == '}';
}

bool isValid_Parenthesis(char* s)
{
    STACK temp = createStack(20);
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(temp, s[i]);
        else
        {
            if(isEmpty(temp) || !isValid_P(pop(temp), s[i]))
                break;
        }
    }

    bool result = isEmpty(temp) ? true : false;
    freeStack(temp);
    return result;
}