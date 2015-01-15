/*
  Problem 50
  The prime 41, can be written as the sum of six consecutive primes:

  41 = 2 + 3 + 5 + 7 + 11 + 13
  This is the longest sum of consecutive primes that adds to a prime below one-hundred.

  The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

  Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include "prime_2.h"
#include <stdio.h>

//#define DEBUG

long consecutive_prime_sum(long seed_pos, int terms);
long prime_sum(long terms);

 
static long LIMIT = 1000000;


int main(void)
{
    //printf("%ld\n", consecutive_prime_sum(2, 6));
#ifdef DEBUG
    printf("Initializing\n");
#endif
    initialize_primes();
#ifdef DEBUG
    printf("Initialized\n");
#endif

    //long b = 0;
    for(int i = 10000; i > 0; i--)
    {
	long a = prime_sum(i);
	if(a != -1)
	{
	    printf("%ld is the sum of %d consecutive prime numbers.\n", a, i);
	    return 0;
	    //b = a;
	}
    }

    //prime_sum(543);
    //printf("%ld\n", prime_sum(543));
    
    printf("Found no answer.\n");
    
}

/*
  If there a sequence of consecutive primes of length `terms` that sums to a prime below LIMIT,
  this will return the num. Otherwise, it will return -1.
*/
long prime_sum(long terms)
{
    int seed_pos = 0;
    bool loop = true;
    long curr_sum;
    while(loop)
    {
	curr_sum = consecutive_prime_sum(seed_pos, terms);
	if(is_prime(curr_sum) && curr_sum <= LIMIT)
	{
	    return curr_sum;
	}
	if(curr_sum > LIMIT)
	{
	    loop = false;
	}
	seed_pos++;
    }
    return -1;
}

/*
  Returns the sum of `terms` consecutive primes starting with `seed_prime`
*/
long consecutive_prime_sum(long seed_pos, int terms)
{
    long sum = 0;
    int i = seed_pos;
    for(int j = 0; j < terms; j++)
    {
	sum += prime(i + j);
    }
    return sum;
}
