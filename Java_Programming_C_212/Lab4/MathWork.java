package lab4b;

import java.util.InputMismatchException;
import java.util.Scanner;


public class MathWork {

	// Instance variables
	private Scanner keyboard;				// a common scanner for all user input
	private boolean fileCreatedFlag;		// flag to indicate if file is open, and use append=true in that case
	
	/**
	 * Constructor, no argument
	 */
	public MathWork()
	{
		keyboard = new Scanner(System.in);
		fileCreatedFlag = false;
	}
	
	/**
	 * printMenu, prints a menu and prompt user for choice
	 * @return an integer value with the user menu selection
	 */
	public int printMenu() {
		
		// Print menu, for user selection
		System.out.println("\n*************** MathWork ***************");
		System.out.println("(1) Factorial Calculation.");
		System.out.println("(2) Fibonacci Calculation.");
		System.out.println("(3) GCD Calculation.");
		System.out.println("Please make a choice (0 to quit):");

		// get user input, if input is not an Integer print an error message
		// return 4  will cause the calling application to handle the error
		// by reprinting the menu.
		try
		{
			int choice = keyboard.nextInt();
			keyboard.nextLine(); // read line to get rid of newline character before next input
			return choice;
		}
		catch(InputMismatchException e)
		{
			// if user inputs a non integer value, exception is handled,
			// by printing an error message and send a value of 4 
			System.out.println("An Integer value is needed!");
			keyboard.nextLine(); // read line to get rid of newline character before next input
			return 4;
		}
	}

	/**
	 * factorial, get user input, calculate the factorial and write result to file
	 */
	public void factorial() 
	{
		// prompt the user for input
		System.out.println("Please enter an integer value between 0-15:");
		
		// try to read the value, if value is not an integer exception is caught and handled
		try
		{
			int n = keyboard.nextInt();
			keyboard.nextLine(); // read line to get rid of newline character before next input
			
			if ( n >= 0 && n <= 15 ) // only calculate the factorial if value is less than 15
			{
				// use the recursive method factorialCalculator to calculate the factorial
				int result = factorialCalculator(n);
				
				// if file doesn't exist create a new file otherwise append old file 
				if (fileCreatedFlag)
				{
					FileWriter.write("Factorial Of " + n + " = " + result , true);
					System.out.println("Factorial Of " + n + " = " + result );
				}
				else
				{
					FileWriter.write("Factorial Of " + n + " = " + result , false);
					fileCreatedFlag = true;
				}	
			}
			else
			{
				// if value is larger than 15, print an error message
				System.out.println("Error, A value between 0-15 is needed!");
			}
		}
		catch(InputMismatchException e)
		{
			// if user inputs a non integer value, handle exception
			System.out.println("Error, An Integer value is needed!");
			keyboard.nextLine(); // read line to get rid of newline character before next input
		}
	}



	/**
	 * fibonacci, get user input, calculate the fibonacci and write result to file
	 */
	public void fibonacci() 
	{
		// prompt the user for input
		System.out.println("Please enter an integer value between 0-35:");
		
		// try to read the value, if value is not an integer exception is caught and handled
		try
		{
			int n = keyboard.nextInt();
			keyboard.nextLine(); // read line to get rid of newline character before next input
			
			if ( n >= 0 && n <= 35 )
			{
				// use the recursive method fibonacciCalculator to calculate the fibonacci
				int result = fibonacciCalculator(n);
				
				// if file doesn't exist create a new file otherwise append old file 
				if (fileCreatedFlag)
					FileWriter.write("The " + numberToString(n) + " Fibonacci number = " + result , true);
				else
				{
					FileWriter.write("The " + numberToString(n) + " Fibonacci number = " + result , false);
					fileCreatedFlag = true;
				}	
			}
			else
			{
				System.out.println("Error, A value between 0-35 is needed!");
			}
		}
		catch(InputMismatchException e)
		{
			// if user inputs a non integer value, handle exception
			System.out.println("Error, An Integer value is needed!");
			keyboard.nextLine(); // read line to get rid of newline character before next input
		}
	}
	
	/**
	 * gcd, get user input, calculate the gcd and write result to file
	 */
	public void gcd() 
	{
		// prompt the user for input
		System.out.println("Please enter two integer values:");

		// try to read two values separated by a space, 
		// if values are not entered according to the required format
		// exception is caught and handled
		try
		{
			int n = keyboard.nextInt();
			int m = keyboard.nextInt();
			keyboard.nextLine(); // read line to get rid of newline character before next input
			
			// use the recursive method gcdCalculator to calculate the gcd
			int result = gcdCalculator(n,m);
			
			// if file doesn't exist create a new file otherwise append old file 
			if (fileCreatedFlag)
				FileWriter.write("GCD of " + n + " and " + m + " = " +result , true);
			else
			{
				FileWriter.write("GCD of " + n + " and " + m + " = " +result , false);
				fileCreatedFlag = true;
			}	
		}
		catch(InputMismatchException e)
		{
			// if user inputs a non integer value, handle exception
			System.out.println("Error, An Integer value is needed!");
			keyboard.nextLine(); // read line to get rid of newline character before next input
		}
	}
	
	
	// private methods for factorial, fibonacci and gcd calculation
	/*
	 * Calculate the factorial of a number
	 */
	private int factorialCalculator(int n) 
	{
		if (n == 0)
			return 1;
		else
			return n * factorialCalculator(n-1);
	}
	
	/*
	 * calculate the fibonacci number
	 */
	private int fibonacciCalculator(int n) 
	{
		if(n == 0)
			return 0;
		else if(n == 1)
			return 1;
		else
	      return fibonacciCalculator(n - 1) + fibonacciCalculator(n - 2);
	}
	
	/*
	 * calculate the greatest common divisor for two numbers
	 */
	private int gcdCalculator(int m, int n) 
	{
		if ((m%n) == 0)
			return n;
		else
			return gcdCalculator(n, m%n);
	}
	
	/*
	 * return a string with the number such that 21 -> 21st
	 */
	private String numberToString(int n) 
	{
		if ((n-1)%10 == 0 && n != 11)
			return n + "st";
		else if ((n-2)%10 == 0 && n != 12)
			return n + "nd";
		else if ((n-3)%10 == 0 && n != 13)
			return n + "rd";
		else
			return n + "th";
	}
	
}

