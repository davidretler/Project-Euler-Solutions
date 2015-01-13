/*
Problem 26
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/


//#define DEBUG
#include <stdio.h>

int long_division_cycle(int num, int denom, int offset, int remainder);
void reset_prev(void);

//allocates more memory than necessary
static int prev[1000];

int main(void)
{
	#ifndef DEBUG
	int max_cycle = 0;
	int max_denom = 0;
	for(int d = 1; d < 1000; d++)
	{
		int curr_cycle = long_division_cycle(1, d, 0, 1);
		//printf("%d\t%d\n", d, curr_cycle);
		if(curr_cycle > max_cycle)
		{
			max_cycle = curr_cycle;
			max_denom = d;
		}
	}
	printf("\nMax Cycle: %d\tDenom: %d", max_cycle, max_denom);
	#else
	printf("Cycle: %d", long_division_cycle(1, 111, 0 ,1));
	#endif
	return 0;
}

/*
	Performs long division of num / denom
	Tracks the current remainder and the past remainders
	Once we reach a remainder we've reached before, we must have a cycle
	The length of the cycle (the current offset minus the offset when we first reach the remainder)
	is returned
 */
int long_division_cycle(int num, int denom, int offset, int remainder)
{
	if(offset == 0) reset_prev();
	int curr_digit = remainder/denom;
	
	remainder = remainder - curr_digit * denom;
	if(remainder == 0)
	{
		#ifdef DEBUG
		printf("Terminated.\n");
		#endif
		return 0;
	}
	if(prev[remainder] != -1)
	{
		#ifdef DEBUG
		printf("Cycle found.\n");
		#endif
		return offset - prev[remainder];
	}
	prev[remainder] = offset;
	#ifdef DEBUG
	printf("Current remainder: %d\tLast offset: %d\n", remainder, prev[remainder]);
	#endif
	
	//I <3 recursion
	return long_division_cycle(num, denom, offset + 1, remainder * 10);
}

void reset_prev(void)
{
	for(int i = 0; i < 1000; i++)
	{
		prev[i] = -1;
	}
}