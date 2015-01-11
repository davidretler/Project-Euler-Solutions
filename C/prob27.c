/*
Problem 27
Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n² + an + b, where |a| < 1000 and |b| < 1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/


//#define DEBUG

#include <stdio.h>
#include "prime.h"


int n_primes(int a, int b);

//Just another brute force
int main(void)
{
	int max_n = 0;
	int max_a = 1001;
	int max_b = 1001;
	long count = 0;
	
	for(int a = -1000; a <= 1000; a++)
	{
		for(int b = -1000; b <= 1000; b++)
		{
			int curr_n = n_primes(a, b);
			if(curr_n > max_n)
			{
				max_n = curr_n;
				max_a = a;
				max_b = b;
			}
			#ifdef DEBUG
			printf("a: %d\tb: %d\tn: %d\t%ld\n", a, b, curr_n, count);
			#endif
			count++;
		}
	}
	
	printf("a: %d\tb: %d\ta*b: \%d\tn: %d\n", max_a, max_b, max_a*max_b, max_n);

	printf("\nTested %ld combinations\n.", count);
	
	return 0;
}

/*
	returns the number of consecutive numbers for which the expression
	n^2 + a*n + b
	starting with n = 0
 */
int n_primes(int a, int b)
{
	int curr_n = 0;
	int count = 0;
	while(is_prime(curr_n*curr_n + a*curr_n + b))
	{
		count++;
		curr_n++;
	}
	
	return count;
}
