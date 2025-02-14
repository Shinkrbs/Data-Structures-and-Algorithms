#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main()
{
     int size;
    scanf("%d", &size);
    int arr1[size];
    int arr2[size];

    for(int i = 0; i < size; i++)
        scanf("%d", &arr1[i]);
    for(int i = 0; i < size; i++)
        scanf("%d", &arr2[i]);

    for(int i = 0; i < size; i++)
    {
        bool flag = true;
        int currNum = arr1[i];
        for(int j = 0; j < size; j++)
        {
            int otherNum = arr2[j];
            if(currNum == otherNum)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("%d ", arr1[i]);
    }
    return 0;
}