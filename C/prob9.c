/* Problem 9

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
	long long int a = 1;
	bool done = false;
	
	while(!done)
	{
		long double var = (((1000L*(long double)a)-500000L)/((long double)a-1000L));
		if (var == ceil(var))
		{
			long long int t =  ceil(var);
			long double p = sqrt(t*t + a*a);
			if (p == ceil(p) || p <= 0) 
			{
				printf("%d %d %d\n", p,t,a);
				printf("%d = %d", sqrt(a*a + t*t), p);
				done = true;
			}
		}
		a++;
	}
	
	return 0;
}