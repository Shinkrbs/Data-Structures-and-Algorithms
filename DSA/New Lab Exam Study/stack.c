#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int element;
#define EMPTY -1

typedef struct stack
{
    element* storage;
    int top, capacity;
}*STACK;

STACK createStack(int capacity)
{
    STACK x = (STACK)malloc(sizeof(struct stack));
    x->storage = (element*)malloc(sizeof(element) * capacity);
    x->capacity = capacity;
    x->top = 0;
    return x;
}

void freeStack(STACK x)
{
    free(x->storage);
    free(x);
}

int isEmpty(STACK x)
{
    return x->top == 0;
}

int isFull(STACK x)
{
    return x->top == x->capacity;
}

void push(STACK x, element data)
{
    if(!isFull(x))
        x->storage[x->top++] = data;
}

element pop(STACK x)
{
    if(!isEmpty(x))
        return x->storage[--(x->top)];
    else   
        return EMPTY;
}

element peek(STACK x)
{
    return x->storage[x->top - 1];
}

void binary(element number)
{
    if(number == 0) return;

    STACK bin = createStack(100);
    while(number > 0)
    {
        push(bin, number % 2);
        number /= 2;
    }

    while(!isEmpty(bin))
        printf("%d", pop(bin));
    printf("\n");
    freeStack(bin);
}

// Valid Parenthesis
int isValid(char l, char r)
{
    return l == '(' && r == ')' || l == '[' && r == ']' || l == '{' && r == '}';
}

bool parenthesis(char* s)
{
    STACK p = createStack(50);
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(p, s[i]);
        else
        {
            if(isEmpty(p) || !isValid(pop(p), s[i]))
                break;
        }
    }
    bool res = isEmpty(p) ? true : false;
    freeStack(p);
    return res;
}

bool operator(char s)
{
    return s == '+' || s == '-' || s == '*' || s == '/';   
}

void rev_arr(int* arr, int n)
{
    STACK rev = createStack(n);
    for(int i = 0; i < n; i++)
        push(rev, arr[i]);
    for(int i = 0; i < n; i++)
        arr[i] = pop(rev);
    freeStack(rev);
}

// void addChar(char *s, char r)
// {
//     int l = strlen(s);
//     s[l] = r;
//     s[l + 1] = '\0';
// }

// char* postfix_prefix(char* s)
// {
//     STACK p = createStack(100);
//     for(int i = 0; s[i] != '\0'; i++)
//     {
//         if(operator(s[i]))
//         {
//             char* l = pop(p);
//             char* r = pop(p);
//             addChar(l, s[i]);
//             addChar(l, r);
//             push(p, l);
//         }
//         else   
//             push(p, s[i]);
//     }
//     char* res = pop(p);
//     return res;
// }

void sort_arr(int* arr, int n)
{
    STACK inpStack = createStack(n);
    STACK tempStack = createStack(n);

    for(int i = 0; i < n ; i++)
        push(inpStack, arr[i]);

    while(!isEmpty(inpStack))
    {
        int curr = pop(inpStack);
        while(!isEmpty(tempStack) && peek(tempStack) > curr)
            push(inpStack, pop(tempStack));
        push(tempStack, curr);
    }

    for(int i = n -1 ; i >= 0; i--)
        arr[i] = pop(tempStack);
    
    freeStack(inpStack);
    freeStack(tempStack);
}

STACK sort(STACK x)
{
    STACK temp = createStack(x->capacity);
    while(!isEmpty(x))
    {
        element t = pop(x);
        while(!isEmpty(temp) && peek(temp) > t)
            push(x, pop(temp));
        push(temp, t);
    }
    freeStack(x);
    return temp;
}

void disp(STACK x)
{
    while(!isEmpty(x))
        printf("%d ", pop(x));
    printf("\n");
}

STACK rev(STACK x)
{
    STACK temp = createStack(x->capacity);
    while(!isEmpty(x))
        push(temp, pop(x));
    return temp;
}

int octal(int n)
{
    if( n == 0) return 0;
    STACK x = createStack(100);

    while(n > 0)
    {
        push(x, n % 8);
        n /= 8;
    }
    int result = 0;
    while(!isEmpty(x))
    {
        result *= 10;
        result += pop(x);
    }
    return result;
}

int main()
{
    //binary(121);

    char* s = "{}([))";
    (parenthesis(s)) ? printf("true\n") : printf("false\n");

    int arr[5] = {5, 4, 3, 2, 1};
    sort_arr(arr, 5);

    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    STACK x = createStack(5);
    push(x, 5);
    push(x, 4);
    push(x, 3);
    push(x, 2);
    push(x, 1);

    x = sort(x);
    disp(x);
    freeStack(x);

    printf("Octal: %d", octal(1211));
    return 0;
}