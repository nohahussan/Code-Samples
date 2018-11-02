/**

 * Name Class
 * answer to Lab no 2, 60-212 summer 2014
 * This class represents a name with first, middle, and last name fields.
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

import java.util.StringTokenizer;


public class Name 
{
	//instance variables
	private String firstName;		// String Object for first name
	private String middleName; 		// String Object for middle name
	private String lastName;		// String Object for last name
	
	//Constructors
	/**
	 * Constructor
	 * @param fullName a string object containing the full name 
	 */
	public Name(String fullName)
	{
		// string objects for name extraction
		String first= null;		
		String middle = null;
		String last = null;
		
		// string tokenizer used for name extraction
		StringTokenizer st = new StringTokenizer(fullName);
		
		// example "Noha Said Abdelmonaim Hussan"
		// firstName = Noha
		// middleName = Said Abdelmonaim
		// lastName = Hussan
		
		// string should contain at least two tokens otherwise the full name string is not valid
		int n = st.countTokens();
		if ( n > 1 )
		{
			first = st.nextToken();		// first token represents first name
			n--;
			for ( ; n > 1 ; n--)		// all other tokens before last token represents middle name
			{
				if (middle== null)
					middle = st.nextToken();
				else
					middle = middle + " " + st.nextToken(); // concatenate all middle tokens in one string for middles name
			}
			
			// last token extracted represents last name
			last = st.nextToken();
		}
		else
		{
			// print an error message if the no of tokens is less than 2
			System.out.println("Invlaid Name String");
			System.exit(0);
		}
		
		// set the instance variables to their corresponding values using mutator methods
		this.setFirstName(first);
		this.setMiddleName(middle);
		this.setLastName(last);
	}
	
	/**
	 * Copy Constructor 
	 * @param anotherName an object of class Name
	 */
	public Name (Name anotherName)
	{
		this.firstName = anotherName.firstName; 	// copy first name
		this.lastName = anotherName.lastName;		// copy last name
		this.middleName = anotherName.middleName;	// copy middle name
	}

	// Public Methods
	/**
	 * Mutator method for firstName
	 * @param firstName a string object containing first name
	 */
	public void setFirstName(String firstName) 
	{
		if (firstName != null)
			this.firstName = formatName(firstName);		// format string and save to firstName
	}

	/**
	 * Mutator method for middleName
	 * @param middleName a string object containing middle name
	 */
	public void setMiddleName(String middleName) 
	{
		if (middleName != null)
			this.middleName = formatName(middleName);	// format string and save to middleName
	}

	/**
	 * Mutator method for lastName
	 * @param lastName a string object containing last name
	 */
	public void setLastName(String lastName) 
	{
		if (lastName != null)
			this.lastName = formatName(lastName);		// format string and save to lastName
	}
	
	/**
	 * get the contents of the firstName field
	 * @return a string object for firstName
	 */
	public String getFirstName() {
		return firstName;
	}

	/**
	 * get the contents of the middleName field
	 * @return a string object for middleName
	 */
	public String getMiddleName() {
		return middleName;
	}

	/**
	 * get the contents of the lastName
	 * @return a string object for lastName
	 */
	public String getLastName() {
		return lastName;
	}

	
	/**
	 * an override for the toString method to output a formated string representing the full name
	 */
	public String toString() 
	{
		String nameString;
		// output is dependant on the middle name, if middle name exists output is formated to contain a middle name initial
		if (middleName == null)
			nameString = lastName + ", " + firstName;
		else
			nameString = lastName + ", " + firstName + " " + middleName.charAt(0) + ".";

		return nameString;
	}


	// Private Methods
	/*formatName, used to format name by setting the first letter to upper case
	 * and the rest of the name to lower case letters
	 * @param name a string containing the name to be formatted
	 * @return a string object that contains the formated name
	 */
	private String formatName(String name)
	{
		name = name.substring(0, 1).toUpperCase() + name.substring(1).toLowerCase();
		return name;
	}
	
}
