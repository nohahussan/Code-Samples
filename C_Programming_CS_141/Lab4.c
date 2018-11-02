// Preporocessor Directives
#include <stdio.h>

// Function Prototype Declration
int *Largest( int *array, int size );
void Swap( int *x, int *y );


// Main Function Routine
int main()
{
	// Variable decleration
	int *largestAddr , size = 10 ; 
	int array[10] = { 7 , 4 , 3 , 5 , 2 , 1 , 6 , 8 , 5 , 2} ;
	
	// Print array
	printf("unsorted array = {");
	for (int i = 0 ; i < size ; i++)
		printf (" %d " , array[i] );
	printf("}\n");
	
	// Sort the array by finding the largest element and swaping
	// it with the last element 
	for (int i = size-1 ; i > 0 ; i--)
	{
		largestAddr = Largest (array , i + 1);
		Swap (largestAddr , &array[i]);
	}
	
	// Print array
	printf("sorted array = {");
	for (int i = 0 ; i < size ; i++)
		printf (" %d " , array[i] );
	printf("}\n");
	
	return 0;
}





/*objective : Find the address of the largest element within an array
  inputs    : two inputs are required, the pointer to the array, and 
              the array size.
  output    : the function searchs for the largest element and returns
              its address
*/
int *Largest( int *array, int size )
{
	// Variable declration, a temp storage of the largest element address
	int *largestAddr ;

	// the first element is assumed to be the largest element in 
	// the array
	largestAddr = array;
	
	/* the function loops over the rest of the elements to search 
	   for a larger element, if found, the address of the larger element 
	   replace the old element, when the loop is done, the address will 
	   refelect the largest element in the array*/
	for (int i = 1 ; i < size ; i++)
	{
		if ( *largestAddr < *( array + i ) )
		{
			largestAddr = array + i ;
		}
	}
	
	return largestAddr;
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
}
