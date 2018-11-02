
public class TestEmployee {

	public static void main(String[] args) {

		Employee e1, e2, e3, e4;
		Person p1;

		e1 = new Employee("Jhon Edward Kent", "12/6/2013", 35000.00);
		p1 = new Person("Silvia Kent");

		e1.setSpouse(p1);

		System.out.println(e1.toString() + " \n");
		System.out.println(p1.toString() + " \n");

		e2 = new Employee ("Robert William Hunter", "23/10/2005", 35000.00);
		e3 = new Employee ("John Smith", "15/11/2005", 25000.00);
		e4 = new Employee ("Mary Jane Hull", "06/09/2007");
		e3. setSalary(20000.00);
		e2.setSupervisor(e1);
		e3.setSupervisor(e2);
		e3.setSpouse(e4);
		e4.setSupervisor(e2);
		System.out.println("Number of employees = " + Employee.getEmployeeCount() + " \n");
		System.out.println("Supervisor of Robert is " + e2.getSupervisorName() + " \n");
		System.out.println(e2.toString() + " \n");
		System.out.println(e3.toString() + " \n");
		System.out.println(e4.toString() + " \n");
	}
}