
public class Person
{
	// Instance variables
	private Name name;		// instance variable of type Name
	private Person spouse;	// instance variable of type Person
	
	// Constructors
	/**
	 * Constructor using fullname string
	 * @param fullName a String containing the person full name
	 */
	public Person(String fullName)
	{
		// use the fullName String to create the name object
		name = new Name(fullName);
	}
	
	/**
	 * Copy constructor
	 * @param aPerson an object of class Person to copy data from
	 */
	public Person(Person aPerson)
	{
		// copy the field name from the provided Person object
		name = new Name(aPerson.name);
	}
	
	// Public Methods
	/**
	 * setSopuse, sets the spouse instance variable
	 * @param sp an object of calss person
	 */
	public void setSpouse(Person sp)
	{
		// sets the spouse instance variable to the provided Person object
		// and set the corresponding spouse instance variable to link to the calling object
		spouse = sp;
		sp.spouse = this;
	}
	
	/**
	 * getName, get information about the calling object name
	 * @return String containtig a print out of the name instance variable
	 */
	public String getName()
	{
		// call the function toString of the name object
		return name.toString();
	}
	
	/**
	 * toString, output a string containing a summary of the information contained in the object
	 */
	public String toString()
	{
		// depending on the value in the spouse object an output is constructed
		String outputString;
		if (spouse != null)
			outputString = "Name: " + getName() + "\nMarried to: " + spouse.getName();
		else
			outputString = "Name: " + getName() ;
	
		return outputString;
	}
}
