/*
Problem 18

Find the maximum total from top to bottom of the triangle below.

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04  62 98 27 23 09 70 98 73 93 38 53 60 04 23

*/

#define ROWS 14
//#define DEBUG

#include <stdio.h>
#include <stdlib.h>

const int TRIANGLE[ROWS+1][ROWS+1] = {{75, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
									{95, 64, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
									{17, 47, 82, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
									{18, 35, 87, 10, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
									{20, 04, 82, 47, 65, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
									{19,  1, 23, 75,  3, 34, 00, 00, 00, 00, 00, 00, 00, 00, 00},
							    	{88,  2, 77, 73,  7, 63, 67, 00, 00, 00, 00, 00, 00, 00, 00},
									{99, 65,  4, 28,  6, 16, 70, 92, 00, 00, 00, 00, 00, 00, 00},
									{41, 41, 26, 56, 83, 40, 80, 70, 33, 00, 00, 00, 00, 00, 00},
									{41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 00, 00, 00, 00, 00},
									{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 00, 00, 00, 00},
									{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 00, 00, 00},
									{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 00, 00},
									{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 00}, 
									{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}};

							
								
long triangle_sum(int row_offset, int col_offset);

static int call_count = 0;

int main(void)
{
	long sum = triangle_sum(0, 0);
	
	printf("Largest sum found: %ld\nCalled %d times.\n", sum, call_count);
	
	return 0;
}


/*
	A more efficient approach. (Okay after testing turns out this is exactly the same solution)

	row_offset -- the index of the first row of the tree we're traversing (0 is first)
	col_offset -- the index of the first column of the tree we're traversing
	
	Basically, keep splitting into sub-trees and take the sub-tree that's larger.
	
	Extremely efficient, runs in 0.02 seconds.
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

