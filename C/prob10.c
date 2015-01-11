/*
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/


#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_prime(long long int num)
{
	long long int max = ceil(sqrt(num));
	long long int n = 2;
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
	long long int p = 2L;
	long long int sum = 0;
	
	
	while(p < 2000000L)
	{
		if (is_prime(p))
		{
			sum += p;
		}
		p++;
	}

	printf("Sum: %lld", sum);
	return 0;
}