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
		double curr = ((double)n)/totient(n);
		if(curr > max) {
			max = curr;
			max_n = n;
			//printf("%d\n", n);
		}
		if(n % 1 == 0) {
			//printf("(%d: %f, %d: %f)\n", n, curr, max_n, max);
		}
	}
	
	printf("%d yeilds max value %f", max_n, max);


	return 0;
}


// the number of numbers less than n which are relatively prime to num
int totient(int num) {
	
	int n = num;
	
	if(is_prime(num)) return num - 1; 


	double prod = 1;

	long _prime = 2;
	int curr_p = 0;
	while(_prime < num) {
			
		if(num % _prime == 0) {
			prod *= (1 - 1./_prime);
		}
		
		_prime = prime(++curr_p);
	}	
	
	
	return (int)(n*prod);
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
