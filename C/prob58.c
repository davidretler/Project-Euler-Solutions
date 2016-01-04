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

long** init_spiral();
void fill_spiral(long** spiral);
void display_spiral(long** spiral);
double fraction_prime_diagnals(long** spiral, int curr_layers);
double next_fraction_prime_diagnals(long** spiral);
void free_spiral(long** spiral);

int main() {

	puts("Initialzing...\n");
	initialize_primes();
	puts("Initialized\n\n");
	
	SPIRAL_LAYERS = 100000;
	puts("Making Spiral...\n");
	long** spiral = init_spiral();
	fill_spiral(spiral);
	puts("Done\n\n");
	//display_spiral(spiral);

	for(int curr_layers = 2; curr_layers <= SPIRAL_LAYERS; curr_layers++) {
		
		double fraction = next_fraction_prime_diagnals(spiral);
	
		//printf("%d: %lf%% are prime.\n", curr_layers , fraction*100);
		
		if(fraction < 0.1) {
			printf("%d\n", curr_layers);
			break;
		}
	
		
	}
	
	free_spiral(spiral);
	
	
	return 0;
}

void fill_spiral(long** spiral) {
	const int center_x = SPIRAL_MAX/2;
	const int center_y = center_x;
	
	// start at the center of the spiral
	int x = center_x;
	int y = center_y;
	
	// current layer
	int layer = 0;
	
	long c = 1;
	
	while(layer < SPIRAL_LAYERS) {
		
		//printf("(%d,%d)\n", x, y);
		
		spiral[x][y] = c++;
		
		// get next (x,y)
		if(x - center_x == 0 && y - center_y == 0) {
			// special case, (0,0)
			layer++;
			x++;
		} else if (x - center_x == layer) {
			// we're on right edge
			if (y - center_y == -layer) {
				// we're on top right, move left
				x--;
			} else if (y - center_y == layer) {
				// we're on the bottom right, next layer
				x++;
				layer++;
			} else {
				// right middle, move up
				y--;
			}
		} else if(x- center_x == -layer) {
			// we're on the left edge
			if (y - center_y == -layer) {
				// we're on top left, move down
				y++;
			} else if (y - center_y == layer) {
				// bottom left, move right
				x++;
			} else {
				// left middle, move down
				y++;
			}
		} else {
			// neither left nor right edge
			if (y - center_y == -layer) {
				// top middle, move left
				x--;
			} else {
				// bottom middle, move right
				x++;
			}
		}
	} 
}

void display_spiral(long** spiral) {

	for(int y = 0; y < SPIRAL_MAX; y++) {
		for(int x = 0; x < SPIRAL_MAX; x++) {
			printf("%ld\t", spiral[x][y]);
		}
		printf("\n");
	}
}

long** init_spiral() {

	long** spiral = malloc(SPIRAL_MAX * sizeof(long*));
	for(int i = 0; i < SPIRAL_MAX; i++) {
		spiral[i] = malloc(SPIRAL_MAX * sizeof(long));
	}
	for(int y = 0; y < SPIRAL_MAX; y++) {
		for(int x = 0; x < SPIRAL_MAX; x++) {
			spiral[x][y] = 0;
		}
	}
	return spiral;
}

double fraction_prime_diagnals(long** spiral, int layers) {

	//int max = 2*layers - 1;
	int center_x = SPIRAL_MAX / 2;
	int center_y = center_x;
	int limit_low = center_x - (layers - 1);
	int limit_high = center_x + (layers - 1);

	long total = 0;
	long primes = 0;
	
	for(int i = limit_low; i <= limit_high; i++) {
		// first diagnal
		long n1 = spiral[i][i];
		// second diagnal
		long n2 = spiral[SPIRAL_MAX - i - 1][i];
		
		// printf("(%ld, %ld)\n", n1, n2);
		
		if(is_prime(n1)) {
			primes++;
		}
		// make sure not to count center twice (doesn't *really* matter as 1 is not prime)
		if(n1 != n2 && is_prime(n2)) {
			primes++;
		}
		
		total += 2;
	}
	total--; // subtract 1 because we counted the middle twice
	
	//printf("%ld\n", primes);
	
	return ((double) primes)/((double) total);
}

void free_spiral(long** spiral) {
	for(int i = 0; i < SPIRAL_MAX; i++) {
		free(spiral[i]);
	}
	free(spiral);
}

double next_fraction_prime_diagnals(long** spiral) {
	int center_x = SPIRAL_MAX / 2;
	int center_y = center_x;
	
	int x1 = center_x + (layer - 1);
	int x2 = center_x - (layer - 1);
	
	// check all 4 new numbers
	if(is_prime(spiral[x1][x1])) _primes++;
	if(is_prime(spiral[x1][x2])) _primes++;
	if(is_prime(spiral[x2][x1])) _primes++;
	if(is_prime(spiral[x2][x2])) _primes++;
	
	_total += 4;
	
	// next time check next layer
	layer++;
	
	return ((double) _primes)/((double) _total);
}
