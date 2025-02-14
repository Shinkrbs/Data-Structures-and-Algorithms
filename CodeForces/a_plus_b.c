#include <stdio.h>

int main()
{
    int a, n;
    scanf("%d", &n);

    int answer[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        int temp = a;
        a /= 10;
        int b  = temp % 10;
        answer[i] = a + b;
    }

    for(int i = 0; i < n; i++)
        printf("%d\n", answer[i]);
    return 0;
}