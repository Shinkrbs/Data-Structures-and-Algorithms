#include <stdio.h>
#include <stdlib.h>


float mean(long long int* arr, int size);
long long int median(long long int* arr, int size);
long long int mode(long long int* arr, int size);

int main()
{
    int n;
    scanf("%d", &n);
    long long int *nums = (long long int*)malloc(sizeof(long long int) * n);

    // Receive Nums
    for(int i = 0; i < n; i++)
        scanf("%d", &(*(nums + i)));

    printf("Mean: %.1f\n", mean(nums, n));
    printf("Median: %d", median(nums, n));

    free(nums);
    return 0;
}

float mean(long long int* arr, int size)
{
    float sum = 0.0;

    for(int i = 0; i < size; i++)
        sum += (float)*(arr + i);
    sum /= size;
    return sum;
}

long long int median(long long int* arr, int size)
{
    long long int median = 0, index;
    if(size % 2 != 0)
    {
        index = (size + 1) / 2;
        return median = *(arr + (index - 1));
    }
    else
    {
        int index1 = size / 2;
        int index2 = (size / 2) + 1;
        return median = (*(arr + (index1 - 1)) + *(arr + (index2 - 1))) / 2;
    }
}

long long int mode(long long int* arr, int size)
{
    long long int maxValue = 0, maxCount = 0;
    for (int i = 0; i < size; ++i)
    {
        long long int count = 0;
        for (int j = 0; j < size; ++j)
        {
            if (*(arr + j) == *(arr + i))
                ++count;
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxValue = *(arr + i);
        }
        // In case of a tie, the smallest number is considered as mode
        else if (count == maxCount && *(arr + i) < maxValue)
        {
            maxValue = *(arr + i);
        }
    }
    return maxValue;
}
