#include "stdio.h"

long ways(int num);
long ways_m(int num, int m);

int main() {
	
	printf("%ld\n", ways(100));
	
	return 0;
}

// number of ways to write num as a sum of 2 or more numbers
long ways(int num) {
	long sum = 0;
	for(int i = 1; i < num; i++) {
		sum += ways_m(num - i, i);
	}
	return sum;
}

// number of ways to write num as a sum of 1 or more numbers less than or equal 
// to m
long ways_m(int num, int m) {
	
	if(num == 1 || m == 1) return 1;
	
	long sum;
	int upper_bound;
	
	if(m > num) {
		sum = 1;
		upper_bound = num - 1;
	} else {
		sum = 0;
		upper_bound = m;
	}
	
	for(int i = 1; i <= upper_bound; i++) {
		sum += ways_m(num - i, i);
	}
	
	return sum;
	
}
