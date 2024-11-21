#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr = (int**)malloc(sizeof(int*) * 5); // Main Dynamic Memory
    
    // Allocating Memory to each Inner Array
    for(int i = 0; i < 5; i++)
        *(arr + i) = (int*)malloc(sizeof(int) * (i + 1));
        //printf("%d, %p\n", i, arr + i);
    
    // Assigning Values to each Index
    for(int i = 0; i < 5; i++)
    {
        int num = 0;
        for(int j = 0; j <= i; j++)
            *(*(arr + i) + j) = num++;
    }   

    // Printing Values
    for(int i = 0; i < 5; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j <= i; j++)
            printf("%d, ", *(*(arr + i) + j));
        printf("\n");
    }

    // Swap the index 1 and index 4 of the jagged array
    int *temp = *(arr + 4);
    *(arr + 4) = *(arr + 1);
    *(arr + 1) = temp;

    // Print 
    // Printing Values
    printf("\n");
    int len[5] = {1, 5, 3, 4, 2};
    for(int i = 0; i < 5; i++)
    {
        printf("[%d] ", len[i] - 1);
        for(int j = 0; j <= len[i] - 1; j++)
            printf("%d, ", *(*(arr + i) + j));
        printf("\n");
    }

    // Freeing Used Memory
    for(int i = 0; i < 5; i++)
        free(*(arr + i));
    free(arr);
    return 0;
}