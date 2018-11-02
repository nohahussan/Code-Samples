// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// define constants 
#define MAX_NUMBER 100

// Function Prototype deceleration 
void GCD (int *result1, int *result2, int *count,  int m, int n);

// Main program function
int main() {
	// variable deceleration
	int result1, result2, count;
	int m, n, maxIterCount;
	
	// seed the random generator 
	srand ( time(NULL) );
	
	// print results table header
	printf("m \t n \t um+vn \t n\' \t Iteration Count \t Max Iteration Count \n");
	
	// calculate the gcd for 50 random pair values
	int i; // loop counter
	for (i = 0 ; i < 50 ; i++ ){
		// generate random numbers
		// between 0 and MAX_NUMBER
		m = (rand() % MAX_NUMBER) + 1;
		n = (rand() % MAX_NUMBER) + 1;
		
		// calculate gcd
		GCD(&result1, &result2, &count, m, n);
		
		// calculate the maximum number of iterations based on the formula
		// 2[log(n)]+1, where n is the smaller of the two values n,m
		maxIterCount = 2 * (log( n<m? n:m )) + 1; 
		
		// print results
		printf("%d \t %d \t %d \t %d \t %d \t\t\t %d\n", m, n, result1, result2, count, maxIterCount);
	}

	// return 0 to indicate successful termination
	return 0;
}


/*GCD calculation function
Objective: 	calculate the GCD of two integer values and report 
			the values of u*m + v*n, and n_dash such that
			u*m + v*n = gcd(m,n)
Inputs:
result1: 	a pointer to an integer to save value of u*m + v*n
result2: 	a pointer to an integer to save value of n_dash
count:		a pointer to an integer to save the number of divisions performed
n,m : 		two integer values to calculate the GCD for

Outputs:
result is reported using the pointers provided in
the input to the function
*/
void GCD (int *result1, int *result2, int *count, int m, int n) {
	//variable deceleration and initialization
	// Step 1
	int u_dash = 1;
	int v_dash = 0;
	int m_dash = m;
	int n_dash = n;
	int u = 0;
	int v = 1;
	*count = 0;
	
	int r, temp1, temp2; // temp variables for value copying
	
	// Step 2
	while ( (m_dash % n_dash) != 0) { // if  m_dash mod n_dash is equal to zero terminate loop and go to step 5
		// Step 3	
		temp1 = u; // save u,v
		temp2 = v;
		
		u = u_dash - ((m_dash/n_dash) * u); // update u,v
		v = v_dash - ((m_dash/n_dash) * v);
		*count = *count + 1; // increment the counter
		
		
		u_dash = temp1; // update u_dash, v_dash with saved old u,v
		v_dash = temp2;
		
		// Step 4
		r = m_dash % n_dash;
		m_dash = n_dash;
		n_dash = r;
	}
	
	// Step 5
	*result1 = u*m + v*n;
	*result2 = n_dash;

	// terminate function
	return;	// optional
}
