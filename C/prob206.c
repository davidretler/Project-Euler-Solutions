#include "stdio.h"
#include "stdbool.h"
#include "math.h"

bool check(unsigned long num);
int digit_at(unsigned long num, int pos);

int main() {

	//start at upper bound and go down
	for(unsigned long n = 1389026624; n > 1; n--) {
		if(check(n*n)) {
			printf("%lu works! (%lu)\n", n, n*n);
			return 0;
		}
	}
	
	puts("Search failed.\n");
	return 1;

}

bool check(unsigned long num) {
	
	if(digit_at(num, 0) != 0) {
		//printf("0 != 0\n");
		return false;
	}
	
	int a = 9;
	for(int i = 2; i < 19; i += 2) {
		if(digit_at(num, i) != a) {
			//printf("%d != %d (%d)\n", i, a, digit_at(num, i));
			return false;
		}
		
		a--;
	}
	
	return true;
}

int digit_at(unsigned long num, int pos) {
	int radix = 10;
	
	long power = pow(radix, pos);
	
	return num/power  % 10;
}


