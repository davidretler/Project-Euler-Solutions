/* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */
	
#include <stdio.h>

int main(void)
{
	int sum = (100)*(100+1)/2; //known closed form
	int sumSq = sum*sum;
	int diff = sumSq - sum;
	printf("%d", diff);
	
	return 0;
}