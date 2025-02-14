#include <stdio.h>
#include <stdlib.h>

int* decimalToBinary(int n);
void printBinary(int* n);

int main()
{   
    printBinary(decimalToBinary(16));
    return 0;
}

int* decimalToBinary(int n)
{
    int *temp = (int*)malloc(sizeof(int) * 35);
    int *answer = (int*)malloc(sizeof(int) * 35);
    int index = 1;
    
    while(n > 0)
    {
        *(temp + index) = n % 2;
        n /= 2;
        index++;
    }
    // Reverse
    int ctr = 1;
    int i = index - 1;
    while(i >= 1)
    {
        *(answer + ctr) = *(temp + i);
        i--;
        ctr++;
    }
    *(answer) = index - 1;
    free(temp);
    return answer;
}

void printBinary(int* n)
{
    for(int i = 1; i < *(n); i++)
    {
        printf("%d", *(n + i));
    }
    free(n);
}