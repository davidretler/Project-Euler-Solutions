/*
  Problem 38
  Take the number 192 and multiply it by each of 1, 2, and 3:

  192 × 1 = 192
  192 × 2 = 384
  192 × 3 = 576
  By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

  The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

  What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool is_n_pandigital(int number, int n);
int check(int number, int n);
int n_digits(int num);

/*
  Note: for some reason this code does not work when -O1 or -O3 is enables
  But, befuddlingly, it works for -O2 and of course -O0
 */
int main(void)
{
    int curr_max = 0;
    int max_i = 0;
    int max_n = 0;
    bool looping = true;
    int i = 1;
    while(looping)
    {
	int n = 2;
	int curr_check = 0;
	
	while(curr_check != -3 && curr_check != -1)
	{
	    curr_check = check(i, n);
	    if(curr_check > 0)
	    {
		if(curr_max < curr_check)
		{
		    max_i = i;
		    max_n = n;
		    curr_max = curr_check;
		}
	    }
	    n++;
	}
	//break if the numbers are too large, even for the smallest n
	if(n == 3 && curr_check == -3) looping = false;
	i++;
    }

    printf("Largest 1-to-9 pandigital: %d\ni = %d\nn = %d\n", check(max_i, max_n), max_i, max_n);  
   
    return 0;
}

/*
  Returns an integer code based on the nature of the number
  Expected:
  any positive number -- number is the correct length and is pandigital
  Error:
  -1 -- number is correct length but not pandigital
  -2 -- number is too short
  -3 -- number is too long
*/
int check(int number, int n)
{
    int digits = 0;
    //int prods[n];
    char prod_s[10];
    //start the string as blank
    prod_s[0] = 0;
    for(int i = 1; i <= n; i++)
    {
	int curr_prod = number * i;
	digits += n_digits(curr_prod);

	if(digits > 9) return -3;
	
	char curr_prod_s[n_digits(curr_prod) + 1];
	sprintf(curr_prod_s, "%d", curr_prod);
	strcat(prod_s, curr_prod_s);
    }

    if(digits != 9) return -2;
    
    if(is_n_pandigital(atoi(prod_s), 9))
    {
	return atoi(prod_s);
    }
    else
    {
	return -1;
    }
}

/*
  Returns whether num is 1-to-n-pandigital
*/
bool is_n_pandigital(int num, int n)
{
    //escape if wrong number of digits
    if(n_digits(num) != n) return false;

    bool flag[] = {false, false, false, false, false, false, false, false, false};
    char num_s[n + 1];
    sprintf(num_s, "%d", num);
    for(int i = 0; i < n; i++)
    {
	int curr_digit = num_s[i] - '0';
	if(!flag[curr_digit] && curr_digit != 0)
	{
	    flag[curr_digit] = true;
	}
	else
	{
	    return false;
	}
    }
    return true;
}

int n_digits(int num)
{
    return (int)ceil(log(num)/log(10));
}
