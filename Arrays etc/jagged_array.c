#include <stdio.h>
#include <stdlib.h>

// Practice jagged arrays 
int main()
{
    int len[7] = {9, 0, 3, 2, 0, 2, 4};
    int **arr = (int**)malloc(sizeof(int*) * (sizeof(len) / sizeof(int)));

    // Dynamically Allocating Memory for each index
    for(int i = 0; i < (sizeof(len) / sizeof(int)); i++)
    {
        *(arr + i) = (int*)malloc(sizeof(int) * len[i]);
        printf("Allocated %d Length of Memory to Index %p\n", len[i], arr[i]);
    }

    // Assigning Values 
    // arr[0]
    *(*(arr)) = 2;
    *(*(arr) + 1) = *(*(arr)) + 1;
    *(*(arr) + 2) =  *(*(arr) + 1) + 2;
    *(*(arr) + 3) = *(*(arr) + 2) + 2;
    *(*(arr) + 4) = *(*(arr) + 3) + 4;   
    *(*(arr) + 5) = *(*(arr) + 4) + 2;
    *(*(arr) + 6) = *(*(arr) + 5) + 4;
    *(*(arr) + 7) = *(*(arr) + 6) + 2;
    *(*(arr) + 8) = *(*(arr) + 7) + 4;
    // arr[1] is empty
    // arr[2]
    *(*(arr + 2)) = 30;
    *(*(arr + 2) + 1) = *(*(arr + 2)) + 30;
    *(*(arr + 2) + 2) = *(*(arr + 2) + 1) + 30;;
    // arr[3]
    *(*(arr + 3)) = 100;
    *(*(arr + 3) + 1) = *(*(arr + 3)) + 100;
    // arr[4] is empty
    // arr[5] 
    *(*(arr + 5)) = 77;
    *(*(arr + 5) + 1) = (*(*(arr + 5)) * 10) + 7;
    // arr[6]
    *(*(arr + 6)) = 2;
    *(*(arr + 6) + 1) = *(*(arr + 6)) + *(*(arr + 6));
    *(*(arr + 6) + 2) = *(*(arr + 6) + 1) + *(*(arr + 6));
    *(*(arr + 6) + 3) = *(*(arr + 6) + 2) + *(*(arr + 6));

    

    // Printing Values
    printf("\n");
    for(int i = 0; i < (sizeof(len) / sizeof(int)); i++)
    {
            for(int j = 0; j < len[i]; j++)
                printf("%d\n", *(*(arr + i) + j));
            printf("\n");
    }

     // Freeing Memory 
    for(int i = 0; i < (sizeof(len) / sizeof(int)); i++)
        free(*(arr + i));
    free(arr);
    
    return 0; 
}