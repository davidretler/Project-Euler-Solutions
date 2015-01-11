/*
Problem 34
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//pre-computed factorials, only 0 - 9 necessary
const int FACTORIAL[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int digits_in(long num);
long fac_of_digits(long num);

int main(void)
{
	//I guessed this upper bound and it worked
	for(int i = 1; i < 1000000; i++)
	{
		if(i == fac_of_digits(i))
			printf("%d\t%ld\n", i, fac_of_digits(i));
	}
	return 0;
}

//returns the factorial of the digits summed
long fac_of_digits(long num)
{
	char digits_s[digits_in(num)+1];
	sprintf(digits_s, "%ld", num);
	
	int index = 0;
	int sum = 0;
	while(digits_s[index] != '\0')
	{
		sum += FACTORIAL[digits_s[index++] - '0'];
	}
	

	return sum;
}

//digits in the number
int digits_in(long num)
{
	return ceil(log(num)/log(10));
}