#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// #define N 4 // Number of people

// // Function to check if person A knows person B
// bool knows(int A, int B) {
//     // This is a stub function. Replace it with the actual implementation.
//     // For example, this could be a matrix or a list where the knowledge relationship is stored.
//     // For simplicity, let's assume a hardcoded matrix:
//     int M[N][N] = {
//         {0, 0, 0, 0},
//         {1, 0, 0, 0},
//         {0, 1, 0, 1},
//         {0, 0, 1, 0}
//     };
//     return M[A][B];
// }

// // Function to find the celebrity
// int findCelebrity() {
//     int candidate = 0;
    
//     // Step 1: Find the candidate
//     for (int i = 1; i < N; i++) {
//         if (knows(candidate, i)) {
//             candidate = i;
//         }
//     }

//     // Step 2: Verify the candidate
//     for (int i = 0; i < N; i++) {
//         if (i != candidate) {
//             if (knows(candidate, i) || !knows(i, candidate)) {
//                 return -1; // No celebrity
//             }
//         }
//     }

//     return candidate;
// }

// int main() {
//     int celebrity = findCelebrity();
    
//     if (celebrity == -1) {
//         printf("There is no celebrity.\n");
//     } else {
//         printf("The celebrity is person %d.\n", celebrity);
//     }

//     return 0;
// }

// Own implementation
// Using Pointers
bool knows(int **array, int i, int j);
int findCelebrity(int **array, int size);

int main()
{
    int **array = (int**)malloc(sizeof(int*) * 4);
    
    for(int i = 0; i < 4; i++)
        *(array + i) = (int*)malloc(sizeof(int));
    
    // Input Values to 2d array
    *(*(array)) =  *(*(array) + 1) = *(*(array) + 2) = *(*(array) + 3) = 0;
    *(*(array + 1)+ 1) =  *(*(array + 1) + 2) = *(*(array + 1) + 3) = 0;
    *(*(array + 2) + 1) =  *(*(array + 2) + 2) = *(*(array + 2) + 3) = 0;
    *(*(array + 3) + 1) =  *(*(array + 3) + 2) = *(*(array + 3) + 3) = 0;
    *(*(array + 1)) = 1;
    *(*(array + 2)) = 1;
    *(*(array + 3)) = 1;

    /*{{0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, , 0, 0}
    }*/

   // Print to test the array
    for(int i = 0; i < 4; i++)
    {
            for(int j = 0; j < 4; j++)
                printf("%d ", *(*(array+ i) + j));
            printf("\n");
    }

    //  Print Values
    if(findCelebrity(array, 4) == -1)
        printf("\nThere is No Celebrity!");
    else
        printf("\nCelebrity is Person %d", findCelebrity(array, 4));


   for(int i = 0; i < 4; i++)
        free(*(array + i));
    free(array);
}

bool knows(int **array, int i, int j)
{
    return (*(*(array + i) + j)) == 1 ? true : false;
}

int findCelebrity(int **array, int size)
{
    int candidate = 0;

    // Find candidate
    for(int i = 1; i < size; i++)
    {
        if(knows(array, candidate, i))
            candidate = i;
    }

    // Verify Candidate
    for(int i = 0; i < size; i++)
    {
        if(i != candidate && (knows(array, candidate, i) || !knows(array, i, candidate)))
        {
              return -1;
        }
    }

    return candidate + 1;
}