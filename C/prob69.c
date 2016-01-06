#include "stdio.h"
#include "stdbool.h"
#include "prime_2.h"

#define GCD_SAVE 20000

int totient(int num);
int gcd(int p, int q);
void init_saved();

bool _is_gcd_saved[GCD_SAVE][GCD_SAVE];
int _gcd_saved[GCD_SAVE][GCD_SAVE];

int main() {

	puts("Initializing prime list...\n");
	initialize_primes();
	puts("Initialized prime list\n\n");
	
	init_saved();
	
	double max = 1;
	int max_n = 0;
	for(int n = 2; n <= 1000000; n++) {
		double curr = ((double)n)/totient(n);
		if(curr > max) {
			max = curr;
			max_n = n;
			printf("%d\n", n);
		}
		if(n % 100 == 0) {
			printf("(%d)\n", n);
		}
	}
	
	printf("%d yeilds max value %f", max_n, max);


	return 0;
}

// the number of numbers less than n which are relatively prime to num
int totient(int num) {
	
	int sum = 1; //start at 1 because 1 is always relatively prime to num
	
	for(int n = 2; n < num; n++) {
		
		bool relatively_prime = true;
		int curr_p = 0;
		long _prime = 2;
		
		if(gcd(num, n) == 1) {
			//printf("%d, ", n);
			sum++;
		}
	}
	
	//printf("\n");
	
	return sum;
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
}
