#include <stdio.h>
#include <stdlib.h>

void to_hex(long long int n);

int main()
{
    long long int n;
    printf("Input Number: ");
    scanf("%lld", &n);
    to_hex(n);
    return 0;
}

void to_hex(long long int n)
{
    long long int* hex = (long long int*)malloc(sizeof(long long int) * 16);
    long long int dec = n, ctr = 0;;

    for(int i = 0; n != 0; i++)
    {
        long long int temp = n % 16;
        if(temp < 10)
            temp += 48;
        else
            temp += 55;
        *(hex + i) = temp;
        n /= 16;
        ctr++;
    }
    printf("Hexadecimal Equivalent[%lld]: ", dec);
    for(int i = ctr - 1; i >= 0; i--)
        printf("%c", *(hex + i));    
    free(hex);
}