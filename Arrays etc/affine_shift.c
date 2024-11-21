#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, n;
    printf("a, b, & n: ");
    scanf("%d %d %d", &a, &b, &n);

    char* input = (char*)malloc(sizeof(char) * (n + 1));
    char* answer = (char*)malloc(sizeof(char) * (n + 1));
    printf("Encrypt: ");
    scanf("%s", input);

    for(int i = 0; i < n; i++)
    {
        int p = 0;
        for(int j = 65; j <= 90; j++)
        {
            if((char)(j) == input[i])
            {
                p = ((a * p) + b) % 26;
                *(answer + i) = (char)(p + 65);
                break;
            }
            p++;
        }
    }
    answer[n] = '\0'; // Null-terminate the answer string

    printf("Encrypted Text: %s", answer);

    free(input);
    free(answer);
    return 0;
}