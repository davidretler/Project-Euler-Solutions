/*The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?*/

//Terribly inefficient

typedef int bool;
#define true 1
#define false 0

#include <stdio.h>

//Returns all the prime numbers up to n, using a inefficient sieve, lest number is -1
bool isprime(long n){
	bool prime;
	if(n == 1 || n == 2 || n == 3 || n == 5 || n == 7) return true;
	long j;
	//loop over all the numbers less than n, starting with 7
	for(j = 2; j < n; j++){
		//if n is divisible by j (not prime)
		if(n % j == 0){
			prime = false;
			break;
		}
		//if we're at the end
		if( j == n - 1){
			prime = true;
			break;
		}
	}
	
	
	return prime;
	
	
}

int main(){
	long i = 600851475143 - 1;
	while(i > 0){
		if(isprime(i) && 600851475143 % i == 0){
			printf("%d ", i);
			break;
		}
		i--;
	}
	printf("\n");
	return 0;
}