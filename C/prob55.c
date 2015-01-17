/*
  Problem 55
  If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

  Not all numbers produce palindromes so quickly. For example,

  349 + 943 = 1292,
  1292 + 2921 = 4213
  4213 + 3124 = 7337

  That is, 349 took three iterations to arrive at a palindrome.

  Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

  Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

  How many Lychrel numbers are there below ten-thousand?

  NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ITERATION_LIMIT 51
//#define DEBUG

typedef unsigned long long ull_t;

bool is_lychrel(ull_t num, int count);
long long reverse_number(ull_t num);
int n_digits(ull_t num);
bool is_palindrome(ull_t num);

int main(void)
{
    int count = 0;
    for(int i = 1; i < 10000; i++)
    {
	if(is_lychrel(i, 0))
	{
	    count++;
	}
    }
    printf("%d\n", count);
    return 0;
}

bool is_lychrel(ull_t num, int count)
{
    ull_t rev = reverse_number(num);
    ull_t sum = num + rev;
#ifdef DEBUG
    printf("%d:\t%llu + %llu = %llu\n", count, num, rev, sum);
#endif
    if(is_palindrome(sum))
    {
#ifdef DEBUG
	//printf("%lld\t%d\n", sum, count);
#endif
	return false;
    }
    else if(count > ITERATION_LIMIT)
    {
	return true;
    }
    return is_lychrel(sum, count + 1);
}

long long reverse_number(ull_t num)
{
    int digits = n_digits(num);
    char num_s[digits + 1];
    char rev_s[digits + 1];
    sprintf(num_s, "%lld", num);
    for(int i = 0; i < digits; i++)
    {
	rev_s[i] = num_s[digits - i - 1];
    }
    rev_s[digits] = 0;

    return atol(rev_s);
}

bool is_palindrome(ull_t num)
{
    int digits = n_digits(num);
    char num_s[digits + 1];
    sprintf(num_s, "%lld", num);
    for(int i = 0; i < digits; i++)
    {
	if(num_s[i] != num_s[digits - i - 1])
	{
	    return false;
	}
    }
    return true;
}
    
int n_digits(ull_t num)
{
    return ceil(log(num)/log(10));
}
