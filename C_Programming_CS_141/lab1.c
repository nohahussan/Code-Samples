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
	int n, x, y, b;
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
			printf("please enter a value of ( x ,y )\n");//ask user to input a value for n
			scanf("%i, %i", &x, &y);//read the user input
			printf("the gcd of (%i , %i) is %i\n", x,y,gcd(x,y));//call the function and return result
                       break;
		case 5:
			printf("please enter a value of ( a , b )\n");//ask user to input a value for n
			scanf("%f,%i", &a, &b);//read the user input
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
	int sum = n * (n + 1)/2;//define an integer variable to store the value of sumation
	return sum;
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
	for(int i = 1; i <=n; i++)
	{

		 cumProduct *=i;

	}
	return cumProduct;
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
	int result = 0;
	int fibN_1 = 1;//define an intger variable to store the value of fib (n-1)
	int fibN_2 = 0;//define an intger variable to store the value of fib (n-2)	 
	for( int i = 2; i <= n; i++)
	{
		
		result  = fibN_1 + fibN_2;
		fibN_2 = fibN_1;
		fibN_1 = result;
	}
	return result;
}

int gcd (int x, int y)
{
/*object : calculate the great of common devisor, gcd (y,x mod y)
input : two intger number (x,y)
output : an integer value
*/
	int oldx;
	if (x < 0 || y < 0)
	{
		printf("Errror (x ,y) should be >=0 \n");
		return 0;
	}

	while (y != 0)
	{
		oldx = x;
		x = y;
		y = oldx % y;
	}
	return x;
}


float power (float a,int b)
{
/* object : calculate the value of a^b
input : a float number (a) and an integer number (b), where a,b should be >=0
output : a float number 
*/
 	float powerValue = 1;
	if (a < 0 || b < 0)
	{
		printf("Error (a , b) should be >=0\n");
		return 0;
	}
	for(int i = 1; i <= b; i++)
	{
		powerValue *= a; //powerValue = powerValue * i

	}


	return powerValue;
}
