import java.util.Scanner;

/**
 * Answer to Lab1a, 60-212 summer 2014,
 * the program will ask the user to input an integer number
 * and will output a message to indicate if the number is a prime
 * number or not
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52 
 */
public class Lab1a
{

	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		Scanner keyboardInput = new Scanner(System.in);
		int userInput;
		
		// Continuously ask the user to enter a positive number
		// and check it is a prime number, exit if number is 
		// less than or equal to 1
		while (true)
		{
			// Prompt the user for a number
			System.out.println("Enter a number (1 to quit) :");
			userInput = keyboardInput.nextInt();
			
			// check if number is less than or equal 1
			if (userInput <= 1)
				break;
			
			if (isPrime (userInput))
				System.out.println(userInput + " is a prime number");
			else
				System.out.println(userInput + " is not a prime number");
	
		}
		
		// Print a goodbye message and exit
		System.out.println("Bye...");
		keyboardInput.close();
		System.exit(0);	
	}

	/**
	 * @param numberToBeChecked, an integer number to check if
	 * prime or not
	 * @output a boolean value to indicate if input is prime or not
	 */
	private static boolean isPrime(int numberToBeChecked)
	{
		// all even numbers are not prime except number 2
		if (numberToBeChecked == 2)
			return true;
		else if (numberToBeChecked%2 == 0)
			return false;
		
		// divide number by all numbers up to 
		// its half value to check if it is prime
		for (int i = 3 ; i <= numberToBeChecked/2 ; i++)
		{
			if (numberToBeChecked%i == 0)
				return false;
		}
		
		// at this point the number has proven not to be even 
		// and didn't divide over any other number, accordingly
		// the number is a prime
		return true;
	}

}
