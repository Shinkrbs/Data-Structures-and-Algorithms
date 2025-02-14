#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    // long long int octal = 0;
    // scanf("%lld", &octal);
    long long int n, octal = 0;
    scanf("%lld", &n);
    int ctr = 0;
    
    while(n != 0)
    {
        int temp = n % 8;
        octal += temp *(pow(10, ctr));
        ctr++;
        n /= 8;
    }
    printf("%d ", octal);
    // printf("%o", octal);
    return 0;
}