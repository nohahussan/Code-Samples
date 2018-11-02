/**
 * ArrayAccess exception handling demonstration class
 * assignment 3, 60-212 Summer 2014 
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
import java.util.InputMismatchException;
import java.util.Scanner;

public class ArrayAccess {
	// Instance Variables
	private int[] array;					// array for storing user input
	private int arrayDataCount = 0;			// no of data points acquired from the user
	private Scanner keyboard;				// scanner object for user input

	// Constructor
	public ArrayAccess(int arraySize) 
	{
		array = new int[arraySize];			// declare array of size arraySize
		
		// print a message to user indicating the creation of the array
		System.out.println("Created an integer array of size " + arraySize);
	}

	// Public Methods
	public void testArray() 
	{
		keyboard = new Scanner(System.in);	// create a scanner object using the standred input
		boolean done = false;				// a boolean flag for loop control
		int userChoice = 0;					// variable for user menu choice storage
		
		while (!done)						// loop until user is done
		{
			try								// try catch block to get user menu input and execute corresponding function
			{
				userChoice = getMenuChoice();
				switch (userChoice)
				{
					case 1:
						getArrayElement();	// prompt user for inputing data to store in the array
						break;
					case 2:
						retriveValue();		// get value stored at a particular index
						break;
					case 3:
						searchForValue();	// search for a value in the array
						break;
					case 0:
						done = true;		// if user is done set done to true to exit loop
						break;
					default:
						// if input is not a valid menu selection print an error message
						System.out.println("Please make a selection between 1-3 (0 to quit).");
						break;
				}
				
			}
			// catch various exceptions that may arise during data input
			catch (InputMismatchException e) 
			{
				System.out.println("an InputMismatchException was caught, Input has to be an Integer value.");
			}
			catch (ArrayIndexOutOfBoundsException e) 
			{
				System.out.println("Currently the index must be within 0 - " + (arrayDataCount - 1));
			}
			catch (NumberNotFoundException e) 
			{
				System.out.println("Value to search could not be found.");
			}
			
			// to get rid of the newline character remaining from last scan
			keyboard.nextLine();
		}
		
		// print bye and finish program
		System.out.println("Bye...");
		keyboard.close();
	}

	// private methods
	private int getMenuChoice() 
	{
		// print menu and scan for user input
		System.out.println("\n****** MENU ******");
		System.out.println("(1)-Enter a value into the array.");
		System.out.println("(2)-Retrive a value using index.");
		System.out.println("(3)-Search for a value.");
		System.out.println("Enter your choice (0 to quit):");

		// read an integer input form the keyboard
		int userChoice = keyboard.nextInt();

		// return user input
		return userChoice;
	}

	/*
	 * prompt the user for input get an integer vlaue and add to array
	 */
	private void getArrayElement() 
	{
		System.out.println("Enter an integer to store:");
		array[arrayDataCount] = keyboard.nextInt();
		arrayDataCount++;
	}

	/*
	 * prompt the user for input to return array data at required index 
	 */
	private void retriveValue() 
	{
		// check if array has data available before user input
		if (arrayDataCount == 0)
			System.out.println("The array is empty. Cannot search an empty array!");
		// get user input for index
		else 
		{
			System.out.println("Enter the index:");
			int index = keyboard.nextInt();
			if (index < arrayDataCount)
				System.out.println("Value at position " + index + " is " + array[index]);
			// if index is outside the bounds of available data throw an exception
			else
				throw new ArrayIndexOutOfBoundsException();
		}
	}

	/*
	 * prompt the user for input look for value within the array
	 * and print the index it is found at, if integer is not found an exception is thrown
	 */
	private void searchForValue() throws NumberNotFoundException 
	{
		// only perform a search if array contains data
		if (arrayDataCount == 0)
			System.out.println("The array is empty. Cannot search an empty array!");
		// get user input to search for in array
		else 
		{
			System.out.println("Enter the value to search:");
			int searchValue = keyboard.nextInt();
			int index = 0;
			boolean valueFound = false;

			// search for value within the array
			for (int i = 0; i < arrayDataCount; i++) 
			{
				if (searchValue == array[i]) 
				{
					valueFound = true;
					index = i;
				}
			}

			// if value is found print location otherwise throw an exception
			if (valueFound)
				System.out.println("Found " + searchValue + " at position "+ index);
			else
				throw new NumberNotFoundException();
		} 
	}
	
}
