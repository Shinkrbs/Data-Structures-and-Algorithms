#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    float* nums = (float*)malloc(sizeof(float) * n);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%f", &(*(nums + i)));

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(fabs(*(nums + j)) > fabs(*(nums + (j + 1))))
            {
                float temp = *(nums + (j + 1));
                *(nums + (j + 1)) = *(nums + j);
                *(nums + j) = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%.1f ", *(nums + i));
    free(nums);
    return 0;
}