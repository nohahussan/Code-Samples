/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

public class Square extends Rectangle
{
	//Constructor
	public Square(int initialSideLength)
	{
		super(initialSideLength, initialSideLength);
		// incrementShapeCount is not needed because
		// it is called within the super constructor
	}
	
	//Public methods
	public String toString()
	{
		// construct string using getArea method
		return "Area: " + getArea();
	}
	
}
