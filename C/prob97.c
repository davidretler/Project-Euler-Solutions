/*
  Problem 97
  The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 26972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.

  However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×27830457+1.

  Find the last ten digits of this prime number.
*/

#include <stdio.h>

//A nice and quick one.
int main(void)
{
    long power = 7830457;
    long multiple = 28433;
    long ans = 1;
    //calculate 2^power iteratively
    for(long i = 0; i < power; i++)
    {
	ans = ans * 2;
	//we only ever need to worry about the last 10 digits, so just discard the rest
	ans = ans % 10000000000;
    }
    //multiply our answer by the multiple and add one
    ans = ans * multiple;
    ans = ans + 1;
    //make sure we've only got the last 10 digits
    ans = ans % 10000000000;
    
    printf("Last ten digits: %ld\n", ans);
    
    return 0;
}
