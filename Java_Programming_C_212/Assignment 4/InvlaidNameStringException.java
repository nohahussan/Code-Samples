/**
 * InvalidNameStringException
 * provides an exception class for class Name,
 * this exception is thrown if provided full name
 * string is not valid for constructing a Name object
 * i.e. the name does not provide at least 
 * two names for first name and last name 
 * Assignment no 4, 60-212 summer 2014
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
@SuppressWarnings("serial")
public class InvlaidNameStringException extends Exception 
{
	/**
	 * Constructor, creates an object with default message 
	 */
	public InvlaidNameStringException()
	{
		super("Invalid String for class Name creation");
	}
	
	/**
	 * Constructor, creates an object with provided message String
	 * @param message, a String containing an exception message
	 */
	public InvlaidNameStringException(String message)
	{
		super(message);
	}
}
