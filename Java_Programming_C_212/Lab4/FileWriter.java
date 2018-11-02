package lab4b;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;


public class FileWriter 
{
	// a static method will be used to write to the file
	// no calling object is needed
	// no constructor is needed because no objects can be created
	public static void write(String outputString, boolean appendFile)
	{
		try
		{
			// opening file for writing, using appendFile boolean value, 
			// an old file is appended or a new file is created
			FileOutputStream outFile = new FileOutputStream("testFile.txt" , appendFile);
			PrintWriter writer = new PrintWriter(outFile);
			
			// print String to file
			writer.println(outputString);
			
			// close file
			writer.close();
			
		}
		catch(FileNotFoundException e)
		{
			// if there is an error in opening the file 
			// print an error message and exit 
			System.out.println("Error opening the file testFile.txt");
			System.exit(0);
		}
		
	}
}
