/**
 * Contact class
 * provide a data type for storing contact information
 * including Name, phone number, and email address
 * Assignment no 4, 60-212 summer 2014
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

import java.util.StringTokenizer;

public class Contact 
{
	// Instance variables
	private Name name;			// contact name
	private String phone;		// contact phone number
	private String email;		// contact email address

	// Constructor
	/**
	 * constructs a new contact object using three arguments
	 * @param name, a String containing the contact's full name, 
	 * at least two names are needed for first and last names
	 * @param phone, a String containing the contact's phone number
	 * @param email, a String containing the contact's email address
	 * @throws InvlaidNameStringException 
	 */
	public Contact(String name, String phone, String email) throws InvlaidNameStringException
	{
		this.name = new Name(name);
		this.phone = phone;
		this.email = email;
	}

	/**
	 * constructs a new contact object using two arguments
	 * @param name, a String containing the contact's full name, 
	 * at least two names are needed for first and last names
	 * @param phone, a String containing the contact's phone number
	 * @throws InvlaidNameStringException 
	 */
	public Contact(String name, String phone) throws InvlaidNameStringException
	{
		this.name = new Name(name);
		this.phone = phone;
	}

	/**
	 * constructs a new contact object using one arguments
	 * @param name, a String containing the contact's full name, 
	 * at least two names are needed for first and last names
	 * @throws InvlaidNameStringException 
	 */
	public Contact(String name) throws InvlaidNameStringException
	{
		this.name = new Name(name);
	}


	// Mutator and Accessor methods
	/**
	 * sets tha name field of the contact object
	 * @param newName, a string containing the new name
	 * @throws InvlaidNameStringException, 
	 * if newName does not contain enough information for creating a name
	 * i.e. first name and last name 
	 */
	public void setName(String newName) throws InvlaidNameStringException
	{
		name = new Name(newName);
	}

	/**
	 * sets the phone number data of the contact object
	 * @param newPhone, a string containing the new phone number
	 */
	public void setPhone(String newPhone)
	{
		phone = newPhone;
	}

	/**
	 * sets the email address data of the contact object
	 * @param newEmail, a string containing the new email address
	 */
	public void setEmail(String newEmail)
	{
		email = newEmail;
	}

	/**
	 * return a string containing the 
	 * information stored in the name data field
	 * @return a string containing firstName middleName lastName, respectively 
	 */
	public String getName()
	{
		return (name.getFirstName() + " " + name.getMiddleName() + " " + name.getLastName());
	}

	/**
	 * return a string containing the contact phone number
	 */
	public String getPhone()
	{
		return phone;
	}

	/**
	 * return a string containing the contact email address 
	 */
	public String getEmail()
	{
		return email;
	}


	// Public Methods
	/**
	 * compare two objects of type Contact, to determine 
	 * if the calling object precedes the provided object, 
	 * alphabetical based on the name data field 
	 * @param otherContact, another Contact to compare calling object to
	 * @return true if calling objects precedes the otherContact based on Name
	 */
	public boolean lessThan (Contact otherContact)
	{
		if (this.name.getLastName().equals(otherContact.name.getLastName()))
		{
			return this.name.getFirstName().compareTo(otherContact.name.getFirstName()) < 0;
		}
		else
			return this.name.getLastName().compareTo(otherContact.name.getLastName()) < 0;		
	}

	/**
	 * Overwrite the toString method, and return a print out of the contact information
	 */
	public String toString()
	{
		return 	"Name: " + this.name +
				"\nPhone: " + (this.phone == null ? "" : this.phone) + 
				"\nEmail: " + (this.email == null ? "" : this.email);
	}


	
	/**
	 * Inner Class Name
	 * Provide a container for name data, including first, middle, and last names
	 */
	private class Name 
	{
		//instance variables
		private String firstName;		// String Object for first name
		private String middleName; 		// String Object for middle name
		private String lastName;		// String Object for last name

		//Constructors
		/**
		 * Constructor
		 * @param fullName a string object containing the full name 
		 * @throws InvlaidNameStringException 
		 */
		public Name(String fullName) throws InvlaidNameStringException
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
				throw new InvlaidNameStringException();
			}

			// set the instance variables to their corresponding values using mutator methods
			this.setFirstName(first);
			this.setMiddleName(middle);
			this.setLastName(last);
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
}