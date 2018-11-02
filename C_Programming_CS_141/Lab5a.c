// preprocessor directive
#include <stdio.h>


// main program function routine
int main()
{
	// declare an integer variable a and store a value of 7
	int a = 7 ;
	
	// declare a pointer to an integer called aPtr
	int *aPtr ;
	
	// Retrive the memory address of the variable a 
	// and store it in the aPtr pointer
	aPtr = &a ;
	
	// Print the memory address of the variable a
	// , using hexdecimal rpresentation
	printf( "%p", &a );
	
	// print the value of aPtr, this will be the 
	// same as the address of variable a
	printf( "%p", aPtr );
	
	// print the memory address of the variable aPtr
	// , pointer to a pointer 
	printf( "%p", &aPtr );
	
	// print the value of a
	printf( "%d", a );
	
	// print the value stored in memory at the address aPtr
	// , will be the same as printing a , since aPtr points 
	// to the address of a
	printf( "%d", *aPtr );
	
	// print the address contained in aPtr, since we are 
	// derefrencing from the address of aPtr
	printf( "%p", *&aPtr );
	
	// print the address of the variable a, getting the 
	// address of the derefernced value from pointer aPtr
	printf( "%p", &*aPtr );
	
	// print the value of variable a, drefernce from the address of a
	printf( "%d", *&a );
	
	// would not work, we cannot derefernce from a since it is not a memory address
	// printf( "%d", &*a );
	
	return 0;
}
