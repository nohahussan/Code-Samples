/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
@SuppressWarnings("serial")
public class InvalidDayException extends Exception
{
	// Constructors
	public InvalidDayException()
	{
		super("Invalid Day");
	}
	
	public InvalidDayException(String message)
	{
		super(message);
	}
}
