// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function Prototype deceleration
// General purpose functions
void randomFill (int n, int inputArray[][n]);
void printArray (int n, int inputArray[][n]);
void findMaxRow (int n, int inputArray[][n], int *maxRowIndex, int *numberOfOnes);

// Main program function
int main() {

	clock_t begin, end;						// for time calculation
	double timeSpent;						// processing time
	int maxRowIndex, numberOfOnes;			// to store search result
	
	// prompt user to enter an array size, and get his input
	int n; 									// number of elements in array
	
	while (1)
	{	
		printf("Please enter a list size (n < 2 to exit): ");
		scanf("%d",&n);
	
		// exit loop if user enters 0 or 1
		if (n < 2)
			break;
			
		// declare two arrays of required size and fill them with random numbers
		// between MAX_NUMBER and MIN_NUMBER
		int array[n][n];						// array with ones and zeros
		randomFill (n, array);					// fill array with ones and zeros
		printArray (n, array);					// print array
		
		// sort array1 using heapSort
		begin = clock();						// start the clock
		findMaxRow (n, array, &maxRowIndex, &numberOfOnes);
		end = clock();							// stop the clock, and calculate time spent
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		
		printf("max number of ones are (%d) and are found at row (%d)\n", numberOfOnes, maxRowIndex+1);
	}

	// return 0 to indicate successful termination
	return 0;
}


/*randomFill function
Objective: 		fill an array with ones and zeros where ones are before zeros for each row

Inputs:
n:			dimension of n*n array 
inputArray:	array to fill with ones and zeros

Outputs:
the inputArray is filled with ones and zeros
*/

void randomFill (int n, int inputArray[][n])
{
	srand (time(NULL));				// seed the random generator 
	int i, j;						// loop counters
	int nn;							// number of ones in a row
	
	// fill array with random numbers between MAX_NUMBER and MIN_NUMBER
	for (i = 0 ; i < n ; i++)
	{
		// generate a random number for filling the row with ones
		// an integer between 0 and n-1
		nn = (rand() % (n));
		
		// insert ones
		for (j = 0; j <= nn; j++)
			inputArray[i][j] = 1;
			
		// insert zeros
		for (; j < n; j++)
			inputArray[i][j] = 0;
	}
	
	// terminate function
	return;	// optional
}

/*printArray function
Objective: 		Print the contents of a two dimensitional input array

Inputs:
n:			dimension of n*n array 
inputArray:	array to print

Outputs:
the inputArray is printed if it has less than 10 elements
*/

void printArray (int n, int inputArray[][n])
{
	// if the number of elements is bigger than 10
	// print processing time only
	if (n > 10)
	{
		return;
	}
	
	// print array contents 
	int i, j;							// loop counter
	for (i = 0 ; i < n ; i++)			// print the contents of the array
	{
		for (j = 0; j < n; j++)
		{
			// print row
			if (j < (n-1))
				printf("%3d, ", inputArray[i][j]);
			else
				printf("%3d  \n", inputArray[i][j]);
		}
	}
	

}

void findMaxRow (int n, int inputArray[][n], int *maxRowIndex, int *numberOfOnes)
{
	// variable decleration
	int i = 0;			// row index
	int j = 0;			// column index 
	
	while (i < n && j < n)
	{
		if (inputArray[i][j] == 1)
		{
			// move to next column
			j++;
			*maxRowIndex = i;
			*numberOfOnes = j;
		}
		else
			// move to next row
			i++;
	}
	// terminate function
	return;	// optional
}
