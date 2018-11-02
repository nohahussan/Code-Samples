// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure definition
typedef struct
{
  int top;		// a location of the top element on the stack, -1 indicates that the stack is empty
  char *stack;	// a pointer to the stack array
} stack;

// Function Prototype deceleration 
int isBalanced (char *equationCharArray);
int isBalancedUsingSummation (char *equationCharArray);
void push(stack *stck, char item);
char pop(stack *stck);
int isEmpty (stack *stck);
void removeNewLineChar(char *line);
		
// Main program function
int main()
{
	char fileName[] = "input.txt";
	
	// check the balance of equations using stack
	FILE *file = fopen(fileName, "r");
	printf("******Balance Checking using a stack******\n");
	if (file != NULL)
	{
		char line [MAX]; 
		while (fgets (line, sizeof line, file) != NULL) /* read a line */
		{
			removeNewLineChar(line);
			printf("Equation -> %s is ",line);
			if (isBalanced (line))
				printf("Balanced\n");
			else
				printf("Not Balanced \n");
		}
		fclose (file);
	}
	else
	{
		perror (fileName); /* why didn't the file open? */
	}
	
	// check the balance of equations using summation
	file = fopen(fileName, "r");
	printf("\n\n******Balance Checking using Summation******\n");
	if (file != NULL)
	{
		char line [MAX]; 
		while (fgets (line, sizeof line, file) != NULL) /* read a line */
		{
			removeNewLineChar(line);
			printf("Equation -> %s is ",line);
			if (isBalancedUsingSummation (line))
				printf("Balanced\n");
			else
				printf("Not Balanced \n");
		}
		fclose (file);
	}
	else
	{
		perror (fileName); /* why didn't the file open? */
	}
	// return 0 to indicate successful termination
	return 0;
}

/*isBalanced function
Objective: 	check if character array is balanced in terms of parentheses

Inputs:
equation:a pointer to a character array that contains the equation 

Output:  a value of 1 if the parentheses is balanced, and a value of 0 otherwise
*/
int isBalanced (char *equationCharArray)
{
	//variable deceleration and initialization
	int stackLength = strlen(equationCharArray)/2;		// stack length is less than or equal half the string 
														// length
	char stackArray[stackLength];						// create a char array for stack application
	stack equationStack;								// create stack structure
	
	equationStack.top = -1;								// Intilaize stack as empty
	equationStack.stack = stackArray;					// assign stack to structure
	
	for( ; *equationCharArray != '\0' ; equationCharArray++) 
	{
		if (*equationCharArray == '(')
			push(&equationStack, '(');					// push item on stack
		else if (*equationCharArray == ')')				// pop item from stack
		{
			if (pop(&equationStack) == -1)				// if returned value is -1, the stack was empty,
				return 0;								// and the pop was unsuccessful, accordingly the eq is 
		}												// unbalanced		
    }

	if (!isEmpty(&equationStack))						// if stack is not empty, eq is not balanced
		return 0;
	else												// if stack is empty, eq is balanced
		return 1;
}

/*isBalancedUsingSummation function
Objective: 	check if character array is balanced in terms of parentheses

Inputs:
equation:a pointer to a character array that contains the equation 

Output:  a value of 1 if the parentheses is balanced, and a value of 0 otherwise
*/
int isBalancedUsingSummation (char *equationCharArray)
{
	//variable deceleration and initialization
	int summation = 0;									// intialize a summation to 0
		
	for( ; *equationCharArray != '\0' ; equationCharArray++) 
	{
		if (*equationCharArray == '(')
			summation++;								// add one to summation for every "("
		else if (*equationCharArray == ')')				// subtract one for every ")"
		{
			if (summation == 0)							// if summation is zero the closing ")",
				return 0;								// didn't have an openning "(" 
			summation--;								// otherwise its okay and subtract one frome summation
		}		
    }

	if (summation != 0)									// if summation is not zero, eq is not balanced
		return 0;
	else												// if summation is zero, eq is balanced
		return 1;
}

/*push function
Objective: 	push a character on the stack

Inputs:
stck: 	a pointer to a variable of type stack 
item:	a variable of type char to push on the stack

Outputs:
no output is provided, the stack is updated with the item
*/
void push(stack *stck, char item)
{
	// move stack top
	stck->top++;
	
	// add element to stack
	*(stck->stack + stck->top) = item;
	
	// terminate function
	return;	// optional
}

/*pop function
Objective: 	pop a character from the stack

Inputs:
stck: 	a pointer to a variable of type stack 

Output:	last char pushed on the stack, 
		a value of -1 indicates that the stack was empty
*/
char pop(stack *stck)
{
	if (stck->top == -1)								// stack is empty a pop operation is not possible
		return -1;
	else
	{
		char tempChar = *(stck->stack + stck->top);		// save value of top item
		stck->top--;									// move stack top
		return tempChar;								// return popped item
	}
}

/*isEmpty function
Objective: 	check if a stack is empty

Inputs:
stck: 	a pointer to a variable of type stack 

Output: 0, if the stack is not empty, or 1 if the stack is not empty
*/

int isEmpty (stack *stck)
{
	if (stck->top == -1)								// stack is empty
		return 1;
	else
		return 0;
}

/*isEmpty function
Objective: 	check if a stack is empty

Inputs:
line: 	a pointer to a chararray 

Output: no output, input is modified
*/
void removeNewLineChar(char *line)
{
	for( ; *line != '\0' ; line++) 
	{
		if (*line == '\n')
		{
			*line = '\0';
			return;
		}
	}
	
	// terminate function
	return;	// optional	
}
