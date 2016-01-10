#include "stdio.h"
#include "stdbool.h"

#define MAX_SAVE 1000

void p76_init();
long ways(int num);
long ways_m(int num, int m);

bool _is_saved[MAX_SAVE][MAX_SAVE];
long _ways_saved[MAX_SAVE][MAX_SAVE];


int main() {
	
	p76_init();
	
	for(int i = 1; i <= 100; i++) {
		printf("%ld\n", ways(i));
	}
	puts("\n");
	return 0;
}

void p76_init() {
	for(int i = 0; i < MAX_SAVE; i++) {
		for(int j = 0; j < MAX_SAVE; j++) {
		_is_saved[i][j] = false;
		}
	}
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
	
	if(num < MAX_SAVE && _is_saved[num][m]) {
		
		return _ways_saved[num][m];
	
	} else {
	
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
		
		if(num < MAX_SAVE) {
			_is_saved[num][m] = true;
			_ways_saved[num][m] = sum;
		}
		
		return sum;
	}	
}
