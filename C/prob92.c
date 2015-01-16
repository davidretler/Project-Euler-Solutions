/*
  Problem 92
  A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

  For example,

  44 → 32 → 13 → 10 → 1 → 1
  85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

  Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

  How many starting numbers below ten million will arrive at 89?
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define CACHE_LIMIT 10000000
#define MAX_START 10000000

static int cache[CACHE_LIMIT];

int n_digits(long num);
bool reaches_89(long num);
void initialize_cache(void);

int main(void)
{
    initialize_cache();
    
    long sum = 0;
    for(int i = 1; i < MAX_START; i++)
    {
	if(reaches_89(i))
	{
	    sum++;
	}
    }

    printf("%ld starting numbers reach 89.\n", sum);
}

/*
  Returns true if sequence reaches 89. Caches answers for efficiency
*/
bool reaches_89(long num)
{
    if(num == 1) return false;
    if(num == 89) return true;
    if(num < CACHE_LIMIT && cache[num] != -1) return (cache[num] == 1) ? true : false;

    char num_s[n_digits(num)+1];
    sprintf(num_s, "%ld", num);
    long square_sum = 0;
    for(int i = 0; i < n_digits(num); i++)
    {
	int digit = num_s[i] - '0';
	square_sum += digit*digit;
    }
    
    //printf("-> %ld ", square_sum);
    
    bool ans = reaches_89(square_sum);
    if(num < CACHE_LIMIT)
    {
	cache[num] = ans;
    }
    return ans;
}

int n_digits(long num)
{
    return ceil(log(num)/log(10));
}

/*
  Initializes all the cache values to -1 (undefined)
*/
void initialize_cache(void)
{
    for(int i = 0; i < CACHE_LIMIT; i++)
    {
	cache[i] = -1;
    }
}
