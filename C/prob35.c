/*
Problem 35 

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(long num);
long next_prime(long p);
bool check_circularity(long p);
long rotate(long p);
int n_digits(long n);

int main(void)
{
	//current prime
	long curr_p = 2;
	//is curr_p circular?
	bool is_circ = false;
	
	int count = 0;
	
	while(curr_p < 1000000)
	{
		if(check_circularity(curr_p))
		{
			count++;
			printf("%ld\n", curr_p); 
		}
		
		curr_p = next_prime(curr_p);
	}
	
	printf("Number of circular primes: %d", count);
	
	return 0;
}

//Checks if p is a circular prime
bool check_circularity(long p)
{
	//n digits means n - 1 rotations
	int digits = n_digits(p);
	
	//Rotate the proper number of times
	for(int i = 0; i < digits; i++)
	{
		if(!is_prime(p))
		{
			return false;
		}
		p = rotate(p);
	}
	
	return true;
}

//Rotates the prime once
long rotate(long p)
{
	int digits = n_digits(p);
	char p_string[digits];
	char copy_string[digits];
	
	sprintf(p_string, "%ld", p);
	//sprintf(copy_string, "%ld", p);
	
	for(int i = 0; i < digits; i++)
	{
		copy_string[i] = p_string[(i > 0) ? i - 1 : digits - 1];
	}
	
	return atoi(copy_string);
}

//Returns true if a number is prime, O(sqrt(n))
//This naive algorithm works by trial division rather than anything fancy.
bool is_prime(long num)
{
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

