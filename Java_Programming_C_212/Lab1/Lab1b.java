import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * answer to lab1b, 60-212 summer 2014
 * the program will continuously ask for a string
 * and count the number of vowels and show the 
 * shortest and longest words
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52 
 */
public class Lab1b
{

	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		Scanner keyboardInput = new Scanner(System.in);
		String userInput;
		char testChar;
		int vowelCounter;
		String shortestWord, longestWord, currentWord;
		
		// Continuously ask the user for a string until user inputs
		// quit
		while (true)
		{
			//Prompt the user for input
			System.out.println("Enter a sentence (“Quit” to quit):");
			userInput = keyboardInput.nextLine();
			userInput = userInput.trim();
			
			// did user input quit
			if (userInput.equalsIgnoreCase("quit"))
				break;
			
			// move over characters and count vowels
			vowelCounter = 0;
			for (int i = 0 ; i < userInput.length() ; i++)
			{
				testChar = userInput.charAt(i);
				if (testChar == 'a' || testChar == 'A' || 
					testChar == 'e' || testChar == 'E' || 
					testChar == 'i' || testChar == 'I' || 
					testChar == 'o' || testChar == 'O' || 
					testChar == 'u' || testChar == 'U' )
					vowelCounter++;
			}
			
			// Print number of vowels in string
			System.out.println("The number of vowels = " + vowelCounter);
			
			
			// Find Tokens in the string and print the word content
			System.out.println("The words are:");
			StringTokenizer stringTokenFinder = new StringTokenizer(userInput);
			shortestWord = "";
			longestWord = "";
			while (stringTokenFinder.hasMoreTokens()) 
			{
				currentWord = stringTokenFinder.nextToken();
				System.out.println(currentWord);
				
				// find and update record of longest and shortest words
				if (currentWord.length() < shortestWord.length() || shortestWord.length() == 0)
					shortestWord = currentWord;
				
				if (currentWord.length() > longestWord.length())
					longestWord = currentWord;
			}
			System.out.println("The shortest word: " + shortestWord);
			System.out.println("The longest word: " + longestWord);
			
		}

		// print goodbye and exit
		keyboardInput.close();
		System.out.println("Bye...");
		System.exit(0);
	}

}
