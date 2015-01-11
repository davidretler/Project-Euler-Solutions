/*
Problem 39
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int triangle_solutions(int p);

//naive brute force. 
//My slowest C solution so far. clocking at 50s, 1000x longer than my most efficient solution. 
int main(void)
{
	int max_value = 0;
	int max_index = 1;
	for(int i = 1; i <= 1000; i++)
	{	
		int t = triangle_solutions(i);
		#ifdef DEBUG
		printf("%d\t%d\n", i, t);
		#endif
		if(t > max_value)
		{
			max_value = t;
			max_index = i;
		}
	}
	
	printf("The maximum number of solutions is %d for p = %d.\n", max_value, max_index);
	
	return 0;
}

//the number of solutions for a given perimeter
int triangle_solutions(int p)
{
	int count = 0;

	//two degrees of freedom == double-for
	//use convention c >= b >= a
	for(int a = 1; a < p; a++)
	{
		for(int b = a; b < p; b++)
		{
			//find c
			double c = sqrt(a*a + b*b);
			//check if c is an integer
			if(ceil(c) == floor(c) && a + b + (int)c == p)
			{
				#ifdef DEBUG
				printf("%d: (%d %d %d)\n", p, a, b, (int)c);
				#endif
				count++;
			}
		}
	}
	
	return count;
}