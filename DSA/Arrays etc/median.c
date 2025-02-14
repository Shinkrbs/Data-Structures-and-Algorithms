#include <stdio.h>
#include <math.h>

//Find Median of the Number

void sort(float arr[], int n);
float findMedian(float arr[], int n);

int main()
{
	int n;
	scanf("%d", &n);

	float arr[n];
	for(int i = 0; i < n; i++)
		scanf("%f", &arr[i]);
	printf("%.1f", findMedian(arr, n));
	return 0;
}

void sort(float arr[], int n)
{
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
}

float findMedian(float arr[], int n)
{
	if (n <= 1)
		return arr[0];
	sort(arr, n);

	if(n % 2 != 0)
	{
		int index = n / 2;
		return arr[index];
	}
	else
	{
		int index_right, index_left;
		index_right = (n / 2 ) - 1;
		index_left = (n / 2);
		float answer = (arr[index_right] + arr[index_left]) / 2;
		//printf("%d, %d\n", index_right, index_left);
		return answer;
	}
}