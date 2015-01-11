/*
Problem 37
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/
//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prime.h"

void truncate_left(char *string);
void truncate_right(char *string);
bool check_left(long num);
bool check_right(long num);


int main(void)
{
	long curr_p = 11;
	int n_trunc = 0;
	long sum = 0;
	while(n_trunc < 11)
	{
		if(check_left(curr_p) && check_right(curr_p))
		{
			n_trunc++;
			sum += curr_p;
			printf("Number found!\t%ld\n", curr_p);
		}
		curr_p = next_prime(curr_p);
	}
	
	printf("Sum: %ld\n", sum);
	
	return 0;
}

//check if the prime is left-truncatable
bool check_left(long num)
{
	char num_s[n_digits(num) + 1];
	sprintf(num_s, "%ld", num);
	int i = n_digits(num);
	while(i != 0 && is_prime(atoi(num_s)))
	{
		#ifdef DEBUG
		printf("%s\n", num_s);
		#endif
		
		truncate_left(num_s);
		i--;
	}
	if(i == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//check if the prime is right-truncatable
bool check_right(long num)
{
	char num_s[n_digits(num) + 1];
	sprintf(num_s, "%ld", num);
	int i = n_digits(num);
	while(i != 0 && is_prime(atoi(num_s)))
	{
		#ifdef DEBUG
		printf("%s\n", num_s);
		#endif
		
		truncate_right(num_s);
		i--;
	}
	if(i == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//truncate the string one character from the right
void truncate_right(char *string)
{
	string[strlen(string) - 1] = 0;
}

//truncate the string one character from the left
void truncate_left(char *string)
{
	int i = 1;
	while(string[i] != 0)
	{
		string[i - 1] = string[i];
		i++;
	}
	string[i-1] = 0;
}
