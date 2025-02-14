#include <stdio.h>
#include <stdlib.h>

void sort(int* x, int size);
int* storage(int capacity);
int* merge(int* x, int* y, int size_x, int size_y);
void disparr(int* x, int size);

int main()
{
    int size_x = 5;
    int size_y = 3;

    // Create two arrays
    int* array1 = storage(size_x);
    int* array2 = storage(size_y);

    // Initialize the arrays with test data
    array1[0] = 5;
    array1[1] = 2;
    array1[2] = 9;
    array1[3] = 1;
    array1[4] = 4;

    array2[0] = 8;
    array2[1] = 3;
    array2[2] = 7;

    // Display Array1
    printf("Array 1: ");
    disparr(array1, size_x);

    // Display Array2
    printf("Array 2: ");
    disparr(array2, size_y);

    // Merge the two arrays
    int* mergedArray = merge(array1, array2, size_x, size_y);

    // Print the sorted merged array
    printf("Sorted merged array: ");
    disparr(mergedArray, size_x + size_y);
    
    // Free allocated memory
    free(array1);
    free(array2);
    free(mergedArray);
    return 0;
}

void sort(int* x, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(x[i] > x[i + 1])
            {
                int temp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = temp;
            }
        }
    }
}

int* storage(int capacity)
{
    int* x = (int*)malloc(sizeof(int) * capacity);
    return x;
}

int* merge(int* x, int* y, int size_x, int size_y)
{
    int* z = storage(size_x + size_y);
    int ctr = 0;

    for(int i = 0; i < size_x; i++, ctr++)
        z[ctr] = x[i];
    for(int i = 0; i < size_y; i++, ctr++)
        z[ctr] = y[i];
    sort(z, size_x + size_y);
    return z;
}

void disparr(int* x, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", x[i]);
    printf("\n");
}