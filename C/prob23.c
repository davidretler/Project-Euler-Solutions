/*
  Problem 23 
  A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

  A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

  As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

  Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

//#define DEBUG
#define UPPER_BOUND 10000
#define MAX_ABUNDANT 28124
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool is_abundant(long num);
int n_digits(long num);
void divisors(long num, long* div_array);
void initialize_abundant(void);
void initialize_sums(void);
bool is_abundant_sum(long num);

static int abundant[UPPER_BOUND];
//we only need to go to 28123 because everything above it true
static bool sums[28123];

int main(void)
{
    initialize_abundant();
    initialize_sums();

    long sum = 0;

    for(int i = 0; i < MAX_ABUNDANT - 1; i++)
    {
	if(!is_abundant_sum(i))
	{
	    //printf("%d\n", i);
	    sum += i;
	}
    }

    //printf("%d\n", is_abundant_sum(28124));

    printf("Sum: %ld\n", sum);
     
    return 0;
}

/*
  Returns whether a given number is abundant or not
*/
bool is_abundant(long num)
{
    //int length = n_digits(num);

    long div_array[num+1];

    divisors(num, div_array);

    long  sum = 0;
    int i = 0;

    while(div_array[i] != -1)
    {
	sum += div_array[i++];
    }

    return sum > num;
}

bool is_abundant_sum(long num)
{
    if(num > MAX_ABUNDANT - 1) return true;
    else return sums[num];
}

/*
  Fills an array with the divisors of the passed number
*/
void divisors(long num, long* div_array)
{
    int i = 0;
    for(long d = 1; d < num; d++)
    {
	if(num % d == 0)
	{
	    div_array[i++] = d;
	}
    }
    div_array[i] = -1;
}

/*
  Returns the number of digits in the number
*/
int n_digits(long num)
{
    return ceil(log(num)/log(10));
}

/*
  Populates and array of the abundant numbers
*/
void initialize_abundant(void)
{
    int i = 0;
    int n = 1;
    while(i < UPPER_BOUND)
    {
	if(is_abundant(n))
	{
	    abundant[i++] = n;
	}
	n++;
    }
}

/*
  Fills an array with the sums of pairs of abundant numbers
*/
void initialize_sums(void)
{
    for(int k = 0; k < MAX_ABUNDANT; k++)
    {
	sums[k] = false;
    }
    
    for(int i = 0; i < UPPER_BOUND; i++)
    {
	for(int j = 0; j < UPPER_BOUND; j++)
	{
	    int curr_sum = abundant[i] + abundant[j];
	    if(curr_sum < MAX_ABUNDANT)
	    {
		sums[curr_sum] = true;
	    }
	}
    }
}
