/*
  Problem 41
  We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

  What is the largest n-digit pandigital prime that exists?
*/

#include <stdio.h>
#include <stdlib.h>
#include "prime_2.h"
#include <stdbool.h>

bool is_pandigital(long long num);

int main(void)
{
    initialize_primes();

    for(long long i = 987654321; i > 1; i--)
    {
	if(is_pandigital(i) && is_prime(i))
	{
	    printf("%lld\n", i);
	    return 0;
	}
    }
    
    return 1;
}

/*
  Returns true if and only if the number is pandigital
 */
bool is_pandigital(long long num)
{
    int digits = n_digits(num);

    //there can't exist a 10-digit or greater pandigital number
    if(digits > 9) return false;
    
    char num_s[digits + 1];
    sprintf(num_s, "%lld", num);
    //the index 0 is true because the number can't contain a 0 digit
    bool digit_used[] = {true, false, false, false, false, false, false, false, false, false};
    for(int i = 0; i < digits; i++)
    {
	int curr_digit = num_s[i] - '0';
	if(digit_used[curr_digit] || curr_digit > digits)
	{
	    return false;
	}
	digit_used[curr_digit] = true;
    }
    return true;
}
