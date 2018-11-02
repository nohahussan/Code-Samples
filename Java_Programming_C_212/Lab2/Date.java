/**
 * Date Class
 * answer to Lab no 2, 60-212 summer 2014
 * This class represents a Date with day, month, and year fields.
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

import java.util.StringTokenizer;


public class Date 
{
	// Instance Variables
	private int day;
	private int month;
	private int year;
	
	// Constructors
	/**
	 * No Argument constructor, creates a Date object with default Date 1/1/1000
	 */
	public Date() 
	{
		this.setDay(1);			// set day to 1
		this.setMonth(1);		// set month to January
		this.setYear(1000);		// set year to 1000
	}
	
	/**
	 * Constructor that takes a Date string according to the format dd/mm/yyyy or
	 * dd-mm-yyyy
	 * @param dateString a string containing the initial Date
	 */
	public Date(String dateString)
	{
		// temp variables for Date storage
		int day, month, year;
		
		// string tokenizer is used to extract the data using / and - delimeters
		StringTokenizer dateTokenizer = new StringTokenizer(dateString, "/-");
		
		// string should contain at least 3 tokens to repesent a valid Date
		if(dateTokenizer.countTokens() != 3)
		{
			System.out.println("Invalid Date string");
			System.exit(0);
		}
		else
		{
			// Integer class parsInt is used to convert string to integer
			day = Integer.parseInt(dateTokenizer.nextToken().trim());
			month = Integer.parseInt(dateTokenizer.nextToken().trim());
			year = Integer.parseInt(dateTokenizer.nextToken().trim());
			
			// check the validity of the Date before storing in instance variables
			if (isValidDay(day) && isValidMonth(month) && isValidYear(year))				
			{
				this.setDay(day);
				this.setMonth(month);
				this.setYear(year);
			}
			else
			{
				// print an errot message if Date is not valid
				System.out.println("Invalid Date string");
				System.exit(0);
			}
		}
	}
	
	/**
	 * Copy constructor, is used to create a copy of Date object
	 * @param anotherDate a Date object to be copied
	 */
	public Date (Date anotherDate)
	{
		// copy instance variables to new Date
		this.day= anotherDate.day;
		this.month =anotherDate.month;
		this.year = anotherDate.year;
	}
	
	// Public Methods
	/**
	 * setDay Mutator method for day setting
	 * @param day an integer number for day data
	 */
	private void setDay(int day) 
	{
		// day is checked for validity before setting otherwise an error message is printed
		if (isValidDay(day))
			this.day = day;
		else
		{
			System.out.println("Invlid day");
			System.exit(0);
		}
		
	}
	
	/**
	 * setMonth Mutator method for month setting
	 * @param month an integer number for month data
	 */
	private void setMonth(int month) 
	{
		// month is checked for validity before setting otherwise an error message is printed
		if (isValidMonth(month))
			this.month = month;
		else
		{
			System.out.println("Invlid month");
			System.exit(0);
		}
	}
	
	/**
	 * setYear Mutator method for year setting
	 * @param year an integer number for year data
	 */
	private void setYear(int year) 
	{
		// year is check for validity before setting otherwise an error message is printed
		if (isValidYear(year))
			this.year = year;
		else
		{
			System.out.println("Invlid year");
			System.exit(0);
		}
	}

	
	/**
	 * getDay, get the value of the day field in the Date object
	 * @return an integer value for day data
	 */
	public int getDay() 
	{
		return day;
	}

	/**
	 * getMonth, get the value of the month field in the Date object
	 * @return an integer value for month data
	 */
	public int getMonth() 
	{
		return month;
	}

	/**
	 * getYear, get the value of the year field in the Date object
	 * @return
	 */
	public int getYear() 
	{
		return year;
	}

	/**
	 * earlierThan, compares Date object with another Date object to determine if calling object is earlier than anotherDate
	 * @param anotherDate a Date object for comparison
	 * @return a boolean value, true if calling Date is earlier than anotherDate, false otherwise
	 */
	public boolean earlierThan (Date anotherDate)
	{
		if (this.year < anotherDate.year)
			return true;				// if year is earlier than year return true 
		else if (this.year > anotherDate.year)
			return false;				// if year is later than year return false
		else							// if year is equal to year compare month data
		{
			if (this.month < anotherDate.month)
				return true;			// if month is earlier than month return true
			else if (this.month > anotherDate.month)
				return false;			// if month is later than month return false
			else						// if month is equal to month compare day data
			{
				if (this.day < anotherDate.day)
					return true;		// if day is earlier than day return true, otherwise return false
				else
					return false;
			}
		}
	}
	
	
	/**
	 * equals compare calling Date object to anotherDate and return true is they are equal
	 * @param anotherDate a Date object for comparison
	 * @return	a boolean value true if two dates are equal, false otherwise
	 */
	public boolean equals(Date anotherDate)
	{
		if (this.day == anotherDate.day &&
			this.month == anotherDate.month &&
			this.year == anotherDate.year)
			return true;
		else
			return false;
	}
	
	/**
	 * Output a string representation of Date data
	 */
	public String toString() {
		String dateString;
		
		// a string array contains string representation of month data
		String[] monthString = {"January" , "Febraury" , "March" , "April" , "May" , "June" ,
				                "July" , "August" , "September", "October", "November", "December"};
		
		// using month-1 as array index, compose dateString with Date data
		dateString = monthString[month-1] + " " + day + ", " + year;
		
		// return dateString
		return dateString;
	}

	// Private Methods
	/*
	 * isValidDay, check the validity of day data
	 * @param day an integer representing day data
	 * @return boolean data true, if data is valid
	 */
	private boolean isValidDay (int day)
	{
		return (day >= 1 && day <= 31);
	}
	
	/*
	 * isValidMonth, check the validity of month data
	 * @param month an integer representing month data
	 * @return boolean data true, if data is valid
	 */
	private boolean isValidMonth (int month)
	{
		return (month >= 1 && month <= 12);
	}
	
	/*
	 * isValidYear, check the validity of year data
	 * @param year an integer representing year data
	 * @return boolean data true, if data is valid
	 */
	private boolean isValidYear (int year)
	{
		return (year >= 1000 && year <=3000);
	}
}
