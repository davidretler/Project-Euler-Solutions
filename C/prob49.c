/*
  Problem 49
  The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

  There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

  What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <stdio.h>
#include "prime_2.h"
#include <stdbool.h>
#include <string.h>

bool check(int num_one, int num_two, int num_three);
bool is_permutation(char *s_one, char *s_two);

int main(void)
{
    initialize_primes();

    for(int i = 1000; i <= 9999; i++)
    {
	for(int d = 1; d < (10000 - i)/2; d++)
	{
	    int j = i + d;
	    int k = j + d;
	    if(check(i, j, k))
	    {
		printf("(%d, %d, %d) works!  Concatenated: %d%d%d\n", i , j ,k, i , j, k);
	    }
	}
    }
    
    
    return 0;
}

/*
  Checks the three given numbers to see if the match the properties specifies in the problem
*/
bool check(int num_one, int num_two, int num_three)
{
    //if the sequence is not decreasing
    if(num_one >= num_two || num_one >= num_three || num_two >= num_three) return false;
    //if any of the numbers aren't prime
    if(!is_prime(num_one) || !is_prime(num_two) || !is_prime(num_three)) return false;

    char s_one[n_digits(num_one) + 1];
    char s_two[n_digits(num_two) + 1];
    char s_three[n_digits(num_three) + 1];
    sprintf(s_one, "%d", num_one);
    sprintf(s_two, "%d", num_two);
    sprintf(s_three, "%d", num_three);
    //if any is a permutation of the other
    if(!is_permutation(s_one, s_two) || !is_permutation(s_one, s_three) || !is_permutation(s_two, s_three))
    {
	return false;
    }
    
    return true;
}

/*
  Returns true if and only if s_one is a permutation of s_two
*/
bool is_permutation(char *s_one, char *s_two)
{
    int len_one = strlen(s_one);
    int len_two = strlen(s_two);
    if(len_one != len_two) return false;

    bool flag_one[len_one];
    bool flag_two[len_two];
    for(int i = 0; i < len_one; i++)
    {
	flag_one[i] = false;
	flag_two[i] = false;
    }
    //Compare every character in s_one to every character in s_two
    //if none of the characters mach or that ones that do mach have already been matched to a different
    //character, then return false
    for(int i = 0; i < len_one; i++)
    {
	for(int j = 0; j < len_two; j++)
	{
	    if(s_one[i] == s_two[j] && !flag_one[i] && !flag_two[j])
	    {
		flag_one[i] = true;
		flag_two[j] = true;
	    }
	    if(j == len_two - 1 && !flag_one[i])
	    {
		return false;
	    }
	}
    }
    return true;
}
