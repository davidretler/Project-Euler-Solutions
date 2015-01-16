/*
  Problem 47
  The first two consecutive numbers to have two distinct prime factors are:

  14 = 2 × 7
  15 = 3 × 5

  The first three consecutive numbers to have three distinct prime factors are:

  644 = 2² × 7 × 23
  645 = 3 × 5 × 43
  646 = 2 × 17 × 19.

  Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
*/

//#define DEBUG

#include <stdio.h>
#include "prime_2.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool judge(long num, int n_prime_factors);

int main(void)
{
    initialize_primes();
    printf("Initialized.\n");
    long i = 2;
    while(!judge(i, 4))
    {
	//printf("i = %ld\n", i);
	i++;
    }

    printf("Result: %ld\n", i);
    
    return 0;
}

/*
  Checks if num and the 3 numbers after it have distinct prime factors
*/
bool judge(long num, int n_prime_factors)
{
    //upper bound found from this source: https://primes.utm.edu/howmany.html
    int lim =(int)ceil((num / log(num)) *(1 + 1.2762/log(num)));

    int *factors = malloc(sizeof(int) * lim);

    for(int j = 0; j < n_prime_factors; j++)
    {
	int distinct = 0;
	prime_factors(num + j, factors);
	int i = 0;
#ifdef DEBUG
	printf("%ld: ", num + j);
#endif
	while(factors[i] != -1)
	{
#ifdef DEBUG
	    printf("%d ", factors[i]);
#endif
	    if(factors[i] != 0) distinct++;
	    i++;
	    if(i >= lim)
	    {
		printf("Error: insufficient array length\n");
		return false;
	    }
	}
#ifdef DEBUG
	printf("\n");
#endif
	if(distinct != n_prime_factors) return false;
    }
    return true;
}
