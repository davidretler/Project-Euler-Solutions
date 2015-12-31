#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

bool is_triangle(unsigned long num);
unsigned long triangle_num(int n);
long *k_given_j(long j, long n);
bool sum_is_triangle(int i, int j);

int main() {
	// loop over possible n values
	
	for(int n = 1; n < 10000; n++) {
		// loop over j values
		for(int j = n; j < 100000; j++) {
			// check if there is a solution for k
			long* ks = k_given_j(j, n);
			if (ks[0] != -1) {
				// first root is a integer solution
				if(sum_is_triangle(j,ks[0])) {
					printf("(%d,%d,%lu)\n",n,j,ks[0]);
				}
			} 
			if (ks[1] != -1) {
				// second root is a integer solution
				if(sum_is_triangle(j,ks[1])) {
					printf("(%d,%d,%lu)\n",n,j,ks[1]);
				}
			}
			free(ks);	
		}
	}
	
	/*
	for(int k = 0; k < 10; k++) {
		for(int j = k; j < 10; j++) {
			if(sum_is_triangle(j,k)) {
				printf("(%lu,%lu)\n", j, k);
			}
		}
	}
	*/	
}

unsigned long triangle_num(int n) {
	long i = (long) n;
	return i*(3*i - 1)/2;
}


bool is_triangle(unsigned long num) {
	if(num == 0) return false;
	
	double discriminant = sqrt(1 + 24 * num);
	double n = (1. + discriminant)/6.;
	
	// returns true if and only if n represents an integer
	return floorf(n) == n;
	
}

bool sum_is_triangle(int j, int k) {
	if(j <= 0 || k <= 0) return false;
	return is_triangle(triangle_num(j) + triangle_num(k));
}

// solves the equation P_j - P_k = P_n for k
// returns both roots that may be possible k values. If not valid, returns -1
long *k_given_j(long j, long n) {
	
	double discriminant = 1 - 12*(n*(3*n-1)-j*(3*j-1));
	double num1 = (1. + sqrt(discriminant))/6.;
	double num2 = (1. - sqrt(discriminant))/6.;
	long *k = malloc(2 * sizeof(long));
	
	if(floor(num1) == num1 && num1 > 0) {
		k[0] = floorl(num1);
	} else {
		k[0] = -1;
	}
	
	if(floor(num2) == num2 && num2 > 0) {
		k[1] = floorl(num2);
	} else {
		k[1] = -1;
	}
	
	return k;
}




