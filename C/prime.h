#include <math.h>
#include <stdbool.h>

bool is_prime(long num);
int n_digits(long n);
long next_prime(long p);

//Returns true if a number is prime, O(sqrt(n))
//This naive algorithm works by trial division rather than anything fancy.
bool is_prime(long num)
{
	if(num == 1 || num <= 0) return false;
	
	long max = ceil(sqrt(num));
	long n = 2;
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

//Returns the number of digits in the number
int n_digits(long n)
{
	return ceil(log(n)/log(10));
}

//Returns the first prime after p
long next_prime(long p)
{
	//if p is even, add one. if p is odd, add two.
	p += (p % 2 == 0) ? 1 : 2;
	while(!is_prime(p))
	{
		p+=2;
	}
	return p;
}
