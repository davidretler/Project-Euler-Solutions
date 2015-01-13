/*
  Problem 36
  The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

  Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

  (Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
bool check_palindrome(char* string);
static char* i_to_base2(long num);
int n_digits(long n);


int main(void)
{
     int sum = 0;
     for(int i = 1; i < 1000000; i++)
     {

	  char* p_base_2 = i_to_base2(i);
	  char p_base_10[20];
	  sprintf(p_base_10, "%d", i);
	  bool palindrome_2 = check_palindrome(p_base_2);
	  bool palindrome_10 = check_palindrome(p_base_10);
	  if(palindrome_2 && palindrome_10)
	  {
	       printf("%d\t%s\n", i, p_base_2);
	       sum += i;
	  }
     }	
	
     printf("The sum of all the palindromes in both bases 2 and 10 under 1000000 is %d.\n", sum);
     return 0;


}

//Returns the number of digits in the number
int n_digits(long n)
{
     return ceil(log(n)/log(10));
}

//Returns a string the represents the number in base 2
static char* i_to_base2(long num)
{
     //last char is length
     static char base_two[20];

     for(int j = 0; j < 20; j++)
     {
	  base_two[j] = '0';
     }
	
     int digits = floor(log(num)/log(2)); 	//the number of binary digits
     for(int i = digits; i >= 0; --i)
     {
	  //if the number minus 2^i is not negative
	  if(num - (1 << i) >= 0)
	  {
	       base_two[digits - i] = '1';
	       num -= (1 << i);
	  }
     }
     base_two[digits + 1] = '\0';
	
     return base_two;
	
}

//Checks if a string of char is a palindrome
bool check_palindrome(char* string)
{
     int length = strlen(string);
     for(int i = 0; i < length/2; i++)
     {
	  if(string[i] != string[length - i - 1])
	       return false;
     }
     return true;
}
