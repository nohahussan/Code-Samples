// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function Prototype deceleration 
void randomFill (int *inputArray,  int arrayLength, int min , int max);
int notDistinct (int number, int *arrayPointer, int n);
void printArray (int *inputArray, int arrayLength);
void quickSort(int *startPointer, int *endPointer);
int *partition (int *startPointer, int *endPointer);
int binarySearch(int array[], int searchValue, int arrayLength);

// Main program function
int main() 
{
	// prompt user to enter a list size, and get his input
	int n; 										// number of elements in array
	int index;									// index of found element
	int i;										// loop counter
	while (1)
	{	
		printf("Please enter a list size (n < 2 to exit): ");
		scanf("%d",&n);
	
		// exit loop if user enters 0 or 1
		if (n < 2)
			break;
			
		// fill array with distinct random numbers
		// between 0 and 2*n
		int A[n]; 								// array for random numbers storage
		int B[n];								// array for index subtraction
		randomFill (A, n, 0, 2*n);				// fill array
		
		// sort the array to convert it to a strictly increasing array 
		quickSort(A, A+n-1);					// sort array using quickSort
		printf("A strictly increasing array, of length %d\n", n);
		printArray (A, n);						// print orted array
		
		// subtract index from array elements to get B array
		for (i = 0; i < n; i++)
			B[i] = A[i] - i;
			
					
		// perform binary search, for a value of 0
		// that would indicte an element in A, where
		// A[i] = i
		index = binarySearch(B, 0, n);
		
		// print message
		if ( index != -1)
			printf("element no. %d satisfies the criteria A[i] = i\n\n", index);
		else
			printf("no element found that satisfies the criteria A[i] = i\n\n");	
	}

	// return 0 to indicate successful termination
	return 0;
}


/*randomFill function
Objective: 		fill an array with randomly generated numbers
				function checks before inserting a new value, 
				to make sure the values are non repeating

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array


Outputs:
the inputArray is filled with random numbers, using its pointer
*/

void randomFill (int *inputArray,  int arrayLength, int min, int max)
{
	srand (time(NULL));				// seed the random generator 
	int i;							// loop counter
	int temp;						// a temp storage of a radnom number
	int *arrayPointer = inputArray;	// copy array pointer value
	
	// first element is chosen as -1, 
	// as per Dr. Asish instructions during lab time
	*arrayPointer = -1;
	arrayPointer++;
	
	// fill array with random numbers between min and max
	for (i = 1 ; i < arrayLength ; i++)
	{
		// generate a random number
		temp = (rand() % (max - min + 1)) + min;
		
		// check to make sure number is not in the array
		while ( notDistinct(temp, inputArray, i) )
		{
			// generate another number
			temp = (rand() % (max - min + 1)) + min;
		}
		
		*arrayPointer = temp;		// store number in array	
		arrayPointer++;				// index to next array element
	}
	
	// terminate function
	return;	// optional
}

/*notDistinct function
Objective: 		check if a value exists within an array

Inputs:
number:			value to check for
arrayPointer:	a pointer to an integer for search array 
n:				number of elements in array


Outputs:
an integer value of 0 if value is not found and 1 if value is found
*/

int notDistinct (int number, int *arrayPointer, int n)
{
	int i;							// loop counter
		
	for (i = 0; i < n; i++)
	{
		if ( *arrayPointer == number )
			return 1;				// number is found, value is not distinct
		
		arrayPointer++;				// move pointer to next index
	}
	
	return 0;						// number is not found, value is distinct
}

/*printArray function
Objective: 		Print the contents of an input array

Inputs:
inputArray:		a pointer to an integer for search array 
arrayLength:	an integer for number of elements in search array


Outputs:
the inputArray is printed if it has less than 10 elements
*/

void printArray (int *inputArray, int arrayLength)
{	
	// print array contents 
	int i;										// loop counter
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

/*binarySearch function
Objective: 		search an ordered array for a value

Inputs:
array:			an integer array with ordered values
searchValue:	an integer search value 
endPointer:		array length


Outputs:
integer index of value postion, -1 if value is not found in array
*/
int binarySearch(int array[], int searchValue, int arrayLength)
{
	// start and end of search indices
	int start = 0;
	int end = arrayLength;
	
	// divide and conqure, divide array in half, to find value
	while (start < end)
	{
		int mid = (start+end)/2 ;		// calculate mid array mid position
		
		// is mid array element, the value we are looking for
		if (array[mid] == searchValue)
			return mid;					// return element index
			
		// element is not in the middle, divide the array
		// by adjusting the start and end position for next loop
		if (array[mid] < searchValue )
			start = mid + 1;			// value could be in top half
		else
			end = mid;					// vlaue could be in bottom half			
	}
	
	// element is not found
	return -1;							// to indicate that element is not found	
}
