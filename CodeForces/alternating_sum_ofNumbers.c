#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    int a[n], ans[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        int sum = 0;

        for(int j = 0; j < m; j++)
            scanf("%d", &a[j]);

        for(int j = 0; j < m; j++)
        {
            if(j % 2 == 0)
                sum += a[j];
            else    
                sum -= a[j];
        }
        ans[i] = sum;
    }

    for(int i = 0; i < n; i++)
        printf("%d\n", ans[i]);

    return 0;
}