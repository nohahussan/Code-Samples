// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// define constants 
#define MAX_NUMBER 100000
#define MIN_NUMBER 0

// Function Prototype deceleration 
void randomFill (int *inputArray1, int *inputArray2,  int arrayLength);
void printArray (int *inputArray, int arrayLength, char *message);
void insertionSort(int *inputArray, int arrayLength);
void quickSort(int *startPointer, int *endPointer);
int *partition (int *startPointer, int *endPointer);

// Main program function
int main() {

	clock_t begin, end;						// for time calculation
	double timeSpent;						// processing time
	
		
		
	
	
	// prompt user to enter a list size, and get his input
	int n; 																// number of elements in array
	
	while (1)
	{	
		printf("Please enter a list size (n < 2 to exit): ");
		scanf("%d",&n);
	
		
		// exit loop if user enters 0 or 1
		if (n < 2)
			break;
			
		// declare two arrays of required size and fill them with random numbers
		// between MAX_NUMBER and MIN_NUMBER
		int array1[n]; 														// array for random numbers storage
		int array2[n];														// array for random numbers storage
		randomFill (array1,array2, n);										// fill arrays
		printArray (array1, n, "Unsorted array");							// print unsorted array
		
		// sort array1 using insertionSort
		begin = clock();						// start the clock
		insertionSort(array1, n);				// sort array using insertionSort
		end = clock();							// stop the clock, and calculate time spent
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		// print sorting time
		printf("Using insertionSort\tProcessing Time (sec):%f\n", timeSpent);
		// print sorted array
		printArray (array1, n, "Sorted array");
		
		
		
		// sort array2 using quickSort
		begin = clock();						// start the clock
		quickSort(array2, array2+n-1);			// sort array using quickSort
		end = clock();							// stop the clock, and calculate time spent
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		// print sorting time
		printf("Using quickSort\t\tProcessing Time (sec):%f\n", timeSpent);
		// print sorted array
		printArray (array2, n, "Sorted array");
		
	}

	// return 0 to indicate successful termination
	return 0;
}


/*randomFill function
Objective: 		fill an array with randomly generated numbers

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array


Outputs:
the inputArray is filled with random numbers, using its pointer
*/

void randomFill (int *inputArray1, int *inputArray2,  int arrayLength)
{
	srand (time(NULL));				// seed the random generator 
	int i;							// loop counter
	
	// fill array with random numbers between MAX_NUMBER and MIN_NUMBER
	for (i = 0 ; i < arrayLength ; i++)
	{
		// generate random numbers
		*inputArray1 = *inputArray2 = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
		
		// index to next array element
		inputArray1++;
		inputArray2++;
	}
	
	// terminate function
	return;	// optional
}

/*printArray function
Objective: 		Print the contents of an input array

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array


Outputs:
the inputArray is printed if it has less than 10 elements
*/

void printArray (int *inputArray, int arrayLength, char *message)
{
	// if the number of elements is bigger than 10
	// print processing time only
	if (arrayLength > 10)
	{
		return;
	}
	
	// print array contents 
	int i;										// loop counter
	printf("%s\n", message);					// print message
	for (i = 0 ; i < arrayLength ; i++)			// print the contents of the array
	{
		// print array
		if (i < (arrayLength-1))
			printf("%3d, ", *inputArray);
		else
			printf("%3d  ", *inputArray);
	
		// index to next array element
		inputArray++;
	}
	printf("\n");
	
	// terminate function
	return;	// optional
}

/*insertionSort function
Objective: 		sort an array using insertion sort

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array


Outputs:
array is modified to a sorted order
*/
void insertionSort(int *inputArray, int arrayLength)
{
	int i, j;				 				// loop counters
	int temp;								// temp storage for sorting
	
	// sort array	
	for (i = 1; i < arrayLength; i++)
	{
		temp = inputArray[i];				// select an element
		j = i;								// start point for insertion search
		// loop to find insertion point
		while (j > 0 && inputArray[j-1] > temp)
		{
			inputArray[j] = inputArray[j-1];// shift element to left
			j--;							// move to next element
		}
		// insert copied value at j position
		inputArray[j] = temp;
	}
	
	// terminate function
	return;	// optional	
}

/*quickSort function
Objective: 		sort an array using quick sort

Inputs:
startPointer:		a pointer to start position 
endPointer:			a pointer to end position


Outputs:
array is modified to a sorted order
*/
void quickSort(int *startPointer, int *endPointer)
{
	// if starting position is larger than end position
	// return call, other wise run a recursive call on partioned array
	if (startPointer < endPointer)
	{
		// get array partiion location
		int *r = partition (startPointer, endPointer);
		
		// recursive call
		quickSort(startPointer, r);
		quickSort(r+1, endPointer);
	}
	
	// terminate function
	return;	// optional	
}

/*partition function
Objective: 		partition an array into two sections
				L1, L2, such that 
				every element in L1 is <= every element in L2 

Inputs:
startPointer:		a pointer to start position 
endPointer:			a pointer to end position


Outputs:
array is modified and pointer for partition point is returned
*/
int *partition (int *startPointer, int *endPointer)
{
	// variable decleration
	int a = *startPointer;			// copy starting number
	int temp;						// temp value for exchange
	int *lp = startPointer-1;		// start search pointer
	int *rp = endPointer+1;			// end search pointer
	
	while (lp < rp)
	{
		// move left until element is <= a
		rp--;
		while (*rp > a)
			rp--;
	
		// move right until element is >= a
		lp++;
		while (*lp < a)
			lp++;
		
		// if pointer have not met or crossed
		// exchange the elments pointed at by the pointers
		if (lp < rp)
		{
			temp = *lp;
			*lp = *rp;
			*rp = temp;
		}
	}
	
	// return partion pointer
	return rp;
}

