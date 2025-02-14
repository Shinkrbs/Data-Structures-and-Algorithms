#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char* chars = (char*)malloc(sizeof(char) * (n + 1));
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    
    for(int i = 0; i < n; i++)
        scanf(" %c", &(*(chars + i)));

    *(chars + n) = '\0';
    printf("%s\n", chars);

    for(int i = 0; i < n; i++)
        *(res + i) = ((*(chars + i) - 68 + 26) % 26) + 'A';

    *(res + n) = '\0';
    printf("%s ", res);

    free(chars);
    free(res);
    return 0;
}