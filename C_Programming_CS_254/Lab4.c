//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function Prototype deceleration 
unsigned int FibonacciRecursive (int n);
unsigned int FibonacciIterative (int n);
unsigned int FibonacciDynamic (int n);

// Main program function
int main() {
	// variable deceleration
	int n;
	unsigned int fib;


	// print a validation report
	n=10;
	printf("Validation for the three methods implementation\n");
	printf("the %dth Fibonacci number using Recursion is: %u\n",n,FibonacciRecursive(n));
	printf("the %dth Fibonacci number using Iteration is: %u\n",n,FibonacciIterative(n));
	printf("the %dth Fibonacci number using Dynamic Programming is: %u\n\n",n,FibonacciDynamic(n));
	
	// time analysis
	printf("Fibonacci numbers form 0 to 47, and their processing times\n\n");
	
	// variables for time calculation
	clock_t begin, end;
	double timeSpent;
	
	// print table header
	printf("\t\t\t\t\ttime(sec)\n");
	printf("n\tFibonacci\tRecursive\tIterative\tDynamic\n");
	
	for (n = 0; n <= 47; n++)
	{
		// using recursive method
		begin = clock();
		fib = FibonacciRecursive(n);
		end = clock();
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		printf("%d\t%-10u\t%f",n,fib,timeSpent);
	
		// using iterative method
		begin = clock();
		fib = FibonacciIterative(n);
		end = clock();
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		printf("\t%f",timeSpent);
	
		// using dynamic method
		begin = clock();
		fib = FibonacciDynamic(n);
		end = clock();
		timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
		printf("\t%f\n",timeSpent);
	}
	// return 0 to indicate successful termination
	return 0;
}


/*FibonacciRecursive function
Objective: 	Calculate the value of the Fibonacci number using recursion

Input:	an integer value for Fibonacci calculation
Output: the Fibonacci number
*/

unsigned int FibonacciRecursive (int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return FibonacciRecursive(n-1) + FibonacciRecursive(n-2);
}

/*FibonacciIterative function
Objective: 	Calculate the value of the Fibonacci number using iteration

Input:	an integer value for Fibonacci calculation
Output: the Fibonacci number
*/

unsigned int FibonacciIterative (int n)
{
	// variable deceleration
	unsigned int fib[] = {0 , 1};
	
	// for n = 0 or 1
	if (n <= 1)
		return fib[n];

	// current Fibonacci number		
	unsigned int fibN;
	
	
	// Loop counter
	int i;
	
	for (i = 2; i <= n; i++)
	{
		// calculate current Fibonacci number	
		fibN = fib[1] + fib[0];
		
		// update previous numbers
		fib[0] = fib[1];
		fib[1] = fibN;
	}
	
	return fibN;
}

/*FibonacciDynamic function
Objective: 	Calculate the value of the Fibonacci number using Dynamic calculation

Input:	an integer value for Fibonacci calculation
Output: the Fibonacci number
*/

unsigned int FibonacciDynamic (int n)
{
	static unsigned int knownF[48];
	
	if (knownF[n] != 0) 
		return knownF[n];
	
	unsigned int t=n ;
	
	if (n < 0) 
		return 0;
	if (n > 1) 
		t = FibonacciDynamic(n-1) + FibonacciDynamic(n-2);
	
	return knownF[n] = t;
}


