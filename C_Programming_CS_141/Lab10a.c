// preprocessor directives
#include <stdio.h>


// structure defintion
struct employee 
{
	char firstname[40];
	char lastname[40];
	int id;
};

typedef struct employee Employee;

// Function Prototype

/* Input the employee data interactively from the keyboard */
void InputEmpRecord(Employee *EmpList);

/* Display the contents of Employee records from the list */
void PrintEmpList(const Employee *EmpList);

/* Save the employee records from the list to the newly created text 
file specified by FileName */
void SaveEmpList(const Employee *EmpList, const char *FileName);

/* remove the new line character '\n' from the end of a string array */
void removeNewLine ( char *strPtr ) ;


int main() 
{
	// variable decleration
	Employee EmpList[3]; // a structure array for Employee data
	
	// get user data for 3 employees
	InputEmpRecord(EmpList);
	
	// print employee data
	PrintEmpList(EmpList);
	
	// save employee data to a sequentioal file
	SaveEmpList(EmpList, "employee.dat");
	
	// end of main function routine
	return 0;
}



/* InputEmpRecord function
Objective	: Input the employee data interactively from the keyboard

Inputs		: a pointer to an employee structure array.

Output		: no return, function modifies contents in the memory.
*/
void InputEmpRecord(Employee *EmpList)
{
	int i ; // loop counter
	
	// loop for getting user input
	for ( i = 0 ; i < 3 ; i++ , EmpList++ )	
	{
		printf ( "Employee Record no. %d\n" , i + 1 ) ;
		
		// First Name
		printf ( "First name : " ) ;
		fgets( EmpList -> firstname , 40 , stdin ) ;
		removeNewLine ( EmpList -> firstname ) ;
	
		// Last Name
		printf ( "Last Name : ") ;
		fgets( EmpList -> lastname , 40 , stdin ) ;
		removeNewLine ( EmpList -> lastname ) ;
		
		// ID
		EmpList -> id = ( i + 1 ) * 10 ;
	}	
	
	//  end of function
	return ;
}


/* PrintEmpList function
Objective	: Display the contents of Employee records from the list

Inputs		: a pointer to an employee structure array.

Output		: no return, function prints results on the screen.
*/
void PrintEmpList(const Employee *EmpList)
{
	int i ; // loop counter
	
	// loop for printing EmpList data
	for ( i = 0 ; i < 3 ; i++ , EmpList++ )	
	{
		// print corresponding employee data record
		printf ( "\n*********************************\n" ) ;
		printf ( "* Employee ID: %-16d *\n" , EmpList -> id ) ;
		printf ( "* Last Name: %-18s *\n" , EmpList -> lastname ) ;
		printf ( "* First Name: %-17s *\n" , EmpList -> firstname ) ;
		printf ( "*********************************\n" ) ;
	}	
	
	// end of function
	return ;
}

/* SaveEmpList function
Objective	: Save the employee records from the list to the newly created text 
			  file specified by FileName
Inputs		: two inputs 
			  1- a pointer to an employee structure array.
			  2- a pointer to a string array for filename

Output		: no return, function writes output to a file.
*/
void SaveEmpList(const Employee *EmpList, const char *FileName)
{
	FILE *FileId = fopen ( FileName , "w" ) ; // open file for writing
	
	int i ; // loop counter
	
	// loop for printing EmpList data
	for ( i = 0 ; i < 3 ; i++ , EmpList++ )	
	{
		// print corresponding employee data record to file
		fprintf (FileId , "%d %s %s\n" 	, EmpList -> id 
										, EmpList -> firstname 
										, EmpList -> lastname ) ;
	}	
	
	fclose ( FileId ) ; // close file
	
	// end of function
	return ;
}

/* removeNewLine function
Objective	: remove the new line character '\n' from the end 
			  of a string array.

Inputs		: a pointer to a string array.

Output		: No return, data is modified in memory.
*/
void removeNewLine ( char *strPtr )
{
	// loop until end of string
    while ( *strPtr != '\0' )
    {
    	// if '\n' is found change to the null terminating character
        if ( *strPtr == '\n' )
            *strPtr = '\0' ;
        // move to next character address
        strPtr++ ;
    }

	// end of function
    return ;
}
