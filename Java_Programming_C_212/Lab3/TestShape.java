/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

public class TestShape
{
	public static void main(String[] args)
	{
		// declare shape array object
		Shape[] shapeArray = new Shape[3];
		
		// create shapes objects using their respective constructors
		shapeArray[0] = new Rectangle(8,6);
		shapeArray[1] = new Triangle(8,6);
		shapeArray[2] = new Square(6);
		
		// print total number of shapes
		System.out.println("Total shapes created: " + Shape.getShapeCount());
		
		// print a summary of all shapes
		for (Shape shapeElement: shapeArray)
		{
			System.out.println("Object of class " + shapeElement.getClass() + ", " + shapeElement);			
		}
	}

}
