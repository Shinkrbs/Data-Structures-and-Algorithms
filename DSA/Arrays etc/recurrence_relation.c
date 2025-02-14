#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long int n;
    scanf("%lld", &n);

    long long int *a = (long long int*)malloc(sizeof(long long int) * n);
    long long int x = 0;
    
    if(n < 0 && n > 50)
        return 0;
    

    for(int i = 0; i < n; i++)
    {
        if(x == 0)
        {
            a[i] = 1;
            x = fabs(a[i]);
        }
        else if(x % 2 != 0 && x > 0)
        {
            a[i] = 2 * a[i - 1];
            x = fabs(a[i]);
        }
        else if (x % 2 == 0 && x > 0)
        {
            a[i] = (3 * a[i - 2]) - (4 * a[i - 1]);
            x = fabs(a[i]);
        }
    }
       
    for(int i = 0; i < n; i++)
        printf("%lld ", a[i]);
    free(a);
    return 0;
}