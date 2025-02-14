#include <stdio.h>
#include <stdlib.h>

int *findEven(int *array, int size, int *newSize);
int isEven(int num);

int main()
{
    int size = 7;
    int *a = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i ++)
        *(a + i) = size * (i + 1);

    for(int i = 0; i < size; i++)
        printf("%d, ", *(a + i));
    
    int newSize;
    int *evenArray = findEven(a, size, &newSize);
    
    printf("\n");
    for(int i = 0; i < newSize; i++)
        printf("%d, ", *(evenArray + i));

    free(a); 
    free(evenArray);
    return 0;
}

int *findEven(int *array, int size, int *newSize)
{
    int *temp = (int*)malloc(sizeof(int) * size);
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(isEven(*(array + i)))
        {
            *(temp + count) = *(array + i);
            count++;
        }
    }
    int *newArr= (int*)realloc(temp, sizeof(int) * count);
    *newSize = count;
    return newArr;
}

int isEven(int num)
{
    return num % 2 == 0;
}