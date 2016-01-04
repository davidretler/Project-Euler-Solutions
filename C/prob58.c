#include "prime_2.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

//#define SPIRAL_LAYERS 4
#define SPIRAL_MAX (SPIRAL_LAYERS*2-1)

int SPIRAL_LAYERS;
//int SPIRAL_MAX;

int _primes = 0;
int _total = 1;
int layer = 2;

double next_fraction_prime_diagnals();
long diagonal_1(long layer);
long diagonal_2(long layer);
long diagonal_3(long layer);
long diagonal_4(long layer);


int main() {

	puts("Initialzing Primes...\n");
	initialize_primes();
	puts("Initialized\n\n");

	SPIRAL_LAYERS = 13121;

	for(int curr_layers = 2; curr_layers <= SPIRAL_LAYERS; curr_layers++) {
		
		double fraction = next_fraction_prime_diagnals();
	
		printf("%d: %lf%% are prime.\n", curr_layers , fraction*100);
		
		if(fraction < 0.1) {
			printf("Layer: %d\n", curr_layers);
			printf("Side Length: %d\n", 2 * curr_layers - 1);
			printf("(%ld, %ld, %ld, %ld)", diagonal_1(layer), diagonal_2(layer), diagonal_3(layer), diagonal_4(layer));
			break;
		}
	
		
	}
	

	return 0;
}

double next_fraction_prime_diagnals() {

	if(is_prime(diagonal_1(layer))) _primes++;
	if(is_prime(diagonal_2(layer))) _primes++;
	if(is_prime(diagonal_3(layer))) _primes++;
	if(is_prime(diagonal_4(layer))) _primes++;
	
	_total += 4;
	
	// next time check next layer
	layer++;
	
	return ((double) _primes)/((double) _total);
}

// closed form for each diagonal (derived on pen and paper)

long diagonal_1(long layer) {
	return 4*layer*layer - 8*layer + 5;
}

long diagonal_2(long layer) {
	return 4*layer*layer - 6*layer + 3;
}

long diagonal_3(long layer) {
	return 4*layer*layer - 4*layer + 1;
}

long diagonal_4(long layer) {
	return 4*layer*layer - 10*layer + 7;
}
