/*
  Problem 33
  The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

  We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

  There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

  If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool cancel_digits(int num, int denom, int *canceled);
void lowest_terms(int num, int denom, int *terms);

int main(void)
{
    int canceled[2];
    int num_prod = 1;
    int denom_prod = 1;
    for(int i = 10; i < 100; i++)
    {
	for(int j = i+1; j < 100; j++)
	{
	    if(cancel_digits(i, j, canceled))
	    {
		if((double)i/(double)j == (double)canceled[0]/(double)canceled[1] && i % 10 != 0)
		{
		    printf("%d/%d\t=\t%d/%d!\n", i, j, canceled[0], canceled[1]);
		    num_prod = num_prod * i;
		    denom_prod = denom_prod * j;
		}
	    }
	}
    }

    printf("\nFinal fraction: %d/%d\n", num_prod, denom_prod);
    lowest_terms(num_prod, denom_prod, canceled);
    printf("Lowest terms: %d/%d\n", canceled[0], canceled[1]);
    
    return 0;
}

/*
  Store the numerator and denominator of the given fraction in lowester terms in *terms
 */
void lowest_terms(int num, int denom, int *terms)
{
    bool canceling = true;
    int t = 2;
    while(canceling)
    {
	if(num % t == 0 && denom % t == 0)
	{
	    num = num / t;
	    denom = denom / t;
	}
	else
	{
	    t++;
	}
	if(t > num || t > denom)
	{
	    canceling = false;
	}
    }
    terms[0] = num;
    terms[1] = denom;
}



/*
  Cancels the digits of the numerator and denominator if such a operation can be performed
 */
bool cancel_digits(int num, int denom, int *canceled)
{
    char num_s[3];
    char denom_s[3];
    sprintf(num_s, "%d", num);
    sprintf(denom_s, "%d", denom);
    bool cancel = false;

    /*
      I should have does this part with a double-for to make the solution more general
      rather than just for the case of 2 digits...
     */
    
    if(num_s[0] == denom_s[0])
    {
	num_s[0] = num_s[1];
	num_s[1] = 0;
	denom_s[0] = denom_s[1];
	denom_s[1] = 0;
	cancel = true;
    }
    else if(num_s[0] == denom_s[1])
    {
	num_s[0] = num_s[1];
	num_s[1] = 0;
	denom_s[1] = 0;
	cancel = true;
    }
    else if(num_s[1] == denom_s[0])
    {
	num_s[1] = 0;
	denom_s[0] = denom_s[1];
	denom_s[1] = 0;
	cancel = true;
    }
    else if(num_s[1] == denom_s[1])
    {
	num_s[1] = 0;
	denom_s[1] = 0;
	cancel = true;
    }
    canceled[0] = atoi(num_s);
    canceled[1] = atoi(denom_s);
    return cancel;
}

