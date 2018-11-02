// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// define constants 
#define MAX_NUMBER 1000
#define MIN_NUMBER 0

// Function Prototype deceleration
// General purpose functions
void randomFill (int *inputArray1, int *inputArray2,  int arrayLength);
void printArray (int *inputArray, int arrayLength, char *message);
// quick sort functions
void quickSort(int *startPointer, int *endPointer);
int *partition (int *startPointer, int *endPointer);
// heap sort functions
void heapSort(int *inputArray, int arrayLength);
void buildHeap(int *inputArray, int arrayLength);
void heapify(int *inputArray, int i, int j);


// Main program function
int main() {

	clock_t begin, end;						// for time calculation
	double timeSpent;						// processing time
	
	// prompt user to enter a list size, and get his input
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
		int array1[n]; 														// array for random numbers storage
		int array2[n];														// array for random numbers storage
		randomFill (array1,array2, n);										// fill arrays
		printArray (array1, n, "Unsorted array");							// print unsorted array
		
		// sort array1 using heapSort
		begin = clock();						// start the clock
		heapSort(array1, n);					// sort array using insertionSort
		end = clock();							// stop the clock, and calculate time spent
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		// print sorting time
		printf("Using heapSort\t\tProcessing Time (sec):%f\n", timeSpent);
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


/*heapSort function
Objective: 		sort an array using heapSort

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array

Outputs:
array is modified to a sorted order
*/
void heapSort(int *inputArray, int arrayLength)
{
	int i;				 				// loop counter
	int temp;							// temp storage for exchange
	
	// call buildHeap
	buildHeap(inputArray, arrayLength);

	// sort array	
	for (i = (arrayLength - 1); i >= 1; i--)
	{
		// exchange A[0] with A[i]
		temp = inputArray[0];
		inputArray [0] = inputArray[i];
		inputArray [i] = temp;
		
		// Heapify(1,i-1)
		heapify(inputArray, 0, i-1);
	}
	
	// terminate function
	return;	// optional	
}

/*buildHeap function
Objective: 		rearrange an array, so, that it meets the Heap property

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array

Outputs:
array is modified to meet the heap property
*/
void buildHeap(int *inputArray, int arrayLength)
{
	int i;		// loop counter
	
	// heapify the array
	for (i = (arrayLength - 1); i >= 0; i--)
		heapify(inputArray, i, arrayLength - 1);
	
	// terminate function
	return;		// optional	
}

/*heapify function
Objective: 		rearrange a sub list to meet the heap property

Inputs:
inputArray:		a pointer to an integer for search array 
i:				an integer index of starting position
j: 				an integer index of end position

Outputs:
array is modified to meet the heap property
*/
void heapify(int *inputArray, int i, int j)
{
	int k, temp;				// index and temp for exchange
	
	// only proceed if element is not a leaf
	// an element is a leaf if it has one or two children
	// children are calculated as
	// left child index = 2*i + 1 
	// right child index = 2*i + 2
	if ((2*i + 1) <= j || (2*i + 2) <= j)
	{
		// element has two children	
		// find out which child is larger
		if ((2*i + 1) <= j && (2*i + 2) <= j)
		{
			// if the element has two children, find out which one is larger
			if (inputArray[2*i + 1] > inputArray[2*i + 2])
				k = 2*i + 1;
			else
				k = 2*i + 2;
		}
		else	// element has only one child
			k = 2*i + 1;
		
		// if the larger child is larger than parent, exchange with parent
		if (inputArray[i] < inputArray[k])
		{
			temp = inputArray[i];
			inputArray[i] = inputArray[k];
			inputArray[k] = temp;
		}
		
		// recursive call of heapify, on the children
		heapify(inputArray, k, j);
	}
	
	// terminate function
	return;	// optional	
}
