#include <stdio.h>
#include <string.h>

int romanToInt(char* romanNumeral)
{
    int length = strlen(romanNumeral);
    int result = 0;

    // Create a mapping of Roman numeral symbols and their corresponding values
    int values[26];
    values['I' - 'A'] = 1;
    values['V' - 'A'] = 5;
    values['X' - 'A'] = 10;
    values['L' - 'A'] = 50;
    values['C' - 'A'] = 100;
    values['D' - 'A'] = 500;
    values['M' - 'A'] = 1000;

    // Iterate through the Roman numeral string
    for (int i = 0; i < length; i++) 
    {
        // Get the value of the current symbol
        int current = values[romanNumeral[i] - 'A'];
        
        // Check if the next symbol has a higher value
        if (i + 1 < length && values[romanNumeral[i + 1] - 'A'] > current) 
        {
            result += values[romanNumeral[i + 1] - 'A'] - current;
            i++; // Skip the next symbol since it has been considered
        } 
        else 
            result += current;
    }
    return result;
}

int main() 
{
    char romanNumeral[20];
    printf("Enter a Roman numeral: ");
    scanf("%s", romanNumeral);
    int result = romanToInt(romanNumeral);
    printf("Equivalent integer: %d\n", result);
    return 0;
}