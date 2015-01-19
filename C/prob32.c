/*
  Problem 32
  We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

  The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

  Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

  HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

//#define DEBUG

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define I_MAX 999999
#define J_MAX 999999
#define CACHE_LIMIT 10000000


bool is_n_pandigital(int num, int n);
int n_digits(int num);
int to_str_cat(int num_one, int num_two, int num_three);
int check(int num_1, int num_2);
bool check_cache(int num);
void initialize_cache(void);

static int cached[CACHE_LIMIT];
static int current_capacity = 0;

int main(void)
{
    initialize_cache();

    printf("Done initilizing\n");
    long sum = 0;
    int curr_check;
    int i = 1;
    int j = 1;
    bool looping_j = true;
    while(i < I_MAX)
    {
	while(looping_j)
	{
	    j++;
	    curr_check = check(i, j);
	    //printf("(%d, %d)\tcheck: %d\n", i, j, check(i, j));
	    if(curr_check == 1)
	    {
		sum += i*j;
		printf("%d\t(%d, %d)\n", i*j, i, j);
	    }
	    //escape if our current number of digits is too high
	    else if(curr_check == -3)
	    {
		//printf("Escaping\t(%d, %d)\n", i ,j);
		looping_j = false;
	    }
	}
	i++;
	j = 1;
	looping_j = true;
    }

    printf("\nAnswer (sum): %ld\n", sum);

    return 0;
}

/*
  Checks the current multiplicand-multiple pair:
  1 -- works
  -3 -- too high
  -1 not too high but doesn't work
  -4 -- a number was 0
 */
int check(int num_1, int num_2)
{
    if(num_1 == 0 || num_2 == 0) return -4;
    int prod = num_1 * num_2;
    int tot_dig = (n_digits(num_1) + n_digits(num_2) + n_digits(prod));
    if(tot_dig < 9) return -1;
    if(tot_dig > 10) return -3;
    if(tot_dig == 9)
    {
	int res = to_str_cat(num_1, num_2, prod);
	if(is_n_pandigital(res, 9) && !check_cache(prod))
	{
	    cached[current_capacity++] = prod;
	    return 1;
	}
    }
    return -1;
}

/*
  Checks the cache to see if num has already been used (simple linear sort)
 */
bool check_cache(int num)
{
    for(int i = 0; i < current_capacity; i++)
    {
	if(cached[i] == num) return true;
    }
    return false;
}

/*
  Initializes the cache values
*/
void initialize_cache(void)
{
    for(int i = 0; i < CACHE_LIMIT; i++)
    {
	cached[i] = 0;
    }
}

/*
  Makes str contain the digits of num_one concatenated with the digits of the other numbers
 */
int to_str_cat(int num_one, int num_two, int num_three)
{
    char num_s[10];
    char str[10];
    str[0] = 0;
    sprintf(num_s, "%d", num_one);
    strcat(str, num_s);
    sprintf(num_s, "%d", num_two);
    strcat(str, num_s);
    sprintf(num_s, "%d", num_three);
    strcat(str, num_s);
    str[9] = 0;
    return atoi(str);
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
	if(!flag[curr_digit - 1] && curr_digit != 0)
	{
	    flag[curr_digit - 1] = true;
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
