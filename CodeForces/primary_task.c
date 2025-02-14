#include <stdio.h>
// need to fix the algorithm
int main()
{
    int a, n;
    scanf("%d", &n);

    int answers[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if((a / 100) == 10 || (a / 10) == 10)
        {
            if((a % 100) > 1 && (a % 100) <= 99 || (a % 10) > 1 && (a % 10) <= 99)
                answers[i] = 1;
        }
        else 
            answers[i] = 0;
    }

        for(int i = 0 ; i < n ; i++)
        {
            if(answers[i] == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    return 0;
}