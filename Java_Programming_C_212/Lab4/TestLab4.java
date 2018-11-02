package lab4b;


public class TestLab4 {

	public static void main(String[] args) {
		
		System.out.println("\nI can perform the following operations recursively:");
		
		MathWork dm = new MathWork();
		int choice;
		
		do{
			choice = dm.printMenu();
			switch (choice) {
			case 0 : 
				System.out.println("Bye...");
				System.exit(0);
			case 1 : 
				dm.factorial();
				break;
			case 2:
				dm.fibonacci();
				break;
			case 3 :
				dm.gcd();
				break;
			default : 
				System.out.println("Wrong choice! Try again:");
			}
		} while(choice != 0);
	}
}
