#include <stdio.h>

int main()
{
	char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
							'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
							'U', 'V', 'W', 'X', 'Y', 'Z'};
	int n;
	scanf("%d", &n);

	char input[n];
	char answer[n];

	scanf("%s", &input);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(input[i] == letters[j])
			{
				answer[i] = letters[(j - 3 + 26) % 26];
				break;
			}
		}
	}
	printf("%s", answer);		
	return 0;			
}