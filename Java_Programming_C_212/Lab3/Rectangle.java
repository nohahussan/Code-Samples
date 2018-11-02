/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

public class Rectangle extends Shape
{
	// Constructor
	public Rectangle(int initialWidth, int initialHeight)
	{
		super(initialWidth, initialHeight);
		incrementShapeCount();
	}
	
	// Public methods
	public double getArea()
	{
		// calculate the area of the shape
		return getWidth() * getHeight();
	}
	
	public String toString()
	{
		// construct string using getArea method
		return "Area: " + getArea();
	}
	
}
