// preprocessor directive 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN 0
#define MAX 100
#define SIZE 20

// function prototypes
void FillArray  ( int *array, int size );
void PrintArray ( int *array, int size );
void BubbleSort ( int *array, int size );
void Swap ( int *x, int *y );

// main program function routine
int main ( void )
{
	// declare an array NumList of type integer and size SIZE
	int NumList[SIZE];
	
	// fill the array with random numbers between MIN and MAX defined at top
	FillArray  ( NumList , SIZE );
	
	// print the array contents
	printf("Unsorted Array: \n");
	PrintArray ( NumList , SIZE );
	
	// sort the elements of the array using BubbleSort
	BubbleSort ( NumList , SIZE );

	// print the sorted array contents
	printf("Sorted Array: \n");
	PrintArray ( NumList , SIZE );

	return 0;
}


/*objective : fill an array with random numbers between MIN and MAX
  input     : a pointer to an integer array
  output    : no return as the function modifys the orignal array using the pointer
*/
void FillArray ( int *array, int size )
{
	// seed the rand function using the current time to ensure randomness of values
	srand(time(NULL));
	
	// loop over the array elemnets using the pointer and populate with a random number
	int i;
	for (i = 0 ; i < size ; i++ , array ++)
	{
			*array = (rand() % (MAX-MIN+1)) + MIN;
	}
	return;
}

/*objective : Print the elements of an array of size size
  input     : a pointer to an integer array
  output    : the function dosnot return any value it just print a matrix
*/
void PrintArray ( int *array, int size )
{
	// loop over the array elemnets using the pointer and print their values
	int i;
	for (i = 0 ; i < size ; i++ , array ++)
	{
		if (i == 0)
			printf ( "{%3d," , *array );
		else if (i == (size - 1))
			printf ( "%3d}\n" , *array );
		else
			printf ( "%3d," , *array );
	}
	return;
}


/*objective : The function should sort the array passed, in descending order 
  input     : a pointer to an integer array
  output    : the function dosnot return any value it just print a matrix
*/
void BubbleSort ( int *array, int size )
{
	int k , j , sorted;
	for ( k = 0 ; k < size - 1 ; k++ ) 
	// outer loop to go over sublists starting from the whole array
	// and decreasing the size of the sub list until two elements
	{
		sorted = 1; // a flag to find if array is sorted or not
		for ( j = 0 ; j < size - k - 1 ; j++ )
		// inner loop to compare every two elements and move the smaller
		// element up to the end of the sub list
		{
			// compare the two elements and swap if the first element is 
			// smaller than the second , to move the smaller element up 
			// to the end of the array
			if ( *(array + j) < *(array + j + 1) )
			{
				Swap( array + j , array + j + 1 );
				sorted = 0; // since a swap operation has occured, 
				            // the array is still not sorted
			}
		}
		if (sorted) return;
	}
	return;
}

/*objective : Swap the values stored in two memory addresses
  inputs    : two pointers to integer values
  output    : no output is returned, the function modifies 
              the values directly in the memory
*/
void Swap( int *x, int *y )
{
	// declare a temp integer variable to store the data stored at address x
	int temp;
	temp = *x;
	
	// Swap the values by replacing data at x memory address with data from 
	// y address, replace the data in y address with the copy from x location 
	*x = *y;
	*y = temp;
	
	return;
}
