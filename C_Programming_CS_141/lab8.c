// Preprocessor Directives
#include <stdio.h>
#include <string.h>


// Structure definition
struct myword
{
	char Word [21] ;
	int Length ;
};

typedef struct myword myWord ; // create an alias for struct myWord

// Main Program Function Routine
int main (void)
{
	myWord WordList[20]; // a myWord struct array, for word extraction
	char myString[] = "the cat in the hat jumped over the lazy fox";
	char *tokenPtr; // tokenPtr will be used to point to begining of word
	int wordCount = 0 ; // a counter for structure index
	
	
	// using strtok to tokenize the char array myString, 
	// myString is searched for the delimters space
	// when found is replaced by '\0' , and tokenPtr will be pointing 
	// at the begining of the word.
    tokenPtr = strtok( myString , " " );
	
	// in this loop strtok, is used with a NULL input, strtok remembers where it
	// stopped from previous calls, and continue from that point the delimters 
	// is not found the function returns NULL, and this will terminate the loop
    while( tokenPtr != NULL ) 
    {
    	// extract the string from tokenPtr until '\0'
		strcpy ( WordList[wordCount].Word , tokenPtr ) ;
		WordList[wordCount].Length = strlen ( tokenPtr ) ;
		wordCount ++ ;
		
		// Move pointer to next word
    	tokenPtr = strtok( NULL, " " ) ;   // Use NULL in successive calls
    }
    
    
    // print the contents of WordList
    int j ; // print loop counter
    printf ( "unsorted word List:\n" ) ;
    for ( j = 0 ; j < wordCount ; j++ )
    {
    	printf( "%s\n" , WordList[j].Word ); // print WordList at index j
    }
    
    
    // Bubble Sorting of struct array
    int k ; // internal loop counter
    char swapWord[21] ; // char array for word swap
    int swapLength ; // integer for length swaping
    
    for ( j = 0 ; j < wordCount - 1 ; j++ )
    {
    	for ( k = 0 ; k < wordCount - j - 1 ; k++ )
    	{
    		if ( strcmp ( WordList[k].Word , WordList[k+1].Word ) > 0 )
    		{
    			// swap words
    			strcpy ( swapWord , WordList[k].Word ) ;
    			strcpy ( WordList[k].Word , WordList[k+1].Word ) ;
    			strcpy ( WordList[k+1].Word , swapWord ) ;
    			
    			// swap length
        		swapLength = WordList[k].Length ;
    			WordList[k].Length = WordList[k+1].Length ;
    			WordList[k+1].Length = swapLength ;			
    		}
    	}
    }
    
    // print the contents of WordList after sorting
    printf ( "\nsorted word List:\n" ) ;
    for ( j = 0 ; j < wordCount ; j++ )
    {
    	printf( "%s\n" , WordList[j].Word ); // print WordList at index j
    }
    
	// end of program
	return 0;
}
