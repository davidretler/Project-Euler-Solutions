#include "prime_2.h"
#include "stdio.h"
#include "stdbool.h"

#define SPIRAL_LAYERS 4
#define SPIRAL_MAX (SPIRAL_LAYERS*2-1)



long spiral[SPIRAL_MAX][SPIRAL_MAX];
bool spiral_initialized = false;

void init_spiral();
void fill_spiral();
void display_spiral();
double fraction_prime_diagnals();

int main() {

	init_spiral();
	fill_spiral();
	
	//display_spiral(); 
	
	printf("%lf%% are prime.\n", fraction_prime_diagnals()*100);

	return 0;
}

void fill_spiral() {
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

void display_spiral() {
	if(spiral_initialized == false) {
		init_spiral();
	}
	
	for(int y = 0; y < SPIRAL_MAX; y++) {
		for(int x = 0; x < SPIRAL_MAX; x++) {
			printf("%ld\t", spiral[x][y]);
		}
		printf("\n");
	}
}

void init_spiral() {
	for(int y = 0; y < SPIRAL_MAX; y++) {
		for(int x = 0; x < SPIRAL_MAX; x++) {
			spiral[x][y] = 0;
		}
	}
	spiral_initialized = true;
}

double fraction_prime_diagnals() {
	if(spiral_initialized == false) {
		init_spiral();
	}
	
	long total = 0;
	long primes = 0;
	
	for(int i = 0; i < SPIRAL_MAX; i++) {
		// first diagnal
		long n1 = spiral[i][i];
		// second diagnal
		long n2 = spiral[SPIRAL_MAX - i - 1][i];
		
		printf("(%ld, %ld)\n", n1, n2);
		
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
	
	printf("%ld\n", primes);
	
	return ((double) primes)/((double) total);
}
