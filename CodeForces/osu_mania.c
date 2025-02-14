#include <stdio.h>
// Not finished

int main()
{
    int n, ctr;
    scanf("%d", &n);
    char* a[n];
    int b[n], len[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &len[i]);
        for(int j = 0; j < len[i]; j++)
        {
            scanf("%c %c %c %c", &a[j]);
            for(int k = 3; k >= 0; k--)
            {
                if(*(a[k]) == '#')
                {
                    ctr++;
                    b[j] = k + 1;
                }
            }
        }
    }

    for(int i = 0; i < ctr; i++)
    {
        for(int j = 0; j < len[i]; j++)
            printf("%d ", b[j]);
        printf("\n");
    }
    
    return 0;
}