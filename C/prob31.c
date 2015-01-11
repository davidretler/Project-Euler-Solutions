/*
Problem 31
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/



#include <stdio.h>

int main(void)
{
	long count  = 0;
	for(int one = 0; one <= 200; one++)
	for(int two = 0; two <= 100 - one/2; two++)
	for(int five = 0; five <= 40 - one/5 - (2*two)/5 ; five++)
	for(int ten = 0; ten <= 20 - one/10 - two/5 - five/2; ten++)
	for(int twenty = 0; twenty <= 10 - one/20 - two/10 - five/4 - ten/2; twenty++)
	for(int fifty = 0; fifty <= 4 - one/50 - two/25 - five/10 - ten/5 - (2*twenty)/5; fifty++)
	for(int one_hundred = 0; one_hundred <= 2 - one/100 - two/50 - five/20 - ten/10 - twenty/5 - fifty/2; one_hundred++)
	for(int two_hundred = 0; two_hundred <= 1; two_hundred++)
		if(one + 2*two + 5*five + 10*ten + 20*twenty + 50*fifty + 100*one_hundred + 200*two_hundred == 200)
			count++;

	printf("There are %ld possible combinations!\n", count);
}