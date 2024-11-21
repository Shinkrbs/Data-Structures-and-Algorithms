#include <stdio.h>
#include <stdlib.h>

int main()
{
    void* x;
    void* arr1 = (void*)malloc(sizeof(void*) * 4);
    void* arr2 = (void*)malloc(sizeof(void*) * 2);
    void* arr3 = (void*)malloc(sizeof(void*) * 5);
    void* arr4 = (void*)malloc(sizeof(void*) * 6);
    void* arr5 = (void*)malloc(sizeof(void*) * 8);

    x = arr1;
    
    // arr1
    *((int*)arr1) = 3;
    *((void**)arr1 + 1) = arr2;
    *((void**)arr1 + 2) = NULL;
    *((void**)arr1 + 3) = arr4;

    // arr2
    *((int*)arr2) = 1;
    *((void**)arr2 + 1) = arr3;

    // arr3
    *((int*)arr3) = 4;
    *((void**)arr3 + 1) = arr1;
    *((void**)arr3 + 2) = NULL;
    *((void**)arr3 + 3) = arr4;
    *((void**)arr3 + 4) = arr5;

    // arr4
    *((int*)arr4) = 5;
    *((void**)arr4 + 1) = *((void**)arr4 + 2) = *((void**)arr4 + 3) = 
        *((void**)arr4 + 5) = NULL;
    *((void**)arr4 + 4) = arr5;

    // arr5
    *((int*)arr5) = 7;
    *((void**)arr5 + 1) = *((void**)arr5 + 2) = *((void**)arr5 + 3) =
        *((void**)arr5 + 4) = *((void**)arr5 + 5) = *((void**)arr5 + 6) = NULL;
    *((void**)arr5 + 7) = arr2;

    // Display Values
    printf("%d\n", *((int*)x));
    printf("%d\n", *((int*)(*((void**)x + 1))));
    printf("%d\n", *((int**)(*((void**)(*((void**)x + 1))+ 1))));
    printf("%d\n", *((int**)(*((void**)(*((void**)(*((void**)x + 1))+ 1))+ 3))));
    printf("%d\n", *((int*)(*((void**)(*((void**)(*((void**)x + 1))+ 1))+ 4))));

    // Accessing arr5 though arr1
    printf("%d\n", *((int*)(*((void**)x + 3))));
    printf("%d\n", *((int**)(*((void**)(*((void**)x + 3))+ 4))));

    // Accessing arr4 through arr3
    printf("%d\n", *((int**)(*((void**)(*((void**)(*((void**)x + 1))+ 1))+ 3))));

    //Free
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    return 0;
}