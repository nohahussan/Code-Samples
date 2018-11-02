

import java.util.ArrayList;
import java.util.Scanner;

/**
 * ContactList class
 * contain ArrayList for storing contacts information
 * contain various methods for acquiring, editing and deleting contacts from the list
 * implements the interface Sortable, by sorting the contact list alphabetically
 * Assignment no 4, 60-212 summer 2014
 *
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
public class ContactList implements Sortable 
{
	// Instance variables
	private ArrayList<Contact> contactList;			// ArrayList containing contacts information
	private ArrayList<Contact> searchResultList;	// store a list of items found during list 
	private Scanner keyboard;						// scanner object for acquiring user input 
	boolean isSorted = false;						// keep track if list is sorted or not

	/**
	 * Constructor, initialize the contact list, and the search result list
	 * create a scanner object for getting user input
	 */
	public ContactList()
	{
		contactList = new ArrayList<Contact>();
		searchResultList = new ArrayList<Contact>();
		keyboard = new Scanner(System.in);
	}

	/**
	 * prompt the user for input to acquire contact information
	 * Name, phone, and email address. Store that data in list
	 */
	public void addContact() 
	{
		boolean done = false;
		String name, phone, email;

		while (!done) // while not done
		{
			try
			{
				// get contact information from the user
				System.out.println("Enter full name:");
				name = keyboard.nextLine();
				// add contact to the list
				Contact newContact = new Contact(name);
				// if Name String is not valid for name creation, an exception will be thrown and handled by the catch statement

				System.out.println("Enter phone number:");
				phone = keyboard.nextLine();
				if (!phone.isEmpty())
					newContact.setPhone(phone);

				System.out.println("Enter email address: ");
				email = keyboard.nextLine();
				if (!email.isEmpty())
					newContact.setEmail(email);

				// add contact to the list
				contactList.add(newContact);

				// array is not sorted anymore
				if (isSorted)
					isSorted = false;

			}
			catch(InvlaidNameStringException e)
			{
				System.err.println("Invalid Input for field name");
				// if input is incorrect for the name field, 
				// user will be notified and prompted to see 
				// if he/she wants to create another record
			}

			// ask the user if he/she wants to add another record
			done = !askUser("Add another contact?");
		}
	}

	/**
	 * acquire a search string and provide all contacts in list that contains that string
	 * anywhere in the contact information including name (first, last, and middle), phone
	 * and email address
	 */
	public void searchContact() 
	{
		boolean done = false;

		// if list isEmpty abort search
		if(contactList.isEmpty())
			System.out.println("Contacts List is empty");

		// search loop, search and report results until user is done
		while (!done && !contactList.isEmpty()) // while not done and list is not empty
		{
			// reset search results to perform search
			searchResultList.clear();

			// search for string within contactList
			searchContactList();

			// ask the user if he/she wants to search for another record
			done = !askUser("search for another contact?");
		}
	}

	/**
	 * edit the information for a specific contact, 
	 * first perform a search, if more than one result is found, 
	 * prompt the user to choose one and input new information to save 
	 */
	public void editContact() 
	{
		boolean done = false;
		Contact editContact;							// user selection of record to edit

		// temporary storage of user input
		String userString;
		int choice;
		Contact tempContact;

		// if list isEmpty abort edit
		if(contactList.isEmpty())
			System.out.println("Contacts List is empty");

		// search loop, search and report results until user is done
		while (!done && !contactList.isEmpty()) // while not done and list is not empty
		{
			// reset search results to perform search
			searchResultList.clear();
			editContact = null;

			// search for string within contactList
			searchContactList();


			// find out how many results were found during search
			int noOfResultsFound = searchResultList.size();

			// determine which contact to edit
			if (noOfResultsFound == 1) // if only one result is returned
			{
				editContact = searchResultList.get(0);
			}
			else if (noOfResultsFound != 0) // if more than one result is returned get user choice
			{
				while(true)
				{
					System.out.println("Choose a contact to edit: (1-" + noOfResultsFound + ") (0 to quit)");
					userString = keyboard.nextLine();
					choice = Integer.parseInt(userString);

					// check if user choice is valid
					if (choice > 0 && choice <= noOfResultsFound)
					{
						editContact = searchResultList.get(choice-1);
						break;
					}
					else if (choice == 0)
					{
						editContact = null;
						break;
					}

					// an invalid choice was made, print an error message
					System.err.println("invalid choice!");
				}
			}

			// edit selected contact information, if nothing is selected editIndex will be equal to -1
			if(editContact != null)
			{
				while(true) // loop until valid information is put for name field
				{
					try
					{
						// get contact information from the user
						System.out.println("Enter full name:");
						userString = keyboard.nextLine();
						// make a temporary Contact with name = userString
						tempContact = new Contact(userString);
						// if Name String is not valid for name creation, an exception will be thrown and handled by the catch statement

						System.out.println("Enter phone number:");
						userString = keyboard.nextLine();
						if (!userString.isEmpty())
							tempContact.setPhone(userString);

						System.out.println("Enter email address: ");
						userString = keyboard.nextLine();
						if (!userString.isEmpty())
							tempContact.setEmail(userString);

						// replace editContact to point to tempContact
						contactList.set(contactList.indexOf(editContact),tempContact);

						// array is not sorted anymore
						if (isSorted)
							isSorted = false;

						// break out of while loop
						break;
					}
					catch(InvlaidNameStringException e)
					{
						System.err.println("Invalid Input for field name");
					}
				}
			}

			// ask the user if he/she wants to search for another record
			done = !askUser("Edit another contact?");
		}
	}

	/**
	 * delete the information for a specific contact, 
	 * first perform a search, if more than one result is found, 
	 * prompt the user to choose one and remove from array, 
	 * 
	 * if array is sorted 
	 * contact is deleted by shifting all remaining contacts to keep them in order
	 * 
	 * if array is not sorted
	 * contact is replaced by the last element in the contact list, and deleting that element 
	 */
	public void deleteContact() 
	{
		boolean done = false;
		Contact deleteContact;							// user selection of record to edit

		// temporary storage of user input
		String userString;
		int choice;

		// if list isEmpty abort edit
		if(contactList.isEmpty())
			System.out.println("Contacts List is empty");

		// search loop, search and report results until user is done
		while (!done && !contactList.isEmpty()) // while not done and list is not empty
		{
			// reset search results to perform another search
			searchResultList.clear();
			deleteContact = null;

			// search for string within contactList
			searchContactList();

			// find out how many results were found during search
			int noOfResultsFound = searchResultList.size();

			// determine which contact to delete
			if (noOfResultsFound == 1) // if only one result is returned
			{
				deleteContact = searchResultList.get(0);
			}
			else if (noOfResultsFound != 0) // if more than one result is returned get user choice
			{
				while(true)
				{
					System.out.println("Choose a contact to delete: (1-" + noOfResultsFound + ") (0 to quit)");
					userString = keyboard.nextLine();
					choice = Integer.parseInt(userString);

					// check if user choice is valid
					if (choice > 0 && choice <= noOfResultsFound)
					{
						deleteContact = searchResultList.get(choice-1);
						break;
					}
					else if (choice == 0)
					{
						deleteContact = null;
						break;
					}

					// an invalid choice was made, print an error message
					System.err.println("invalid choice!");
				}
			}

			// delete selected contact information, if nothing is selected editIndex will be equal to -1
			if(deleteContact != null && askUser("Are you sure you want to delete this contact?"))
			{
				contactList.remove(deleteContact);
			}

			// ask the user if he/she wants to search for another record
			done = !askUser("Delete another contact?");
		}
	}

	/**
	 * Print out all contacts information contained in array list
	 */
	public void displayContacts() 
	{
		if (contactList.size() > 0)
		{
			boolean answer;
			// find if the user wants to display all contacts
			answer = askUser("Display all contacts?");

			if (answer)
			{
				// display all contacts
				for (Contact tempContact : contactList)
					System.out.println(tempContact);
			}
		}
		else
			System.out.println("Contacts List is empty");
	}

	/** 
	 * Sort all elements in Contact list alphabetically based on Name,
	 * the lessThan method of the contact class is used for this task. 
	 */
	public void sort() 
	{
		if (isSorted)
		{
			System.out.println("The list is already sorted!");
			return;
		}

		if (contactList.isEmpty())
		{
			System.out.println("Contacts List is empty");
			return;
		}
		
		// Sorting loops
		for (int i = 0 ; i < (contactList.size() - 1) ; i++)
		{
			// assume array is already sorted
			isSorted = true;

			for (int j = 0 ; j < (contactList.size() - i - 1) ; j++)
			{
				if (contactList.get(j+1).lessThan(contactList.get(j)))
				{
					// perform a swap between elements to put them in order
					Contact tempContact = contactList.get(j);
					contactList.set(j,contactList.get(j+1));
					contactList.set(j+1,tempContact);

					// since a swap is performed the array is not yet sorted
					isSorted = false;					
				}
			}

			// if inner loop finished without the need to do any swap, 
			// i.e. the isSorted assumption is still true
			// the array is now sorted and no further sorting is required
			// we can stop now to save time
			if (isSorted)
				break;
		}

		// Sorting is done
		isSorted = true;
		System.out.println("The list is sorted!");
	}

	// Private methods
	/*
	 * perform search on contact list based on user input for search string
	 */
	private void searchContactList()
	{
		String userString;

		if (contactList.size() > 0)
		{
			// get user input to search for in all contacts
			System.out.println("Enter text to search for:");
			userString = keyboard.nextLine();

			// find indices of contacts containing userString
			// convert all text to lower case to maximize results
			for (Contact tempContact : contactList)
			{
				String searchString = tempContact.getName() + tempContact.getPhone() + tempContact.getEmail(); 
				if (searchString.toLowerCase().contains(userString.toLowerCase()))
				{	
					// userString is contained in this contact
					searchResultList.add(tempContact);
				}
			}

			// search is done report results
			int noOfResultsFound = searchResultList.size();
			System.out.println(noOfResultsFound + " contact(s) found containing \"" + userString + "\".");
			for (int i = 0 ; i < noOfResultsFound ; i++)
				System.out.println("(" + (i+1) + ")\n" + searchResultList.get(i));
		}
		else
			System.out.println("Contacts List is empty");
	}

	/*
	 * ask user a provided yes/no question and return true or false based on his answer
	 * yes = true
	 * no  = false
	 */
	private boolean askUser(String question)
	{
		// string for user input using the scanner
		String userString;

		// get input, confirm its validity and return result
		while (true)
		{
			// find if the user wants to add another contact
			System.out.println( question +  " [Y/N]:");
			userString = keyboard.nextLine();

			if (userString.equalsIgnoreCase("y"))
			{
				// reset results array and count
				return true;
			}
			else if (userString.equalsIgnoreCase("n"))
			{
				return false;
			}

			// user didn't enter 'y' or 'n'
			System.out.println("Invlaid Input!");
		}
	}
}
