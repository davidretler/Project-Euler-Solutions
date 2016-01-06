#include "stdio.h"
#include "stdbool.h"
#include "prime_2.h"

#define GCD_SAVE 20000
#define TOTIENT_SAVE 10000000

int totient_r(int num);
int totient(int num);
int gcd(int p, int q);
void init_saved();

bool _is_gcd_saved[GCD_SAVE][GCD_SAVE];
int _gcd_saved[GCD_SAVE][GCD_SAVE];

bool _is_totient_saved[TOTIENT_SAVE];
int _totient_saved[TOTIENT_SAVE];

int main() {

	puts("Initializing...\n");
	initialize_primes();
	init_saved();
	puts("Initialized\n\n");
	
	double max = 1;
	int max_n = 0;
	for(int n = 2; n <= 1000000; n++) {
		double curr = ((double)n)/totient_r(n);
		if(curr > max) {
			max = curr;
			max_n = n;
			printf("%d\n", n);
		}
		if(n % 100 == 0) {
			printf("(%d: %f, %d: %f)\n", n, curr, max_n, max);
		}
	}
	
	printf("%d yeilds max value %f", max_n, max);


	return 0;
}

// recursive totient, for simple cases
int totient_r(int n) {
	
	if(n < TOTIENT_SAVE && _is_totient_saved[n]) {
		return _totient_saved[n];
	} else {
		int t;
		if(n == 1) return 0;
		if(n == 2) return 1;
		if(n % 2 == 0) {
			if (n/2 % 2 == 0) {
				t = 2 * totient_r(n/2);
			} else {
				t = totient_r(n/2);
			}
		} else {
			// call the more general one
			t = totient(n);
		}
		
		if(n < TOTIENT_SAVE) {
			_totient_saved[n] = t;
			_is_totient_saved[n] = true;
		}
		
		return t;
	}
}

// the number of numbers less than n which are relatively prime to num
int totient(int num) {
	
	if(num < TOTIENT_SAVE && _is_totient_saved[num]) {
		return _totient_saved[num];
	} else {
		if(is_prime(num)) return num - 1; 
		else {
			// not prime,must have a prime factors
			// if factor has multiplicity of 2 we can simplify
			long _prime = 2;
			int curr_p = 0;
			while(_prime < num) {
				if(num % _prime == 0 && num/_prime % _prime == 0) {
					break;
				}
				_prime = prime(++curr_p);
			}
			if(_prime < num) {
				return _prime * totient_r(num/_prime);
			}
			
		}
	
		int prod = 1;
	
		long _prime = 2;
		int curr_p = 0;
		while(_prime < num) {
				
			if(num % _prime == 0) {
				prod *= (_prime - 1);
			}
			
			_prime = prime(++curr_p);
		}
		
		if(num < TOTIENT_SAVE) {
			_totient_saved[num] = prod;
			_is_totient_saved[num] = true;
		}
		
		return prod;
	}
}

// Euclid's algorithm for GCD
int gcd(int p, int q) {
	//printf("(%d, %d)\n", p, q);
	if(q == 0) return p;
	if(p == 0) return q;
	
	if(p < GCD_SAVE && q < GCD_SAVE && _is_gcd_saved[p][q]) {
		return _gcd_saved[p][q];
	} else {
		int _gcd = gcd(q, p % q);
		if(p < GCD_SAVE && q < GCD_SAVE) {
			_gcd_saved[p][q] = _gcd;
			_is_gcd_saved[p][q] = true;
		} else {
			//puts("Not saved\n");
		}
		return _gcd;
	}
	
}

void init_saved(){
	for(int i = 0; i < GCD_SAVE; i++) {
		for(int j = 0; j < GCD_SAVE; j++) {
			_is_gcd_saved[i][j] = false;
		}
	}
	for(int i = 0; i < TOTIENT_SAVE; i++) {
		_is_totient_saved[i] = false;
	}
}
