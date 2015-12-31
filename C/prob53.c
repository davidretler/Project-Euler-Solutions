#include "stdio.h"

double nCr(int n, int r);


int main() {
	int sum = 0;
	for(int n = 1; n <= 100; n++) {
		for(int r = 0; r <= n; r++) {
			if(nCr(n,r) > 1000000.) {
				//printf("%dC%d > 1000000.\n", n, r);
				sum++;
			}
		}
	}
	
	printf("There are %d such combinations.\n", sum);
}

// nCr = n!/(r!*(n-r)!)
double nCr(int n, int r) {
	if(r > n) return -1;
	// find n!/r!
	double prod = 1;
	for(int i = n; i > r; i--) {
		prod *= i;
	}
	// divide by (n-r)!
	for(int i = n - r; i > 1; i--) {
		prod /= i;
	}
	return prod;
}

