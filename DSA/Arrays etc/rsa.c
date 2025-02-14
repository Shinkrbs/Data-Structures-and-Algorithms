#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void encrypt();
void decrypt();
long int* primeFact(long int n);
long long int inv_mod(long int e, long int phi);
long long int norm_mod(long int b, long int n, long int m);
long long int* char_to_int(char* s);
char* int_to_char(long long int* arr, int* ctr, int blocks);
int n_of_b(long int n);

int main()
{
    decrypt();
    //encrypt();
    return 0;
}

void encrypt()
{
    long int n, e;
    char* s = (char*)malloc(sizeof(char) * 100);
    // Inputs
    printf("Input n and e: ");
    scanf("%ld %ld", &n, &e);
    printf("Input Message to Encrypt: ");
    scanf("%s", s);

    // Ensure Input is Uppercase
    for(int i = 0; i < strlen(s); i++)
        *(s + i) = toupper(*(s + i));
    // Convert Char to Integer
    long long int* c = char_to_int(s);
    // Find number of blocks
    int number_of_blocks = n_of_b(n);
    printf("Number of Blocks: %d\n", number_of_blocks);

    // Print char to int
    printf("char to int equivalent: ");
    for(int i = 0; i < strlen(s) * 2; i++)
        printf("%lld", *(c + i));

    // Final Process (Getting Encryption)
    printf("\nEncryption: ");
    for(int i = 0; i < (strlen(s) * 2); i += (number_of_blocks))
    {
        long int curr_num = 0;
        long long int encryption = 0;
        for(int j = i; j < ((number_of_blocks) + i); j++)
        {
            curr_num *= 10;
            curr_num += *(c + j);
        }
        encryption = norm_mod(curr_num, e, n);
        printf("%lld ", encryption);
    }

    free(s);
    free(c);
}

void decrypt()
{
    long int n, e, blocks;

    printf("Input n and e: ");
    scanf("%ld %ld", &n, &e);
    printf("Input number of blocks: ");
    scanf("%ld", &blocks);

    long long int* encrypted_message = (long long int*)malloc(sizeof(long long int) * blocks);
    long long int* mod_res = (long long int*)malloc(sizeof(long long int) * blocks);
    long int* prime_facts = primeFact(n);
     // Find phi
    long int phi = ((*(prime_facts)) - 1) * ((*(prime_facts + 1)) - 1);
    //Find inverse modulu
    long long int d = inv_mod(e, phi);
    printf("Private Key: %lld\n", d);

    printf("Input Encrypted Message: ");
    for(int i = 0; i < blocks; i++)
        scanf("%lld", &(*(encrypted_message + i)));

    // Decryption Part
    for(int i = 0; i < blocks; i++)
    {
        long long int curr_num = norm_mod(*(encrypted_message + i), d, n);
        *(mod_res + i) = curr_num;
        printf("Decrypted Value (%lld): %lld\n", *(encrypted_message + i), *(mod_res + i));
    }

    // Convert ints to char // not finished
    int ctr = 0;
    char* decrypted_message = int_to_char(mod_res, &ctr, blocks);
    *(decrypted_message + ctr) = '\0'; // Add null terminator
    printf("%d\n", ctr);
    printf("%s\n", decrypted_message);
    
    free(prime_facts);
    free(encrypted_message);
    free(mod_res);
    free(decrypted_message);
}

long int* primeFact(long int n)
{
    long int* p = (long int*)malloc(sizeof(long int) * 2);
    int ctr = 0;

    while(n % 2 == 0)
    {
        if (ctr < 2) 
        {
            *(p + ctr) = 2;
            ctr++;
        }
        n /= 2;
    }

    for(int i = 3; i <= sqrt(n); i += 2)
    {
        while(n % i == 0)
        {
            if (ctr < 2) 
            {
                *(p + ctr) = i;
                ctr++;
            }
            n /= i;
        }
        if(ctr == 2)
            break;
    }

    if(n > 2 && ctr < 2)
        *(p + ctr) = n;

    return p;
}


long long int inv_mod(long int e, long int phi)
{
    long long int d, q = 0, r = 0, t1 = 0, t2 = 1, a = phi, b = e;

    while(r != 1)
    {
        q = a / b;
        r = a % b;
        d = t1 - (q * t2);
        a = b;
        b = r;
        t1 = t2;
        t2 = d;
    }
    if(d < 0)
        d = phi + d;
    return d;
}

long long int norm_mod(long int a, long int b, long int m)
{
    long long int x = 1, p = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * p) % m;
        b /= 2;
        p = (p * p) % m;
    }
    return x;
}

long long int* char_to_int(char* s)
{
    long long int* temp = (long long int*)malloc(sizeof(long long int) * (strlen(s) * 2));
    
    for (int i = 0, j = 0; i < strlen(s); i++, j += 2)
    {
        // Store values in temp array; insert leading 0 if value is less than 10
        if ((((int)(*(s + i)) - 65) % 26) < 10)
        {
            *(temp + j) = 0;
            *(temp + (j + 1)) = ((int)(*(s + i)) - 65) % 26;
        }
        else
        {
            *(temp + j) = (((int)(*(s + i)) - 65) % 26) / 10;
            *(temp + (j + 1)) = (((int)(*(s + i)) - 65) % 26) % 10;
        }
    }
    return temp;
}

int n_of_b(long int n)
{
    return 2 * ((int)(ceil)(log10(n) / 2));
}

char* int_to_char(long long int* arr, int* ctr, int blocks)
{
    char* temp = (char*)malloc(sizeof(char) * (blocks * (3 + 1)));

    for(int i = 0; i < blocks; i ++)
    {
        long long int curr_num = *(arr + i);
        // Convert to Text
        while(curr_num != 0)
        {
            *(temp + *ctr) = (char)(((curr_num % 100) % 26 + 65));
            curr_num /= 100;
            (*ctr)++;
        }
    }
    // Reverse the text //to fix
    for(int i = 0; i < *ctr / 2; i++)
    {
        char temp_char = temp[i];
        temp[i] = temp[*ctr - i - 1];
        temp[*ctr - i - 1] = temp_char;
    }
    return temp;
}