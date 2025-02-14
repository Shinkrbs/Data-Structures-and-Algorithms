#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int Element;
#define EMPTY_STACK -1

typedef struct stack
{
    Element* storage;
    int top, capacity;
}*STACK;

STACK createStack(int capacity);
void freeStack(STACK x);

// Stack Operations
void Push(STACK x, Element data);
Element Pop(STACK x);
int isEmpty(STACK x);
int isFull(STACK x);
int peek(STACK x);

// Problems
void postfix_expression(STACK x, char *s);
void reverse(STACK x);
int isPalindrome(STACK x);
int valid_parenthesis(char l, char r);
int balancedParenthesis(char* s);
void sortStack(STACK x);

int main()
{
    //char *s = "823^/23*+51-";
    STACK x = createStack(100);

    // Push(x, 2);
    // printf("%d", peek(x));
    //postfix_expression(x, s);
    Push(x, 1);
    Push(x, 2);
    Push(x, 2);
    Push(x, 1);
    
    // printf("%d\n", isPalindrome(x));

    // printf("%d\n", Pop(x));
    // printf("%d\n", Pop(x));
    // printf("%d\n", Pop(x));
    // printf("%d\n", Pop(x));
    
    char *s = "(((())))";
    printf("%d\n", balancedParenthesis(s));
    
    freeStack(x);
    return 0;
}

STACK createStack(int capacity)
{
    STACK x = (STACK)malloc(sizeof(struct stack));
    x->storage = (Element*)malloc(sizeof(Element) * capacity);
    x->top = 0;
    x->capacity = capacity;
    return x;
}

void freeStack(STACK x)
{
    free(x->storage);
    free(x);
}

void Push(STACK x, Element data)
{
     if(!isFull(x))
        x->storage[x->top++] = data;
}

Element Pop(STACK x)
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

int peek(STACK x)
{
    return x->storage[x->top - 1];
}

void postfix_expression(STACK x, char *s)
{
    for(int i = 0; *(s + i) != '\0'; i++)
    {
        if(*(s + i) >= '0' && *(s + i) <= '9')
            Push(x, *(s + i) - '0');
        else
        {
            Element r = Pop(x), l = Pop(x);
            printf("%d %c %d\n", l, *(s + i), r);
            switch (*(s + i))
            {
                case '+': Push(x, l + r); break;
                case '-': Push(x, l - r); break;
                case '*': Push(x, l * r); break;
                case '/': Push(x, l / r); break;
                case '^': Push(x, (int)pow(l, r)); break;
                case '%': Push(x, l % r); break;
            }
        }
    }
    printf("%d", Pop(x));
}

void reverse(STACK x)
{
    STACK temp = createStack(x->capacity);
    STACK temp2 = createStack(x->capacity);
    
    while(!isEmpty(x))
        Push(temp, Pop(x));
    while(!isEmpty(temp))
        Push(temp2, Pop(temp));
    
    while(!isEmpty(temp2))
        Push(x, Pop(temp2));

    freeStack(temp);
    freeStack(temp2);
}

int isPalindrome(STACK x)
{
    STACK temp = createStack(x->capacity);
    int l = 0, r = 0, t;

    while(!isEmpty(x))
    {
        t = Pop(x);
        l = (l * 10) + t;
        Push(temp, t);
    }

    while(!isEmpty(temp))
    {
        t = Pop(temp);
        r = (r * 10) + t;
        Push(x, t);
    }

    freeStack(temp);    
    reverse(x);
    return l == r;
}

int valid_parenthesis(char l, char r)
{
    return (l == '(' && r == ')' || 
    l == '[' && r == ']' || 
    l == '{' && r == '}');
}

int balancedParenthesis(char* s)
{
    STACK temp = createStack(20);

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            Push(temp, s[i]);
        else
        {
            if(isEmpty(temp) || !valid_parenthesis(Pop(temp), s[i]))
            {
                freeStack(temp);
                return 0;
            }
        }
    }

    int res = isEmpty(temp) ? 1 : 0;
    freeStack(temp);
    return res;
}

void sortStack(STACK x) // Sort Ascending Order
{
    STACK auxStack = createStack(x->capacity);

    while (!isEmpty(x)) 
    {
        Element temp = Pop(x);

        while (!isEmpty(auxStack) && peek(auxStack) > temp)
            Push(x, Pop(auxStack));

        Push(auxStack, temp);
    }

    while (!isEmpty(auxStack))
        Push(x, Pop(auxStack));

    freeStack(auxStack);
}
