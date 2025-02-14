#include <stdio.h>

int main()
{
    int a, b, n;
    scanf("%d", &n);

    int ans[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        int c = (a + b) / 2;
        ans[i] = (c - a) + (b  - c);
    }

    for(int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}