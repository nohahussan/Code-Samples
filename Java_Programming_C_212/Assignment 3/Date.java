/**
 * Date Class provided by by 60-212 summer 2014
 * Modified by including Date validity 
 * checks and exceptions by
 * 
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */

import java.util.Scanner;
import java.util.StringTokenizer;
public class Date
{
	private int day;   // 1-31 based on month
	private int month; // 1-12
	private int year;  // 1000 - 3000

	private static final int[] daysInMonths = // days in each month
								{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	private static final String[] nameOfMonths = // name of months
				{"", "January", "February", "March", "April", "May", "June",
						"July", "August", "September", "October", "November", "December"};

	public Date( String aDate )
	{
		aDate = aDate.trim();
		StringTokenizer dateToken = new StringTokenizer( aDate, " /,.-" );

		if( dateToken.countTokens() < 3 ) {
			System.out.println("Invalid date entered. Default date object \"1/1/1000\" is created.");

			day = 1;
			month = 1;
			year = 1000;
		}
		else 
		{
			int tempDay = Integer.parseInt(dateToken.nextToken());
			int tempMonth = Integer.parseInt(dateToken.nextToken());
			int tempYear = Integer.parseInt(dateToken.nextToken());
			boolean notDone = true;
			
			// We should close the keyboard scanner object after we are done
			// but this causes error on next Date object construction
			// because once System.in stream is closed it cannot be reopened
			@SuppressWarnings("resource")
			Scanner keyboard = new Scanner(System.in);
			
			// loop until data for Date creation is valid
			while(notDone)
			{
				// try creating the Date object using mutator methods for 
				// day, month, and year, if any of the data is invalid
				// exceptions are caught and handled accordingly
				try
				{
					setYear(tempYear);
					setMonth(tempMonth);
					setDay(tempDay);
					notDone = false;
				}
				// for invalid year, prompt the user for a different year data
				catch (InvalidYearException e)
				{
					System.out.println("Invalid Year Exception");
					System.out.println("Invalid year. Enter a valid year (1000 - 3000):");
					tempYear = keyboard.nextInt();
				}
				// for invalid month, prompt the user for a different month data
				catch (InvalidMonthException e)
				{
					System.out.println("Invalid Month Exception");
					System.out.println("Invalid month. Enter a valid month (1 - 12):");
					tempMonth = keyboard.nextInt();	
				}
				// for invalid day, prompt the user for a different day data
				catch(InvalidDayException e)
				{
					System.out.println("Invalid Day Exception");
					System.out.println("Invalid day for " + nameOfMonths[month] + " of " + year + ". Enter a valid day:");
					tempDay = keyboard.nextInt();
				}
			}
			// We should close the keyboard scanner object after we are done
			// but this causes error on next date object construction
			// because once System.in stream is closed it cannot be reopened
			// keyboard.close();
		}
	} // end Date constructor

	public Date()//no-argument constructor, creates default date
	{
		this("1/1/1000");
	}

	public String getDate() //return date as dd/mm/yyyy
	{
		return day + "/" + month + "/" + year;
	}

	public void setDay(int d) throws InvalidDayException
	{
		// get the maximum number of days in month from daysInMonths array
		int maxDay = daysInMonths[month];
		
		// check if it is a leap year and the month is February, 
		// in which case change maxDay to 29
		if (month == 2 && isLeapYear())
			maxDay = 29;
		
		// check the validity of the day
		if (d > 0 && d <= maxDay) 
			day = d;
		else
			throw new InvalidDayException();
	}

	public int getDay(){
		return day;
	}

	public void setMonth(int m) throws InvalidMonthException
	{
		// check the validity of the month
		if ( m > 0 && m <= 12)
			month = m;
		else
			throw new InvalidMonthException();
	}

	public int getMonth(){
		return month;
	}

	public void setYear(int y) throws InvalidYearException
	{
		// check the validity of the year
		if ( y >= 1000 && y <= 3000)
			year = y;
		else
			throw new InvalidYearException();
	}

	public int getYear(){
		return year;
	}

	public boolean earlierThan( Date otherDate )
	{
		if( this.year < otherDate.year )
			return true;

		else if( this.year == otherDate.year )
		{
			if( this.month < otherDate.month )
				return true;
			else if(this.month == otherDate.month ) {
				if( this.day < otherDate.day )
					return true;
			}
		}
		return false;
	}

	public boolean equals( Date otherDate )
	{
		if( this.year == otherDate.year &&
			this.month == otherDate.month &&
			this.day == otherDate.day )
		//then
			return true;
		//otherwise
		return false;
	}

	public String toString()
	{
		return nameOfMonths[month] + " " + day + ", " + year;
	}

	// Private methods
	private boolean isLeapYear()
	{
		/* 
		 * ******************* Leap year Algorithm *********************
		 * (1) Every year that is evenly divisible by four is a leap year;
		 * (2) of those years, if it can be evenly divided by 100, it is NOT a leap year, unless 
		 * (3) the year is evenly divisible by 400. Then it is a leap year.
		 */
		
		if ( (year % 4) != 0 ) //year is not divisible by 4 then common year
			return false;
		else if ( (year % 100) != 0 )  //year is not divisible by 100 then leap year
			return true;
		else if ( (year % 400) != 0 )//year is not divisible by 400 then common year
			return false;
		else  //leap year
			return true;
	}
}
