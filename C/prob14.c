/*
Problem 14 (UNFINISHED)
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
*/

//#define DEBUG
#define ANS_SIZE 2482111348


#include <stdio.h>



long collatz(long n, long d_curr, long d_tot, unsigned short* answers);
void initialize(unsigned short* answers);
long collatz_s(long n);



int main(void)
{
	//unsigned short answers[ANS_SIZE];
	//initialize(answers);
	
	long highest_n = 1;
	long highest_depth = 1;
	long curr_depth;
	
	for(int curr_n = 1; curr_n < 1000000; curr_n++)
	{
		curr_depth = collatz_s(curr_n);
		if(curr_depth > highest_depth)
		{
			highest_depth = curr_depth;
			highest_n = curr_n;
		}
		#ifdef DEBUG
		printf("%d:\t%ld\n", curr_n, curr_depth);
		#endif
	}
	
	printf("Highest Collatz sequence betweem 0 and 1000000 is %ld with depth %ld.\n", highest_n, highest_depth);
	
	printf("%ld", collatz_s(113383));
	return 0;
}

/*
Returns the length of the chain leading from n to 1 on the collatz chain
	n -- current number
	d_curr -- how far from the first n we arr
	d_tot -- how far from 1 the original n was
	
	the distance from the current n from 1 is d_tot - d_curr.
	
	This is more time efficient than collatz_s() but uses much more memory.
	I wrote this first, but it turns out a much simple implementation worked
	and was fast enough to warrent not using this one.
*/
long collatz(long n, long d_curr, long d_tot, unsigned short* answers)
{
	
	if(answers[n] != 0)
	{
		//if we already know the length of this number to 1, return the total path to 1 by adding
		//d_curr
		printf("FOUND ANSWER! n:\t%ld\n", n);
		return answers[n] + d_curr ; 
	}
	if(n == 1)
	{
		//Once we're at 1, return the length of the path to 1
		return d_tot;
	}
	
	
	//take the next collatz number
	n = (n % 2 == 0) ? n/2 : 3*n + 1;
	
	long tot = collatz(n, d_curr + 1, d_tot + 1, answers);
	answers[n] = tot - d_curr;
	

	
	return answers[n] + d_curr;	
}

/*
	A much more naive implementation that in the end was actually better.
*/
long collatz_s(long n)
{
	long count = 0;
	while(n != 1)
	{
		count++;
		n = (n % 2 == 0) ? n/2 : 3*n+1;
	

		#ifdef DEBUG
		printf("%ld:\t%ld\n", n, count);
		#endif
	
	}
	return count;
}


//Initializes the array of answers. Not needed with the bruteforce solution.
void initialize(unsigned short* answers)
{
	#ifdef DEBUG
	printf("Initializing\n");
	#endif
	for(int i = 0; i < ANS_SIZE; i++)
	{
		answers[i] = 0;
	}
}