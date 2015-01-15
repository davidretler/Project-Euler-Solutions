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
  04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

*/

#define ROWS 14
//#define DEBUG

#include <stdio.h>
#include <stdlib.h>

static int TRIANGLE[ROWS+1][ROWS+1] = {{75, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
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

							
								  
long transverse_triangle(void);


int main(void)
{
    printf("Largest sum found: %ld.\n", transverse_triangle());
	
    return 0;
}

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
