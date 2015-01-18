/*
  Problem 112
  Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

  Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

  We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

  Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

  Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.

  Find the least number for which the proportion of bouncy numbers is exactly 99%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_increasing(long num);
bool is_decreasing(long num);
bool is_bouncy(long num);
int n_digits(long num);

int main(void)
{
    long bouncy_count = 0;
    long num_count = 0;
    long i = 1;
    while(100*bouncy_count != 99*num_count || num_count == 0)
    {
	if(is_bouncy(i)) bouncy_count++;
	num_count++;
	i++;
    }

    printf("Answer: %ld\n",  num_count);
    
    return 0;
}

bool is_bouncy(long num)
{
    return !is_decreasing(num) && !is_increasing(num);
}

//Simple check, comparing each digit to the last
bool is_decreasing(long num)
{
    int digits = n_digits(num);
    char num_s[digits+1];
    sprintf(num_s, "%ld", num);
    for(int i = 1; i < digits; i++)
    {
	if(num_s[i] > num_s[i - 1])
	{
	    return false;
	}
    }
    return true;
}

//Exactly like the previous, but > is now <
bool is_increasing(long num)
{
    int digits = n_digits(num);
    char num_s[digits+1];
    sprintf(num_s, "%ld", num);
    for(int i = 1; i < digits; i++)
    {
	if(num_s[i] < num_s[i - 1])
	{
	    return false;
	}
    }
    return true;
}

int n_digits(long num)
{
    return (int)ceil(log(num)/log(10));
}
