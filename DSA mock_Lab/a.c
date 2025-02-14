#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, a;
    int sum = 0;
    scanf("%d %d", &n, &a);
    int arr[n][a];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < a; j++)
            scanf("%d", &arr[i][j]);
    }

    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[j][i] != 0)
                sum += arr[j][i];
            else
                break;
        }
    }
    printf("%d", sum);
    return 0;
}