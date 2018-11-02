// PreProcessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student structure defintion
struct student {
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

// functions prototype
int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
void printListRR(Student *List);
void searchList(Student *List);

// other supporting functions 
void flushInputStream ( void );


// main program function routine
int main() {
    // Variable decleration
    int choice = 0; // user menu choice
    Student *SLIST = NULL; // root pointer for student linked list
	
	// print menu and get user menu
    choice = getChoice();

	// Program loop, get user menu selection until user wants to quit
    while(choice >= 0) {
        switch(choice) {
            // quit
            case 0 : printf("Bye...\n"); exit(0);
            // prompet for user input and add student to list
            case 1 : SLIST = addToList(SLIST); break;
            // print list items in order
            case 2 : printList(SLIST); break;
            // print list items in reverse, using recursive
            case 3 : printListRR(SLIST); break;
            // search list for a student ID
            case 4 : searchList(SLIST); break;
            // input is not valid.
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice(); // reprint menu and get user input
    }

    if(SLIST) free(SLIST);
    return 0;
}


/* getChoice function
Objective	: Print a menu and get user menu choice 

Inputs		: No input.

Output		: an integer for user choice.
*/
int getChoice() {
    // integer for user choice input
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice); // get user input and save in choice
	
	// end of function
    return choice;
}

/* Define your functions below */

/* addToList function
Objective	: get user input for student ID and name and store 
			  it in a linked list

Inputs		: linked list root pointer to structure.

Output		: linked list root pointer to structure.
*/
Student *addToList(Student *List)
{
	// variable decleration
    Student *rootPtr = List ; // a temp storage for root pointer
    int ID; // student ID
    char name[40]; // Student Name
    
    // get user input for student information
    printf ( "Please enter student ID: " ) ;
    scanf ( "%d" , &ID ) ;
    flushInputStream () ; // discard line feed before next scanf read
    
    printf ( "Please enter student name: " ) ;
    scanf ( "%[^\n]" , name ) ;
    flushInputStream () ; // discard line feed before next scanf read

    // add student information to list
    if ( List == NULL )
    {
        // memory allocation for record 
        List =  malloc ( sizeof ( Student ) ) ;
        
        // copy information to structure
        ( List -> ID ) = ID ;
        strcpy ( ( List -> name ) , name ) ;
        ( List -> next ) = NULL ;
        
        rootPtr = List ;
    }
    else
    {
		// advance List pointer to the end of the linked list
		while ( ( List -> next ) != NULL )
			List = ( List -> next ) ;
		 
        //memory allocation for record
        ( List -> next ) =  malloc ( sizeof ( Student ) ) ;
        List = ( List -> next ) ;
        
        // copy information to structure
        ( List -> ID ) = ID ;
        strcpy ( ( List -> name ) , name ) ;
        ( List -> next ) = NULL ;
    }
    
    // end of function
    return rootPtr;
}


/* printList function
Objective	: print student information stored in a linked list

Inputs		: linked list root pointer to structure.

Output		: No output, function prints results.
*/
void printList(Student *List)
{
	// check if list is empty, i.e. root pointer is NULL
    if ( List == NULL )
    {
        printf ( "Student List is empty\n" ) ;
        return ;
    }
    else // if list is not empty
    {
        while ( List != NULL ) // loop over elements until List is NULL
        {
        	// print student record
            printf ( "%d %s\n" , List -> ID , List -> name ) ;
            // advance List pointer to point to next element
            List = ( List -> next ) ;
        }
    }
    
    // end of function
    return ;
}

/* printListRR function
Objective	: print student information stored in a linked list, 
			  in reverse order, using recursion

Inputs		: linked list root pointer to structure.

Output		: No output, function prints results.
*/
void printListRR(Student *List)
{
    if ( List == NULL)
    {
        return ;
    }
    else
    {
        // recursive call of function , untill it hits the NULL
        // on returns the student list will print records from the end
        printListRR ( List -> next ) ;
        printf ( "%d %s\n" , List -> ID , List -> name ) ;
    }
    
    // end of function
    return ;
}

/* searchList function
Objective	: get user input for a student ID, and 
			  search within a linked list for a matching record

Inputs		: linked list root pointer to structure.

Output		: No output, function prints results.
*/
void searchList(Student *List)
{
    int ID; // student ID

    // get user input
    printf ( "Please enter student ID: " ) ;
    scanf ( "%d" , &ID ) ;
    flushInputStream () ;
    
    // search for ID and print student record if found
    while ( List != NULL )
    {
        if ( ( List -> ID ) == ID )
        {
            printf ( "%d %s\n" , List -> ID , List -> name ) ;
            return ;
        }
        
        // move to next record
        List = List -> next ;
    }
    
    printf ( "ID %d not found\n" , ID );
    
    // end of function
    return ;
}


/* flushInputStream function
Objective	: reads and discards characters from the input stream
			  the purpose of this is to insure that any unread 
			  charcters are removed before the next scanf or fgets , etc

Inputs		: No input.

Output		: No output.
*/
void flushInputStream ( void )
{
    int c; // a temp storage for characters
    // loop until new line or end of file
    while ((c = getchar()) != '\n' && c != EOF);
    
    // end of function
    return ;
}
