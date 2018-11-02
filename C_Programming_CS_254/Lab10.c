// preprocessor directives
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
 
 
// function prototypes
int nextPrime(int value);
int isPrime(int value);
int hashInsert(int value, int *hashTable, int *notEmpty, int tableSize, int *probeCount, int probeType);
 
 
#define NUM_OF_ELEMENTS 10000								// number of values to insert in map

// Main program function
int main()
{
    // variable decleration
    float alpha;                                            // final load factor
    int tableSize;                                          // hash table size
    int i;                                                  // loop counter
     
    // prompt user for input to get value of final load factor
    while(1)
    {
        printf("Please enter a value for the load factor between (0.1 and 0.9): ");
        scanf("%f",&alpha);
        if (alpha < 0.1 || alpha > 0.9)
            printf("Invalid input, please input a valid input in the specified range.\n");
        else
            break;
    }
     
    // calculate table size and create hash table
    tableSize = nextPrime(NUM_OF_ELEMENTS/alpha);
    int hashTable[tableSize];                               // array for hash table
     
    int notEmpty[tableSize];                                // not empty array intialized to zeros
    for (i = 0; i < tableSize; i++)                          // to indicate that all positions in hash table
        notEmpty[i] = 0 ;                                   // are empty
 
    // prompt user for input to get probe type
    int probeType;
    while(1)
    {
        printf("please choose a probe type (1=Linear, 2=Quadratic): ");
        scanf("%d",&probeType);
        if (probeType == 1 || probeType == 2)
            break;
        else
            printf("Invalid Choice!.\n");
    }
     
    // creat radnom values and insert in hashTable  
    srand (time(NULL));                                     // seed the random generator
    int hashKey;                                            // keep track of successful insertion
    int probeCount = 0;                                     // number of probs during insertion
    int value;                                              // for random number storage
    for ( i = 0; i < NUM_OF_ELEMENTS; i++ ) 
    {
        value = rand();                                     // randome integer to inseret in table
        hashKey = hashInsert(value, hashTable, notEmpty, tableSize, &probeCount, probeType);
        if (hashKey == -1)                                  // if returned key is -1, 
            break;                                          // it was not possibe to insert value
    }
    printf("after inserting %d values, the average number of probes is %f.\n", i, probeCount / (float) i);
    if (probeType == 1)                         // linear probing
    {
        float theoereticalAverage = (1 + (1/(1-alpha)))/2;
        printf("The theoretical average for linear probing is: %f\n", theoereticalAverage);
    }
     
    // return 0 to indicate sucessful termination of main
    return 0;
}
 
/*nextPrime function
Objective:      find the next prime number starting 
				form an input value, if the value
				is prime, it is returned as it is.
 
Inputs:
value:          an integer value

Outputs:
the first prime number starting with the input value is returned 
*/
int nextPrime(int value)
{
    // increment value until next prime is found
    while (!isPrime(value))
        value++;
         
    return value;
}


/*isPrime function
Objective:      find if an input value is a prime number
 
Inputs:
value:          an integer value

Outputs:
0 if the value is not prime, or 1 if the value is a prime number
*/ 
int isPrime(int value)
{
    if (value <= 1) 
        return 0;                                       // zero and one are not prime
         
    int i;                                              // loop counter
     
    // loop until you reach the square root of value,
    // if value could be devided without a remainder
    // than value is not prime
    for (i = 2; i*i <= value; i++)
    {
        if (value % i == 0) 
            return 0;
    }
 
    // value couldn't be devided, value is prime    
    return 1;
}

/*hashInsert function
Objective:      insert a key into a hash table, using linear probing
				or quadratic probing
 
Inputs:
value:			value to insert in a hash map
hashTable:		an integer pointer to an array for hash map
notEmpty:		an integer pointer to an array that 
				keeps track of which elements are empty
tableSize:		an integer value for table size
probeCount:		an integer pointer to keep track of number of probs made so far
probeType:		probeType, 1 for linear probing and 2 for quadratic probing

Outputs:
index of where element was inserte in map. a value of 
-1 indicates that value was not inserted and would mean that table is full
*/ 

int hashInsert(int value, int *hashTable, int *notEmpty, int tableSize, int *probeCount, int probeType)
{
    int j = 0;                                      // probe sequence counter
    int hashKey;
     
    hashKey = value  % tableSize;       // initial hashKey
     
    // try to insert value in table, as long as j is less than table Size
    while(j < tableSize)
    {
        (*probeCount)++;                        // increment probeCount
        // make sure that this location is empty
        if(!notEmpty[hashKey])
        {
            hashTable[hashKey] = value;
            notEmpty[hashKey] = 1;
            return hashKey;
        }
        // value was not inserted
        // recalculate hashKey based of probe type
        if (probeType == 1)                         // linear probing
            hashKey = (hashKey + 1) % tableSize;
        else if (probeType == 2)                    // quadratic probing
            hashKey = (hashKey + 2*j +1) % tableSize;
        j++;
    }
     
    // hashTabel is full, value couldn't be inserted
    return -1;
}
