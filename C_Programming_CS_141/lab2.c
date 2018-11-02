#include <stdio.h>


//define function prototype decleration
int summation (int n);
int factorial (int n);
int fibonacci (int n);
int gcd (int x, int y);
float power (float a,int b);




//main function program routine
int main ()
{
	int b;
	int n;
	
	int x;
	int y;
	float a;
	
	int userChoice;
	printf("Please chose which function do you want to use\n1\tSumation\n2\tFactorial\n3\tFibonacci\n4\tgcd\n5\tPower\n");
	scanf("%i", &userChoice);
	switch (userChoice)
	{
		case 1:
			printf("Please enter a value of n \n");//ask user to input a value for n
			scanf("%i", &n);//read the user input
			printf("Summation of %i is %i\n",n,summation (n));//call the function and return result

			break;
		case 2:
			printf("please enter a value of n\n");//ask user to input a value for n
			scanf("%i", &n);//read the user input
			printf("Factoria of %i is %i\n",n,factorial (n));//call the function and return result
			break;
		case 3:
			printf("Please enter a value of n \n");//ask user to input a value for n	
			scanf("%i", &n);//read the user input
			printf("fibonacci of %i is %i\n",n,fibonacci (n));//call the function and return result
			break;
		case 4:
			printf("please enter a value of ( x , y )\n");//ask user to input a value for n
			scanf("%i %d", &x, &y);//read the user input
			printf("the gcd of (%i , %i) is %i\n", x,y,gcd(x,y));//call the function and return result
			break;
		case 5:
			printf("please enter a value of ( a , b )\n");//ask user to input a value for n
			scanf("%f %d", &a, &b);//read the user input
			printf("the power of (%f , %i) is %.2f\n", a,b,power (a,b));//call the function and return result
			break;
	}


	return 0;
}


int summation (int n)
{
/*object : calculate a sumation of numbers between 1 and n,1+2+...+n
input : an intger number n, where n should be >=1
output : an integer number representing 1+2+...+n
*/
	if (n < 1)
	
	{
		printf("Error , n should be >=1\n");//print error message and return
		return 0; 
	}

	if (n == 1)
		return 1;

	return n + summation(n-1);
}


int factorial (int n)
{
/* object : calculate the factorial value for n ,where n >=0
input : an integer value n ,n should be >=o
output : an integer value of cumulative product output can be evaluated as n*(n-1)*...*2*1
*/
	int cumProduct = 1;// intialize a cumulative product
	if (n < 0)
	{
		printf("Error , n should be >=0\n");//print error message and return	
		return 0;
	}

	if (n == 0)
		return 1;

	return n * factorial (n-1);
}


 int fibonacci (int n)
{
/* object : calculate fabinacci of n ,fib (n) = fib (n-1)+fib (n-2)
input : an integer number n 
output : an iteger value for fibonacci (n)
*/

	if (n < 0)
	{
		printf("Errror y, n should be >=0\n");
		return 0;
	}
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fibonacci (n-1) + fibonacci (n-2);
}

int gcd (int x, int y)
{
/*object : calculate the great of common devisor, gcd (y,x mod y)
input : two intger number (x,y)
output : an integer value
*/
	if (x < 0 || y < 0)
	{
		printf("Errror (x ,y) should be >=0 \n");
		return 0;
	}

	if (y == 0)
		return x;

	return gcd (y , x % y);
}


float power (float a,int b)
{
/* object : calculate the value of a^b
input : a float number (a) and an integer number (b), where a,b should be >=0
output : a float number 
*/
	if (a < 0 || b < 0)
	{	
		printf("Error (a , b) should be >=0\n");
		return 0;
	}
	
	if (b == 0)
		return 1;
	return a * power (a , b - 1);
}
