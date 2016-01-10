#include "stdio.h"
#include "stdbool.h"
#include "prime_2.h"

bool test(int num);

int main() {
	puts("Initializing...\n");
	initialize_primes();
	puts("Initialized\n\n");

	long sum = 0;
	for(int i = 1; i <= 100000000; i++) {
		if (test(i)) {
			//printf("%d\n", i);
			long old_sum = sum;
			sum += i;
			if(sum < old_sum) {
				puts("Error: overflow.");
			}
		}
		//if(i % 1000 == 0) printf("%d\n", i);
	}

	printf("\n\n Sum: %ld\n", sum);

	return 0;
}

bool test(int num) {
	for (int d = 1; d <= (int)sqrt(num); d++) {
		if(num % d == 0) {
			// if d is a divisor (as is num / d)
			if(!is_prime(d + num / d)) {
				return false;
			}
		}
	}
	return true;
}


