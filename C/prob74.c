#include "stdio.h"
#include "stdbool.h"
#include "math.h"

// if the chain reaches one of these terms, it repeates forever
const int repeating[] = {169, 363601, 1454, 871, 45361, 872, 45362, 145, 1, 2, 40585};
// store factorials to avoid unecessary computation
const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int nth_digit(int num, int digit);
long sum_of_factorial_digits(int num);
long chain_length(long num);
bool is_repeating(int num);

int main() {

	int sum = 0;
	for(int i = 1; i < 1000000; i++) {
		int curr_chain = chain_length(i);
		
		if(curr_chain == 60) {
			sum++;
			//printf("%d\n", i);
		}
	}
	
	printf("\nSum: %d\n", sum);

	return 0;
}

long chain_length(long num) {
	int length = 0;
	int first_repeat = 0;
	while(true) {
		if(is_repeating(num)) {
			if (first_repeat == 0) {
				first_repeat = num;
			} else if (num == first_repeat) {
				break;
			}
		}
		num = sum_of_factorial_digits(num);
		length++;
	}
	return length;
	
}

bool is_repeating(int num) {
	for(int i = 0; i < sizeof(repeating)/sizeof(int); i++) {
		if(repeating[i] == num) {
			return true;
		}	
	}
	return false;
}

int nth_digit(int num, int digit) {
	return num / (int)pow(10, digit) % 10;
}

long sum_of_factorial_digits(int num) {
	
	long sum = 0;
	for(int n = 0; n <= (int)floor(log(num)/log(10)); n++) {
		sum += factorial[nth_digit(num, n)];
	}
	return sum;
	
}
