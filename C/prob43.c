#include <stdio.h>

#define number_of_pandigitals  3628800

void init_pan();
void _init_pan(int d, int curr_num[10]);
long long get_num(int curr_num[10]);
int digit_used(int digit, int digits[10]);
int digit_at(long long number, int digit);
int test_number(long long number);
int is_pandigital(int num[10]);

// store all of the pandigitals
long long pandigitals[number_of_pandigitals];
// number of pandigitals found so far
int curr_generated = 0;

int main() {
	init_pan();
	
}

// initializes the list of pandigitals
void init_pan() {
	_init_pan(1, (int[10]){-1,-1,-1,-1,-1,-1,-1,-1,-1,-1});
	long long sum = 0;
	printf("%u generated.\n", curr_generated);
	for(int i = 0; i < number_of_pandigitals; i++) {
		long long num = pandigitals[i];
		if(test_number(num) == 1) {
			printf("%llu\n", num);
			sum = sum + num;
		}
	}
	printf("Done\n");
	printf("%llu is the sum.", sum);
}

void _init_pan(int d, int curr_num[10]) {
	
	if(d == 11) {
		// if on the last digit, add the number to the list and return
		pandigitals[curr_generated] = get_num(curr_num);
		curr_generated++;
		//if(is_pandigital(curr_num) == 0) {
		//	printf("%u\n", get_num(curr_num));
		//}
		return;
	} else {
		// not on last digits, try all possible next digits
		for(int next_digit = 0; next_digit < 10; next_digit++) {
			if(digit_used(next_digit, curr_num) == 0) {
				// digit has not been used yet, use it
				
				// create copy of current number
				int new_num[10];
				for(int i = 0; i < 10; i++) {
					new_num[i] = curr_num[i];
				}
				// change digit to make new number
				new_num[d-1] = next_digit;
				// recursively find all the new numbers
				_init_pan(d + 1, new_num);
			} 
		}
	}
}

// get the number from the array of digits
long long get_num(int curr_num[10]) {
	int radix = 10;
	long long curr_base = 1;
	long long result = 0;
	for(int i = 9; i >=0; i--) {
		result += curr_base * curr_num[i];
		curr_base *= radix;
	}
	return result;
}

int digit_used(int digit, int digits[10]) {
	for(int i = 0; i < 10; i++) {
		if(digits[i] == digit) {
			return 1;
		}
	}
	return 0;
}

int digit_at(long long number, int digit) {
	long long base = 1;
	int radix = 10;
	for(int i = 0; i != digit; i++) {
		base = base*radix;
	}
	return number / base % 10;
}

int test_number(long long number) {
	int num1 = 100*digit_at(number, 10-2) + 10*digit_at(number, 10-3) + digit_at(number, 10-4);
	int num2 = 100*digit_at(number, 10-3) + 10*digit_at(number, 10-4) + digit_at(number, 10-5);
	int num3 = 100*digit_at(number, 10-4) + 10*digit_at(number, 10-5) + digit_at(number, 10-6);
	int num4 = 100*digit_at(number, 10-5) + 10*digit_at(number, 10-6) + digit_at(number, 10-7);
	int num5 = 100*digit_at(number, 10-6) + 10*digit_at(number, 10-7) + digit_at(number, 10-8);
	int num6 = 100*digit_at(number, 10-7) + 10*digit_at(number, 10-8) + digit_at(number, 10-9);
	int num7 = 100*digit_at(number, 10-8) + 10*digit_at(number, 10-9) + digit_at(number, 10-10);
	return (num1 % 2 == 0) && (num2 % 3 == 0) && (num3 % 5 == 0) && (num4 % 7 == 0) && (num5 % 11 == 0) && (num6 % 13 ==0) && (num7 % 17 == 0);
}

int is_pandigital(int num[10]) {
	int used[10] = {0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < 10; i++) {
		used[num[i]] = 1;
	}
	for(int i = 0; i < 10; i++) {
		if(used[i] == 0) {
			return 0;
		}
	}
	return 1;
}
