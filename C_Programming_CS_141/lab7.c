// Preprocessor Directives
#include <stdio.h>
#include <math.h>


// Function Prototype
int AtoI ( const char * str );
int StrCmp ( const char * str1, const char * str2 );
char * StrCpy ( char * destination, const char * source );
char * StrCat ( char * destination, const char * source );
char * StrChr ( char * str, int character );


// Main Program Function Routine
int main (void)
{
	/* AtoI Function Testing */
	char charArray[] = "\a\b\f\n\r\t\v      -9534aaaa"; // define a charArray to convert to an integer
	// call the AtoI function and print the returned result
	printf("Converted number: %d\n",AtoI(charArray));
	
	
	/* StrCmp Function Testing */
	// define two string variable str1 and str2 to compare
	char str1[] = "Hello";
	char str2[] = "Hello";
	// compare the two strings and print the result, since the two strings are
	// equal the function will return 0
	printf("string compare result: %d\n" , StrCmp(str1,str2));
	
	
	/* StrCpy Function Testing */
	// declare two string variables destination (dest) of size 20, and
	// a source src that contains a string to be copied
	char dest[20];
	char src[] = "hello, there";
	char *ptr; // declare a pointer to a character to store the StrCpy return
	// call the StrCpy and print the destination 
	ptr = StrCpy( dest , src );
	printf("%s\n" , dest);
	
	
	/* StrCat Function Testing */
	char greating[20]; // declare a variable greeting of a size 20
	char name[10]; // declare a variable name of size 10
	StrCpy ( greating , "Hello, " ); // copy a string "Hello, " to the greating variable
	printf ( "What is your name: " ); // ask the user for a name 
	scanf ( "%s",name ) ;
	StrCat ( greating , name ) ; // Use the StrCat function to add the name to the graeting
	printf("%s\n" , greating) ; // print the greating
	
	
	/* StrChr Function Testing */
	// declare a string str3 for searching and a character to a pointer pch,
	// to store charcter address
	char str3[] = "This is a sample string";
	char * pch;
	// display a search message
	printf ("Looking for the 's' character in \"%s\"...\n",str3);
	// search str3 for the character 's' 
	pch=StrChr(str3,'s');
	
	// loop until no more character 's' is found
	while (pch!=NULL)
	{
		printf ("found at %d\n",pch-str3+1); // print the location of the 's' by 
		// subtracting pch from the str3 to get the relative position
		pch=StrChr(pch+1,'s'); // search for the next occurance of 's'
	}

	// end of program
	return 0;
}





/*objective : convert a char array to an integer.

  input     : one input a char array or a char pointer.
  
  output    : an integer containing the result of the conversion,
  			  will return 0 if no number is found.
*/
int AtoI ( const char * str )
{
	// calculate the string length by finding the address of the '\0' 
	// and subtracting the start pointer 
	int arrayLength = StrChr( (char *)str , '\0' ) - str;
	
	// declare an array to store the corresponding integer values
	int intArray[arrayLength];
	int temp; // store a temp value of the Integer conversion
	int i = 0; // loop counter
	int result = 0; // Intger conversion result
	int power; // a variable for base power calculation
	int negative = 0; // to store if the number has a leading negative sign.
	
	// consume the leading whitespace and control characters
	while ( *str != '\0')
	{
		if ( (*str >= 7 && *str <= 13) || *str == 32 )
			str ++ ;
		else
			break ;
	
	}
	
	// check if number has aleading negative sign
	if ( *str == '-' )
	{
		str ++ ;
		negative = 1 ;
	}
	else if (*str == '+' )
	{
		str ++ ;
		negative = 0 ;
	}
	
	// loop over array elements and convert each character to the corosponding
	// integer value
	for (i = 0 ; i < arrayLength ; i++ )
	{
		temp = *str - '0'; // Value is found by finding the relative ascii code
		// to the '0' character, a vlaue less than 0 or greater than 9 indicates
		// that the character is not a number , and the loop is broken
		
		if (temp >=0 && temp <=9)
		{	
			intArray[i] = temp;
			str ++ ;
		}	
		else
			break;
	}
	
	// update the array length to reflect the actual size of the integer values
	arrayLength = i;
	
	if (arrayLength == 0)
		return 0; // if length is 0 no numbers was found and return a value of 0
	
	// calculate the corresponding value by converting the numbers using base 10
	// i.e. intArray of size 3, result = i0 * 100 + i1 * 10 + i2 * 1
	for (i = 0, power = arrayLength - 1 ; i < arrayLength ; i++ , power--)
	{
		result += intArray[i] * pow(10,power);
	}
	
	if ( negative )
		return result * -1 ; // return a negative number
	else
		return result ; // return result
}


/*objective : Compare two string arrays to test if they are equal.

  input     : two pointers to char arrays.
  
  output    : 0 if the two strings are equal, 1 or -1 if not equal based 
  			  on the first letter that didn't match.
*/
int StrCmp ( const char * str1, const char * str2 )
{
	int temp; // store the charcter compare result 
	
	// loop over all elements of both arrays until '\0' if two chacters 
	// are not equal, i.e. subtraction is not equal to zero , return 1 or -1
	do
	{
		temp = *str1 - *str2; // subtract the two characters
		
		// test result to return if characters were not equal
		if (temp > 0)
			return  1;
		if (temp < 0)
			return -1;
			
		str1++; // advance pointers to next location
		str2++;
	} while (*str1 != '\0' || *str2 != '\0');
	
	// return 0, the two strings were equal since they finsihed the while loop
	// without returning
	return 0;
}



/*objective : Copy the contents of a source char array to a destination char array.

  input     : two pointers to char arrays.
  
  output    : a pointer to the destination array.
*/
char * StrCpy ( char * destination, const char * source )
{
	char *destPtr = destination; // save a copy of the destination array address
	// for the return statement
	
	// loop over source elements until '\0' null terminating chacter
	while (*source != '\0')
   	{
   		*destination = *source; // copy source to destination
   		destination++; // advance pointer address to next location
   		source++;
   	}
   	
   	// add null terminating character to the end of destination
   	*destination = '\0';
	
	// return destination pointer
	return destPtr;
}



/*objective : apply string concatination.

  input     : two pointers to char arrays.
  
  output    : a pointer to the destination array address.
*/
char * StrCat ( char * destination, const char * source )
{
	char *destPtr = destination; // save a copy of the destination array address
	// for the return statement 
	
	// advance the destination pointer until the null terminating character
	// to start adding the second array
	while (*destination != '\0') 
	{
		destination ++ ;
	}
	
	// copy the elements of the source array to the destiantion array
	// starting at the '\0' location
	while (*source != '\0')
	{
		*destination = *source ; // copy character to destination
		
		destination ++ ; // advance to next location
		source ++ ;
	}
	
	// add the null terminating character
	*destination = '\0';
	
	// return destination pointer
	return destPtr;
}




/*objective : search for a character within a char array.

  input     : a pointer to a char array and character to search for.
  
  output    : if the character is found address is returned otherwise the
  			  the function returns NULL.
*/

char * StrChr ( char * str, int character )
{
	
	// loop over array elements, if charcter is found return address
	while (*str != '\0')
	{
		if (*str == character) // compare and return address if found
			return str ;

		str ++ ; // advance pointer to next location
	}
	
	// check if the charcter to search for was the null terminating character
	if (*str == character)
		return str ;
	
	// return NULL the charcter was not found
	return NULL;
}

