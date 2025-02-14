#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize);

int main()
{

    return 0;
}

int maxArea(int* height, int heightSize) 
{
    int max = 0, left = 0, right = heightSize - 1;
    while(left < right)
    {
        // Finding the total area (Width * Height)
        int current_area = (right - left) * ((*(height + left) < *(height + right)) ? *(height + left) : *(height + right));
        if(max < current_area)
            max = current_area;
        
        if(*(height + left) < *(height + right))
            left++;
        else
            right--;
    }
    return max;
}