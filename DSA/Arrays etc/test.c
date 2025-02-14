#include <stdio.h>

int main()
{
	printf("Hello World");
	return 0;
}

// C Program to check for prime number using Simple Trial
// Division
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int N) {
  
    // If number is less than/equal to 1, it is not prime
    if (N <= 1) {
        return false;
    }

    // Check for divisors from 2 to N-1
    for (int i = 2; i < N; i++) {
      
        // If N is divisible by any number in this range, it
        // is not prime
        if (N % i == 0) {
            return false;
        }
    }

    // If no divisors are found, it is prime
    return true;
}

int main() {
    int N = 29;
    printf("Is %d prime?\n", N);

    if (isPrime(N)) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}

#include <stdio.h>

int main() {

  int n, i, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // 0 and 1 are not prime numbers
  // change flag to 1 for non-prime number
  if (n == 0 || n == 1)
    flag = 1;

  for (i = 2; i <= n / 2; ++i) {

    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  // flag is 0 for prime numbers
  if (flag == 0)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);

  return 0;
}