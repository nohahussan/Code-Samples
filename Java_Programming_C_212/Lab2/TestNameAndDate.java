
public class TestNameAndDate {

	public static void main(String[] args) {

		//testing Name class
		System.out.println("Testing Name class...");
		Name name1 = new Name("mary todd");
		Name name2 = new Name("John HENRY SmITh");
		Name name3 = new Name("quaZI r. rAhman");

		System.out.println(name1.toString());
		System.out.println(name2.toString());
		System.out.println(name3.toString());

		//testing Date class
		System.out.println("\nTesting Date class...");
		Date date1 = new Date("12/7 / 2008");
		Date date2 = new Date("20-11-2010");
		Date date3 = new Date("06/ 09 - 2002");

		System.out.println("date1 = " + date1.toString());
		System.out.println("date2 = " + date2.toString());
		System.out.println("date3 = " + date3.toString());

		System.out.println("date1 = " + date1.toString());
		System.out.println("date2 = " + date2.toString());
		System.out.println("date3 = " + date3.toString());
		System.out.println("date1 is " + (date1.earlierThan(date2) ? "earlier than " : "later than ") + "date2");
		System.out.println("date1 is " + (date1.earlierThan(date3) ? "earlier than " : "later than ") + "date3");
		System.out.println("date2 is " + (date2.earlierThan(date1) ? "earlier than " : "later than ") + "date1");
		System.out.println("date2 is " + (date2.earlierThan(date3) ? "earlier than " : "later than ") + "date3");
		System.out.println("date3 is " + (date3.earlierThan(date1) ? "earlier than " : "later than ") + "date1");
		System.out.println("date3 is " + (date3.earlierThan(date2) ? "earlier than " : "later than ") + "date2");

		Date date4 = new Date();
		System.out.println("date4 = " + date4.toString());
	}

}