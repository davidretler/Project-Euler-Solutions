/*
Problem 67 (unfinished)

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
*/

#define ROWS 100
//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "Triangle.h"

							
								
long transverse_triangle(void);


int main(void)
{
    long sum = transverse_triangle();
	
    printf("Largest sum found: %ld.\n", sum);
	
    return 0;
}

/*
  Finally an efficient solution to this problem

  The solution works thus:
  by starting at the bottom of the triangle, we can work our way up by taking the largest of the two
  values up to the next row. So rather than testing every single possible sum, which yield exponential 
  complexity, we only need to make n comparisons for n rows, giving us O(n^2) complexity.
 */
long transverse_triangle(void)
{
    //begin on second to last row
    int curr_row = ROWS - 1;
    while(curr_row >= 0)
    {
#ifdef DEBUG
	printf("New row\n");
#endif
	//transverse each column in the row
	for(int col = 0; col <= curr_row; col++)
	{
	    int left = TRIANGLE[curr_row+1][col];
	    int right = TRIANGLE[curr_row+1][col+1];
#ifdef DEBUG
	    printf("%d\t%d\t%d\n",TRIANGLE[curr_row][col],left,right);
#endif
	    TRIANGLE[curr_row][col] += (left > right) ? left : right;
	}
	curr_row--;
    }
    return TRIANGLE[0][0];
}
