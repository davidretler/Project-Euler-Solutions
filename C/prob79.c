/*
  Problem 79
  A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

  The text file, keylog.txt, contains fifty successful login attempts.

  Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "numbers.h"

#define ROW_LENGTH 3
#define NUM_ROWS 50

bool check(long test_password);
int n_digits(long num);

int main(void)
{
    long i = 100;
    while(!check(i)) i++;
    printf("%ld\n", i);
    return 0;
}

/*
  Returns true if and only if the given password is valid for all attempts
 */
bool check(long test_password)
{
    int digits = n_digits(test_password);
    if(digits < 3) return false;
    char test_s[digits +1];
    sprintf(test_s, "%ld", test_password);

    //iterate over all three numbers
    for(int row = 0; row < NUM_ROWS; row++)
    {
	int test_index = 0;
	int start = 0;
	char curr_row[ROW_LENGTH];
	for(int i = 0; i < ROW_LENGTH; i++) curr_row[i] = attempts[row][i];
	while(test_index < ROW_LENGTH)
	{
	    //while the current index is less than the length of the password
	    while(start < digits)
	    {
		if(test_s[start] == curr_row[test_index])
		{
		    test_index++;
		}
		start++;
		//if we're at the end of the number and haven't matched the digits
		if(start == digits && test_index < 3)
		{
		    return false;
		}
	    }
	}
    }
    return true;
}

int n_digits(long num)
{
    return (int)ceil(log(num)/log(10));
}
