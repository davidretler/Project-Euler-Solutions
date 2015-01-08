/*The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600,851,475,143 ?*/

//Terribly inefficient


#include <stdio.h>
#include <stdbool.h>

// calcul a^n%mod
size_t power(size_t a, size_t n, size_t mod)
{
    size_t power = a;
    size_t result = 1;
 
    while (n)
    {
        if (n & 1)
            result = (result * power) % mod;
        power = (power * power) % mod;
        n >>= 1;
    }
    return result;
}
 
// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
bool witness(size_t n, size_t s, size_t d, size_t a)
{
    size_t x = power(a, d, n);
    size_t y;
 
    while (s) {
        y = (x * x) % n;
        if (y == 1 && x != 1 && x != n-1)
            return false;
        x = y;
        --s;
    }
    if (y != 1)
        return false;
    return true;
}
 
/*
 * if n < 1,373,653, it is enough to test a = 2 and 3;
 * if n < 9,080,191, it is enough to test a = 31 and 73;
 * if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
 * if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
 * if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
 * if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
 * if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
 */
 
bool is_prime_mr(size_t n)
{
    if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3)
        return true;
 
    size_t d = n / 2;
    size_t s = 1;
    while (!(d & 1)) {
        d /= 2;
        ++s;
    }
 
    if (n < 1373653)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141)
        return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
    if (n < 1122004669633)
        return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
    if (n < 2152302898747)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
    if (n < 3474749660383)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);
    return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);
}

int main(){
	//start at floor(600851475143/2), the lowest possible factor
	//using longs cause the number is too big
	long i = 300425737571;
	while(i > 0)
	{
		//keep iterating over primes until we reach the largest one the factors
		//ie the first one if we're counting down
		if(is_prime_mr(i) && 600851475143 % i == 0){
			printf("%d ", i);
			break;
		}
		//we can safely skip down two without missing a prime
		i -= 2;
	}
	
	printf("\n");
	
	
	
	return 0;
}