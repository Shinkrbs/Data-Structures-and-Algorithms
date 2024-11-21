#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	float arr[n];
	for(int i = 0; i < n; i++)
		scanf("%f", &arr[i]);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				float temp = arr[j];
				arr[j]  = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for(int i = 0; i < n; i++)
		printf("%.1f ", arr[i]);
}