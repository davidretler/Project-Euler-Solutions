/*Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.*/

#include <stdio.h>

int main(){

	//initial seeds
	int a = 0;
	int b = 1;
	//temp buffer
	int c;
	//sum of even values
	int sum = 0;
	
	//while b, the current fib, is bellow four million
	while(b <= 4000000){
		if(b % 2 == 0)
			sum += b;
		c = a + b;
		a = b;
		b = c;
	}

	printf("%d", sum);

	return 0;
}