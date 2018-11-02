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

/* Read data from filr */
void ReadEmpRecord(Employee *EmpList , const char *FileName );

/* Format the contetnts of emplist by changing first letter to upper case */
void FormatEmpList(Employee *EmpList);

/* Save the employee records from the list to the newly created text 
file specified by FileName */
void SaveEmpList(const Employee *EmpList, const char *FileName);

/* convert the first letter of a word to upper case and the rest of the 
letters to lower case */
void WordCap ( char *word ) ;

/* print the contents of an employee list */
void PrintEmpList(const Employee *EmpList) ;

int main() 
{
	// variable decleration
	Employee EmployeeList[3]; // a structure array for Employee data
	
	// employee record from file
	ReadEmpRecord(EmployeeList , "employee.dat" ) ;
	printf ( "\n\n************ Unformatted Employee data ************\n" ) ;
	PrintEmpList(EmployeeList) ;
	
	// format employee data
	FormatEmpList(EmployeeList);
	printf ( "\n\n************ formatted Employee data ************\n" ) ;
	PrintEmpList(EmployeeList) ;
	
	// save employee data to a sequentioal file
	SaveEmpList(EmployeeList, "employee.dat");
	
	// end of main function routine
	return 0;
}


/* ReadEmpRecord function
Objective	: read employee data from a sequential file

Inputs		: two inputs 
			  1- a pointer to an employee structure array.
			  2- a pointer to a string array for filename

Output		: no return, function mdifies data content in memory.
*/
void ReadEmpRecord(Employee *EmpList , const char *FileName )
{
	FILE *FileId = fopen ( FileName , "r" ) ; // open file for reading
	
	int i ; // loop counter
	
	// loop for printing EmpList data
	for ( i = 0 ; i < 3 ; i++ , EmpList++ )
	{
		// print corresponding employee data record to file
		fscanf (FileId , "%d %s %s\n" 	, &(EmpList -> id) 
										, EmpList -> firstname 
										, EmpList -> lastname ) ;
	}	
	
	fclose ( FileId ) ; // close file
	
	//  end of function
	return ;
}

/* FormatEmpList function
Objective	: Format the contetnts of emplist by changing first 
			  letter of names to upper case.
			  
Inputs		: a pointer to an employee structure array.
			  
Output		: no return, function modifies contents of the memory.
*/
void FormatEmpList(Employee *EmpList)
{
	int i ; // loop counter
	
	// loop for format EmpList data
	for ( i = 0 ; i < 3 ; i++ , EmpList++ )	
	{
		// format firstname and last name
		WordCap ( EmpList -> lastname ) ;
		WordCap ( EmpList -> firstname ) ;
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

/* WordCap function
Objective	: Convert the first letter of a word or a sentence to upper case
			  and convert the rest of the letters to lowercase

Inputs		: a pointer to a string array.

Output		: no return, function mdifies data content in memory.
*/
void WordCap ( char *word )
{
    // convert first letter to uppercase
    *word = toupper ( *word ) ;
    word ++ ;

    // convert remaining letters to lowercase
    while ( *word != '\0' )
    {
        *word = tolower ( *word );
        word ++ ;
    }

    // end of function
    return ;
}
