// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// define constants 
#define MAX_NUMBER 10
#define MIN_NUMBER -10

// Function Prototype deceleration 
void maxSpanSum (int *maxSum, int *maxStart, int *maxEnd, int *inputArray,  int arrayLength);

// Main program function
int main() {
	// variable deceleration
	int n=15; // number of elements in array
	int seq=10; // number of sequences
	
	int array[n]; 	// array of numbers for span search
	
	// value of span maximum summation, start, and end of span 
	int maxSum, maxStart, maxEnd;
	
	int i,j; // loop counters
	
	// seed the random generator 
	srand ( time(NULL) );

	// print table header
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("                                  Sequence                                 | Max Sum | Start | End |\n");
	for (j = 0 ; j < n ; j++ )
	{
		printf("%3d  ", j);		
	}
	printf("|         |       |     |\n");
	printf("---------------------------------------------------------------------------|---------|-------|-----|\n");
	
	
	
	for (i = 0 ; i < seq ; i++)
	{
		// fill array with random numbers between MAX_NUMBER and MIN_NUMBER
		for (j = 0 ; j < n ; j++ )
		{
			// generate random numbers
			array[j] = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
		
			// print array
			if (j < (n-1))
				printf("%3d, ", array[j]);
			else
				printf("%3d  ", array[j]);
			
		}


		// call maxSpanSum function to find the Span with the max summation
		maxSpanSum (&maxSum, &maxStart, &maxEnd, array, n);
	
		// print results
		if (maxStart == -1)
			printf("|%8d |    EMPTY    |\n",maxSum);
		else
			printf("|%8d |%6d |%4d |\n",maxSum, maxStart, maxEnd);
	}
	printf("----------------------------------------------------------------------------------------------------\n");
	// return 0 to indicate successful termination
	return 0;
}


/*maxSpanSum function
Objective: 	find the span in the input array with the maximum summation

Inputs:
maxSum: 	a pointer to an integer for maximum span summation reporting 
maxStart: 	a pointer to an integer for start of span  
maxEnd:		a pointer to an integer for end of span 
inputArray:	a pointer to an integer for search array 
arrayLength:an integer for number of elements in search array


Outputs:
result is reported using the pointers provided in
the input to the function
*/

void maxSpanSum (int *maxSum, int *maxStart, int *maxEnd, int *inputArray,  int arrayLength)
{
	//variable deceleration and initialization
	int sum[arrayLength];		// array for saving span summations and start of each span 
	int start[arrayLength];
	
	int i; // loop counter

	// for first element max summation is that single element
	sum[0] = *inputArray;
	start[0] = 0;
	
	// loop over all elements to find where the max summation ending at that element is
	// and store it in the sum array with start index stored in start array
	for (i=1; i < arrayLength; i++) 
	{
		inputArray++; // advance array counter to next element
		
		// for each element the max summation ending at element i 
		// is equal to the maximum summation from the element (i-1) 
		// plus the value of element i,
		// unless the summation at (i-1) is less than 0, 
		// in which case, start a new span for element i that only includes itself
		if (sum[i-1] < 0)
		{
			sum[i] = *inputArray;
			start[i] = i;
		} 
		else 
		{
			sum[i] = sum[i-1] + *inputArray;
			start[i] = start[i-1];
		}
	}
	
	// Intialize the span maximum summation and span location
	*maxSum = sum[0];
	*maxStart = start[0];
	*maxEnd = 0;
	
	// loop over summation values to find which one is the maximum
	for (i=1; i < arrayLength; i++) 
	{
		if (sum[i] > *maxSum)
		{
			*maxSum = sum[i];
			*maxStart = start[i];
			*maxEnd = i;
		}	
	}
	
	// a start and end of -1 indicates that an empty sequence has the max summation
	if (*maxSum < 0)
	{
		*maxSum = 0;
		*maxStart = -1;
		*maxEnd = -1;
	}
	
	// terminate function
	return;	// optional
}
