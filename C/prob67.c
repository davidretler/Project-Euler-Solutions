/*
Problem 67 (unfinished)

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
*/

#define ROWS 40
//#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "Triangle.h"

							
								
long triangle_sum(int row_offset, int col_offset);

static int call_count = 0;

int main(void)
{
	long sum = triangle_sum(0, 0);
	
	printf("Largest sum found: %ld\nCalled %d times.\n", sum, call_count);
	
	return 0;
}


/*
	I'm going to need a better algorithm if I want to finish this
 */
long triangle_sum(int row_offset, int col_offset)
{
	
	call_count++;
	
	//Out of bounds: too far left or too far down
	if(col_offset > row_offset || col_offset < 0 || row_offset > ROWS)
	{
		//just stop
		printf("ERROR\n");
		return -1;
	}
	//if on the last row
	if(row_offset == ROWS)
	{
		//return the value of this node
		return TRIANGLE[row_offset][col_offset];
	}
	
	
	int left = triangle_sum(row_offset + 1, col_offset);
	int right = triangle_sum(row_offset + 1, col_offset + 1);
	return TRIANGLE[row_offset][col_offset] + (left > right ? left : right);

	
	
}

