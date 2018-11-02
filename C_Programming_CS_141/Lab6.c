// Preprocessor Directives
#include <stdio.h>
#include <string.h>


// Function Prototype
void Reverse (char *);
void ParseSentence(char *);


// Main Program Function Routine
int main ( void )
{
	/* Part A. Character array and string */
	printf ( "/* Lab6.c Part A */\n" );
	// Declare char array buffer1, using array
	char buffer1 [] = 	{ 't' , 'h' , 'i' , 's' , ' ' , 'i' , 's' , ' ' , 't'
						, 'h' , 'e' , ' ' , 'f' , 'i' , 'r' , 's' , 't' , ' '
						, 'b' , 'u' , 'f' , 'f' , 'e' , 'r' , '\0' };
	
	// Declare a char array buffer2, using string literal
	char buffer2 [] = 	"this is the second buffer";
		
	// Declare char array buffer2, and input from keyboard using scanf
	char buffer3 [80] ;
	printf ( "Please enter a string:\n" );
	scanf  ( "%[^\n]s" , buffer3 );
	
	// Print all three buffer contents
	printf ( "first string : %s\n" , buffer1 );
	printf ( "second string : %s\n" , buffer2 );
	printf ( "third string : %s\n" , buffer3 );
	
	// Declare a char pointer pBuffer
	char *pBuffer = buffer3; // or &buffer[0]
	printf( "Buffer Contents using pointer : %s\n" , pBuffer);
	
	// advance pBuffer 3 positions
	pBuffer += 3;
	printf( "Buffer Contents using pointer after advancing 3 positions : %s\n" , pBuffer);
	
	
	/* Part B. String Manipulation: Reverse*/
	printf ( "\n\n/* Lab6.c Part B */\n" );
	// Declare a char array for reverse testing
	char testReverse[] = "Helloo";
	// print original array
	printf("Original String : %s\n" , testReverse);
	// apply reverse
	Reverse(testReverse);
	// print reversed array
	printf("Reversed String : %s\n" , testReverse);
	
	
	/* Part C. String Tokenization*/
	printf ( "\n\n/* Lab6.c Part C */\n" );
	// Declare str for ParseSentence testing
	char str[] = "Hello world, how are you today.";
	printf("String for Parsing : %s\n" , str);
	// call ParseSentence function
	ParseSentence(str);

	// end of program
	return 0 ;
}




/*objective : Reverses the contents of a char array.

  input     : one input a char array or a char pointer.
  
  output    : no output is returned, the function modifies 
              the values directly in the memory
*/
void Reverse (char *strStartPointer)
{
	// Declare a pointer to the end of string 
	// using startPointer and string length function
	// the -1 is used to point to the last character before '\0'
	char *strEndPointer = strStartPointer + strlen(strStartPointer) - 1; 
	
	char tempChar; 	// tempChar will be used as a temporary storage 
					// during character swaping 
	
	// reversing loop by swapping start character and last character
	// increment startPointer and decrement endPointer the stopping criteria is 
	// startPointer = endPointer , if array is even, or 
	// startPointer > endPointer , if array is odd
	while (strStartPointer < strEndPointer)
	{
		// swap edge characters using tempChar and pointers
		tempChar = *strStartPointer;
		*strStartPointer = *strEndPointer;
		*strEndPointer = tempChar;
		
		// move pointer to the next position
		strStartPointer++;
		strEndPointer--;
	}
	
	return;
}



/*objective : Tokenize a sentence by printing out words seprated by one
			  of the delimters space, comma, semicolon, and period.
			  
  input     : one input a char array or a char pointer.
  
  output    : no output is returned, the function prints 
  			  out the indvidual words
*/
void ParseSentence(char *str)
{
    char *tokenPtr; // tokenPtr will be used to point to begining of word
	
	// using strtok to tokenize the char array str, str is searched for one
	// of the delimters space, comma, semicolon, and period, 
	// when found is replaced by '\0' , and tokenPtr will be pointing 
	// at the begining of the word.
    tokenPtr = strtok( str , " ,;." );
	
	// in this loop strtok, is used with a NULL input, strtok remembers where it
	// stopped from previous calls, and continue from that point, if non of 
	// the delimters is found the function returns NULL, and this will terminate
	// the loop
    while( tokenPtr != NULL ) 
    {
    	// print the string from tokenPtr until '\0', which would print 
    	// a single word at a time as strtok is moving the pointer
    	printf( "%s\n", tokenPtr ) ;
    	tokenPtr = strtok( NULL, " ,;." ) ;   // Use NULL in successive calls
    }
}

