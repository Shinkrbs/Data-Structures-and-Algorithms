#include <stdio.h>
#include <stdlib.h>

double computeMedian(double *data, int length);

int main()
{
    int length;
    printf("Input Number of Data: ");
    scanf("%d", &length);

    double* data = (double*)malloc(sizeof(double) * length);
    printf("Input Data:\n");
    for(int i = 0; i < length; i++)
        scanf("%lf", &(*(data + i)));

    double median = computeMedian(data, length);
    printf("Median: %.2lf", median);
    
    free(data);
    return 0;
}

double computeMedian(double *data, int length)
{
    // Sort data
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(*(data + j) > *(data + (j + 1)))
            {
                double temp = *(data + j);
                *(data + j) = *(data + (j + 1));
                *(data + (j + 1)) = temp;
            }
        }
    }

    // Find Median
    if(length % 2 != 0)
    {
        int median_position = length / 2;
        return *(data + median_position);
    }
    else
    {
        int median_position1, median_position2;
        median_position1 = (length / 2) - 1;
        median_position2 = median_position1 + 1;
        return ((*(data + median_position1) + *(data + median_position2)) / 2);
    }
}