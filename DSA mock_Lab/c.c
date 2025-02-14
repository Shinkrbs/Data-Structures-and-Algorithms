#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size, average, sum = 0;;
    scanf("%d", &size);
    int arr[size];

    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    for(int i = 0; i < size; i++)
        sum += arr[i];
    average = sum / size;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] < average)
            printf("%d ", arr[i]);
    }
    return 0;
}