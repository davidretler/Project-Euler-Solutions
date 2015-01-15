/*
  Problem 46
  It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

  9 = 7 + 2×12
  15 = 7 + 2×22
  21 = 3 + 2×32
  25 = 7 + 2×32
  27 = 19 + 2×22
  33 = 31 + 2×12

  It turns out that the conjecture was false.

  What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <stdio.h>
#include "prime_2.h"
#include <stdbool.h>

//#define DEBUG

bool judge(long num);

int main(void)
{
    initialize_primes();

    long curr_num = 3;
    while(judge(curr_num))
    {
	curr_num += 2;
    }

    printf("Answer: %ld\n", curr_num);
    
    return 0;
}

bool judge(long num)
{
    if(is_prime(num) || num % 2 == 0) return true;
    //bool loop = true;
    //int curr_prime = 0;
    //int curr_sq = 1;
    long curr_sum;

    for(int curr_sq = 0; 2*curr_sq*curr_sq < num; curr_sq++)
    {
	for(int curr_prime = 0; prime(curr_prime) < num; curr_prime++)
	{
	    curr_sum = 2*curr_sq*curr_sq + prime(curr_prime);
	    if(curr_sum == num)
	    {
#ifdef DEBUG
		printf("%ld = %ld + 2*%d^2\n", num, prime(curr_prime), curr_sq);
#endif		
		return true;
	    }
	}
    }

    return false;
    
}
