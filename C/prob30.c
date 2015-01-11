/*
Problem 30
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digits(long num);
long sum_nth_powers(long num, int n);

int main(void)
{
	long tot = 0;
	for(int i = 1; i < 1000000; i++)
	{
		long sum = sum_nth_powers(i, 5);
		if(i == sum)
		{	
			printf("%d\n", i);
			tot += sum;
		}
	}
	
	printf("Sum of numbers equal to the sum of the nth powers of their digits: %ld\n", tot);

	return 0;
}

//Returns the sum of the nth-powers of the digits
long sum_nth_powers(long num, int n)
{
	#ifdef DEBUG
	printf("Creating buffer\n");
	#endif
	char num_s[digits(num)+1];
	#ifdef DEBUG
	printf("Writing to buffer\n");
	#endif
	sprintf(num_s, "%ld", num);
	#ifdef DEBUG
	printf("Done writing\n");
	#endif
	
	long sum = 0;
	for(int i = 0; i < digits(num); i++)
	{
		int digit = num_s[i] - '0';
		#ifdef DEBUG
		printf("digit: %d\n", digit);
		#endif
		sum += pow(digit, n);
	}
	
	return sum;
}


//Returns the number of digits in num
int digits(long num)
{
	return ceil(log(num)/log(10));
}

