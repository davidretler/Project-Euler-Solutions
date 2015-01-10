/*
Problem 15 (Unfinished)

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

//#define DEBUG
#define LATTICE_SIZE 20

#include <stdio.h>
#include <stdlib.h>

void lattice_paths(long* num_paths, int x, int y);

int main(void)
{
	long* num_paths = malloc(sizeof (long int));
	*num_paths = 0;

	lattice_paths(num_paths, 0, 0);
	
	printf("Number of paths: %ld\n", *num_paths);
	
	return 0;
}

//This algorithm *should* work but it's taking forever to run
void lattice_paths(long* num_paths, int x, int y)
{

	//bottom right corner
	if(x == LATTICE_SIZE && y == LATTICE_SIZE)
	{
		#ifdef DEBUG
		//printf("Found corner! n = %ld\n", (*num_paths));
		#endif
		(*num_paths)++;
		return;
	}
	//out of bounds (or if num_paths overflowed)
	if(x > LATTICE_SIZE || y > LATTICE_SIZE || x < 0 || y < 0 || *num_paths < 0)
	{
		
		#ifdef DEBUG
		printf("Stopping!\n");
		#endif
		return;
	}
	
	
	//branch down
	#ifdef DEBUG
	printf("Branching down (%d, %d)\n", x, y);
	#endif
	lattice_paths(num_paths, x + 1, y);
	//branch right
	#ifdef DEBUG
	printf("Branching right (%d, %d)\n", x, y);
	#endif
	lattice_paths(num_paths, x, y + 1);
}