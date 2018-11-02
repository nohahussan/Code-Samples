@SuppressWarnings("serial")
public class NumberNotFoundException extends Exception 
{

	// Constructor
	public NumberNotFoundException()
	{
		super("Number not found");
	}
	
	public NumberNotFoundException(String message)
	{
		super(message);
	}
}