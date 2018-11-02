import java.util.Random;


public class TestSortedList {

	public static void main(String[] args) 
	{
		// Random number generator
		Random randomGenerator = new Random();
		
		// create first list
		SortedList myList = new SortedList("List1");
		for (int i = 0 ; i < 10 ; i++ )
			myList.insert(randomGenerator.nextInt(101));			// a random number between 0 and 100
		
		// create second list
		SortedList myOtherList = new SortedList("List2");
		for (int i = 0 ; i < 10 ; i++ )
			myOtherList.insert(randomGenerator.nextInt(101));		// a random number between 0 and 100
		
		// print lists
		myList.printList();
		myOtherList.printList();
		
		// merge second list in first list
		myList.merge(myOtherList);

		// print new list
		System.out.println("After merging List2 with List1");
		myList.printList();
	}
}
