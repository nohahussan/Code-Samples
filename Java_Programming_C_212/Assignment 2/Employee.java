
public class Employee extends Person
{
	// instance variables
	private static int employeeCount;		// records the number of employees created
	private int employeeNumber;				// unique number for every employee
	private Date dateJoined; 				// date the employee joined the company
	private double salary;					// salary
	private Employee supervisor; 			// supervisor object
	
	// Constructors
	/**
	 * Constructor, using fullName, joiningDate, startingSalary data,
	 * an object of class Employee is created
	 * @param fullName, a string containing the full name
	 * @param joiningDate, an object of class Date
	 * @param startingSalary, a string for Date
	 */
	public Employee(String fullName, String joiningDate, double startingSalary)
	{
		// using the constructor from the parent class, to set the name field
		super(fullName);
		// create a Date object using the Date String
		dateJoined = new Date(joiningDate);
		
		// Initialize salary with value from starting salary
		salary = startingSalary;
		
		// increment the employee count for all instanced of the class
		employeeCount++;
		
		// set the employee number data field
		employeeNumber = employeeCount;
	}
	
	/**
	 * Constructor, using fullName, and joiningDate, 
	 * an object of class Employee is created with 
	 * a default starting salary of 0
	 * @param fullName, a string containing the full name
	 * @param joiningDate, a string for Date
	 */
	public Employee(String fullName, String joiningDate)
	{
		// use three argument constructor with 
		// input data and 0 value for the salary
		this(fullName , joiningDate , 0);
	}
	
	/**
	 * Constructor, a copy constructor, makes a copy of all data fields
	 * @param emp, an object of class Employee
	 */
	public Employee(Employee emp)
	{
		// use copy constructor from parent class Person
		super(emp);
		
		// increment employee count and set the employee number
		employeeCount++;
		employeeNumber = employeeCount;
		
		// use copy constructor to copy Date field
		dateJoined = new Date(emp.dateJoined);
		
		// copy salary value and reference to supervisor
		salary = emp.salary;
		supervisor = emp.supervisor;
	}
	
	// public methods
	/**
	 * setSalary, sets the value of the salary
	 * @param newSalary, a double value for the salary
	 */
	public void setSalary(double newSalary)
	{
		salary = newSalary;
	}
	
	/**
	 * getSalary, returns the value of the salary
	 * @return, a double data conatining the value of the salary
	 */
	public double getSalary()
	{
		return salary;
	}
	
	/**
	 * getEmployeeCount, return the value of 
	 * the number of Employee objects created
	 * @return, an int data for the employee count
	 */
	public static int getEmployeeCount()
	{
		return employeeCount;
	}
	
	/**
	 * getEmployeeNumber, returns the value of the employee number
	 * @return, an int data containing the vlaue of the employee number
	 */
	public int getEmployeeNumber()
	{
		return employeeNumber;
	}
	
	/**
	 * setSupervisor, set the supervisor of the calling object to
	 * reference to another Employee object 
	 * @param emp
	 */
	public void setSupervisor(Employee emp)
	{
		supervisor = emp;
	}
	
	/**
	 * getSupervisorName, 
	 * returns the name of the supervisor Employee object
	 * @return, a string containing information about the supervisor name
	 */
	public String getSupervisorName()
	{
		if (supervisor != null)
			return supervisor.getName();
		else
			return "CEO (has no supervisor).";
	}

	/**
	 * toString, output a string summary of the object data
	 */
	public String toString()
	{
		String outputString = 	"Employee: " + getEmployeeNumber() + "\n" +
								super.toString() + "\n" +
								"Joined on: " + dateJoined + "\n" +
								"Supervisor: " + getSupervisorName() + "\n" +
								"Salary: " + getSalary();
		return outputString;					
	}
}
