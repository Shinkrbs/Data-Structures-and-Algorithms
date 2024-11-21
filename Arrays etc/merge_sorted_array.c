#include <stdio.h>
#include <stdlib.h>

int mergeSortedArray(int* a1, int* a2, int s1, int s2, int** p);

int main() 
{
    int *result = NULL;
    
    // Test Case 1: Merge two sorted arrays of positive integers
    int a1[] = {1, 3, 5, 7};
    int a2[] = {2, 4, 6, 8};
    int size1 = sizeof(a1) / sizeof(a1[0]);
    int size2 = sizeof(a2) / sizeof(a2[0]);
    
    int mergedSize = mergeSortedArray(a1, a2, size1, size2, &result);
    
    printf("Merged Array (Test Case 1): ");
    for(int i = 0; i < mergedSize; i++) 
        printf("%d ", result[i]);

    printf("\n");
    free(result); // Free the memory allocated by mergeSortedArray

    // Test Case 2: Merge two empty arrays
    int empty1[] = {};
    int empty2[] = {};
    
    mergedSize = mergeSortedArray(empty1, empty2, 0, 0, &result);
    
    printf("Merged Array (Test Case 2): ");
    for(int i = 0; i < mergedSize; i++) 
        printf("%d ", result[i]);
    printf("\n");
    free(result);

    // Test Case 3: Merge one empty array and one non-empty array
    int a3[] = {10, 20, 30};
    
    mergedSize = mergeSortedArray(empty1, a3, 0, 3, &result);
    
    printf("Merged Array (Test Case 3): ");
    for(int i = 0; i < mergedSize; i++)
        printf("%d ", result[i]);

    printf("\n");
    free(result);

    // Test Case 4: Merge two arrays with negative integers
    int a4[] = {-5, -3, -1};
    int a5[] = {-4, -2, 0, 1};
    
    mergedSize = mergeSortedArray(a4, a5, 3, 4, &result);
    
    printf("Merged Array (Test Case 4): ");
    for(int i = 0; i < mergedSize; i++) 
        printf("%d ", result[i]);
    
    printf("\n");
    free(result);

    return 0;
}

int mergeSortedArray(int* a1, int* a2, int s1, int s2, int** p)
{
    int ctr = 0;
    int *temp = (int*)malloc(sizeof(int) * (s1 + s2));
    
    for(int i = 0; i < s1; i++)
    {
        *(temp + i) = *(a1 + i);
        ctr++;
    }
    
    for(int i = 0; i < s2; i++)
        *(temp + (ctr + i)) = *(a2 + i);
    
    //Sort
    for(int i = 0; i < (s1 + s2) - 1; i++)
    {
        for(int j = 0; j < (s1 + s2) - i - 1; j++)
        {
            if(*(temp + j) > *(temp + (j + 1)))
            {
                int temp_num = *(temp + j);
                *(temp + j) = *(temp + (j + 1));
                *(temp + (j + 1)) = temp_num;
            }
        }
    }
    *p = temp;
    return s1 + s2;
}