/**
 * Shape Class
 * answer to Lab no 3, 60-212 summer 2014
 * This class represents an abstract shape object with width and height fields.
 * This class is extended to sub classes Triangle and Rectangle
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

public abstract class Shape
{
	// Instance Variables
	private static int shapeCount = 0;			// keep record of how many shape objects created
	private int width, height;					// dimensions of shape
	
	// Constructors
	public Shape(int initialWidth, int initialHeight)
	{
		// use mutator methods to initialze the instance variables
		setWidth(initialWidth);
		setHeight(initialHeight);
	}

	// public methods
	public void incrementShapeCount()
	{
		// increment shape count static variable
		shapeCount++;
	}
	
	public static int getShapeCount()
	{
		// return the value of shape count
		return shapeCount;
	}
	
	public void setWidth(int initialWidth)
	{
		// check the validity of width and set the value in the instance variable
		if (initialWidth >= 0)
			width = initialWidth;
		else
		{
			// if value is negative print an error message
			System.out.println("Error, Width is negative");
			System.exit(0);
		}
	}
	
	public void setHeight(int initialHeight)
	{
		// check the validity of height and set the value in the instance variable
		if (initialHeight >= 0)
			height = initialHeight;
		else
		{
			// is value is negative print an error message
			System.out.println("Error, Height is negative");
			System.exit(0);
		}		
	}
	
	public int getWidth()
	{
		return width;
	}

	public int getHeight()
	{
		return height;
	}
	
	// declare the abstract method getArea with a return of type double
	public abstract double getArea();
}
