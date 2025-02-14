#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* createStorage(int n);
int* u(int *set1, int* set2);
int display(int *arr);
bool isPresent(int* arr, int index, int num);

int main()
{
    int* x = createStorage(5);
    x[1] = 1; x[2] = 5; x[3] = 7; x[4] = 9; x[5] = 10;
    display(x);

    int *y = createStorage(5);
    y[1] = 3; y[2] = 5; y[3] = 7; y[4] = 1; y[5] = 6;
    display(y);

    display(u(x, y));

    free(x);
    free(y);
    return 0;
}

int* createStorage(int n)
{
    int *arr = (int*)malloc(sizeof(int) * n);
    *(arr) = n;
    return arr;
}

int display(int *arr)
{
    for(int i = 1; i <= *(arr); i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

int* u(int* set1, int* set2)
{
    int size1 = *(set1);
    int size2 = *(set2);
    int *new = createStorage(size1 + size2);
    int index = 1;
    for(int i = 1; i <= size1; i++)
    {
        *(new + index) = *(set1 + i);
        index++;
    }
    
    for(int i = 1; i <= size2; i++)
    {
        if(!isPresent(new, index, *(set2 + i)))
        {
            *(new + index) = *(set2 + i);
            index++;
        }
    }
    
    for(int i = 1; i < index; i++)
    {
        for(int j = 1; j < index - i; j++)
        {
            if(*(new + j) > *(new + (j + 1)))
            {
                int temp = *(new + j);
                *(new + j) = *(new + (j + 1));
                *(new + (j + 1)) = temp;
            }
        }
    }

    int* u = createStorage(index - 1);
    for(int i = 1; i <= index; i++)
        *(u + i) = *(new + i);
    free(new);
    return u;
}   

bool isPresent(int* arr, int index, int num)
{
    for(int i = 1; i < index; i++)
        if(*(arr + i) == num) return true;
    return false;
}