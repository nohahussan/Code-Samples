/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

public class Triangle extends Shape
{
	//Constructor
	public Triangle(int initialBase, int initialHeight)
	{
		super(initialBase, initialHeight);
		incrementShapeCount();
	}
	
	// public methods
	public double getArea()
	{
		// calculate and return area of shape
		return 0.5 * getWidth() * getHeight();
	}
	
	public String toString()
	{
		// construct string using getArea method
		return "Area: " + getArea();
	}
	
}
