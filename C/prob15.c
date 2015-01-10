/*
Problem 15 (Unfinished)

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

//#define DEBUG
#define LATTICE_SIZE 20

#include <stdio.h>
#include <stdlib.h>

long lattice_paths(int x, int y, long cached[LATTICE_SIZE+1][LATTICE_SIZE+1]);
void initialize_cache(long cached[LATTICE_SIZE+1][LATTICE_SIZE+1]);

int main(void)
{

	long cached[LATTICE_SIZE+1][LATTICE_SIZE+1];
	initialize_cache(cached);
	
	long num_paths = lattice_paths(0, 0, cached);

	printf("Number of paths: %ld\n", num_paths);

	return 0;
}

//Got the algorithm to run in .044s using an optimization 
long lattice_paths(int x, int y, long cached[LATTICE_SIZE+1][LATTICE_SIZE+1])
{
	#ifdef DEBUG
	printf("Checking (%d, %d)\n", x, y);
	#endif

	//if we're out of bounds
	if(x > LATTICE_SIZE || y > LATTICE_SIZE || x < 0 || y < 0)
	{
		
		#ifdef DEBUG
		printf("Stopping!\n");
		#endif
		return 0;
	}
	
	//if we already know the number of of paths from this point
	if(cached[x][y] != 0)
	{
		#ifdef DEBUG
		printf("Cached! %ld\n", cached[x][y]);
		#endif
		return cached[x][y];
	}
	
	//if we've reached the end!
	if(x == LATTICE_SIZE && y == LATTICE_SIZE)
	{
		#ifdef DEBUG
		printf("End!\n");
		#endif
		return 1;
	}


	//cache the number of ways from this point to zero
	//sum of two possible paths: right or down
	cached[x][y] = lattice_paths(x + 1, y, cached) + lattice_paths(x, y + 1, cached);
	
	#ifdef DEBUG
	printf("From (%d, %d) there are %ld paths.\n", x, y, cached[x][y]);
	#endif
	return cached[x][y];
}


void initialize_cache(long cached[LATTICE_SIZE+1][LATTICE_SIZE+1])
{
	for(int i = 0; i <= LATTICE_SIZE; i++)
	{
		for(int j = 0; j <= LATTICE_SIZE; j++)
		{	
			cached[i][j] = 0;
		}
	}
}