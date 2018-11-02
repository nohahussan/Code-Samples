/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
@SuppressWarnings("serial")
public class InvalidYearException extends Exception
{
	// Constructors
	public InvalidYearException()
	{
		super("Invalid Year");
	}

	public InvalidYearException(String message)
	{
		super(message);
	}
}
