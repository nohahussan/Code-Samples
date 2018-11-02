// preprocessor directive library includes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Define M N and MIN MAX for array size and random number range
#define M 6
#define N 5
#define MIN 15
#define MAX 75


// function prototype
void PopulateRandom2D(int *arrayAddr);
void PrintArray2D (int *arrayAddr);
int  LinearSearch2D (int *arrayAddr, int userN);
void LeftShift2D (int *arrayAddr);

// Main function routine
int main ( void )
{
	int Array[M][N] , userN , userChoice ;
	PopulateRandom2D( &Array[0][0] ); // intitialize the array with random numbers withing the range
	while (1)
	{
		// print menu
		printf("\n1- Fill the array with random numbers.\n");
		printf("2- Serach the array.\n");
		printf("3- Left shift the array.\n");
		printf("4- Print the array.\n");
		printf("5- Quit.\n\n");
		printf("Select an option (1-5): ");
		scanf ( "%d" , &userChoice );
	
		switch (userChoice)
		{
			case 1:
			{
				// fill the array with random numbers
				PopulateRandom2D( &Array[0][0] );
				break;	
			}
			case 2:
			{
				// ask the user for an input and report search result
				printf("Please Enter a number between %d and %d\n",MIN,MAX);
				scanf("%d",&userN);
				if ( LinearSearch2D( &Array[0][0] , userN ) == 1)
					printf("The number %d was found in the array\n", userN);
				else
					printf("The number %d was not found in the array\n", userN);
				break;
			}
			case 3:
			{
				// shift array to the left
				LeftShift2D ( &Array[0][0] );
				break;	
			}
			case 4:
			{
				// print the array to the user
				printf("\n");
				PrintArray2D( &Array[0][0] );
				break;
			}
			case 5:
			{
				// Quit the program
				return 0;
			}
			default:
			{
				// print an error message
				printf ("Invalid Choice, plesae enter a number (1-5)\n");
				break;
			}
		}
	}
}





/*objective : Populate a 2D array with random numbers between MIN and MAX
  input     : a pointer to an integer array
  output    : no return as the function modifys the orignal array using the pointer
*/
void PopulateRandom2D(int *arrayAddr)
{
	// seed the rand function using the current time to ensure randomness of values
	srand(time(NULL));
	
	// loop over the array elemnets using the pointer and populate with a random number
	for (int i = 0 ; i < M ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			*arrayAddr = (rand() % (MAX-MIN+1)) + MIN;
			arrayAddr ++;
		}
	}
	return;
}



/*objective : Print the elements of a 2D array of size M*N
  input     : a pointer to an integer array
  output    : the function dosnot return any value it just print a matrix
*/
void PrintArray2D (int *arrayAddr)
{
	for (int i = 0 ; i < M ; i++ )
	{
		for (int j = 0 ; j < N ; j++ )
		{
			printf("%d\t",*arrayAddr);
			arrayAddr ++;
		}
		printf("\n");
	}		
	return;
}


/*objective : search for a number that user entered to find out if 
              this number in the matrix or not
  input     : two dimenssion array  and an integer number that user entered
  output    : an integer number one if the user number found within the matrix
              or zero if the number not within the matrix
*/
int LinearSearch2D (int *arrayAddr, int userN)
{
	// loop over array elements using the pointer
	for (int i = 0 ; i < M ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (userN == *arrayAddr)
				return 1; // return from function when value is found
			arrayAddr ++;
		}
	}
	return 0;
}


/*objective : Apply lift shift operation to a 2D array
  input     : a pointer to an integer array
  output    : No output, the function applys the shift to the original array using its pointer
*/
void LeftShift2D (int *arrayAddr)
{
	// store a copy of the first element
	int temp = *arrayAddr; 
	
	// apply the shift process using the fact that the array is stored
	// in the memory as a single row
	for (int i = 0 ; i < M*N-1 ; i++ , arrayAddr++)
		*arrayAddr = *( arrayAddr + 1 );
		
	// the last element will get the value of the first element from the
	// temp copy
	*arrayAddr = temp;
	
	return;
}
