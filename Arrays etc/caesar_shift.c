#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	char answer[n], input[n];
	char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
						'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	scanf("%s", &input);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(input[i] == letters[j])
			{
				int index = (((j - 3) + 26) % 26);
				answer[i] = letters[index];
				break;
			}
		}
	}
	printf("%s", answer);
	return 0;
}