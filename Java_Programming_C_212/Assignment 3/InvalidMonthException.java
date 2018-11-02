/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
@SuppressWarnings("serial")
public class InvalidMonthException extends Exception
{
	// Constructors
	public InvalidMonthException()
	{
		super("Invalid Month");
	}

	public InvalidMonthException(String message)
	{
		super(message);
	}
}
