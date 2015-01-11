/* Prob 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_prime(int num)
{
	int max = ceil(sqrt(num));
	int n = 2;
	bool prime = true;
	
	while(n <= max)
	{
		if(num % n == 0 && num != n)
		{			
			prime = false;
			break;
		}
		n++;
	}
	
	return prime;
}

int main(void)
{
	int nPrimes = 1;
	int p = 2;
	
	while(nPrimes < 10001)
	{
		p++;
		if (is_prime(p))
		{
			nPrimes++;
			printf("%d\n", p);
		}
	}

	return 0;
}