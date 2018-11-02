//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAXCHANGE 100			// assume that the user will not ask for a change for more than 100

// Define global Variables
int diffCoins = 4;				// number of avilable coins to make change with
int coins[] = {1, 5, 10, 25};	// coins are quarters, dimes, nickels and pennies

int coinsUsed[MAXCHANGE];		// store a dynamic copy of coinsUsed for a specific change
int lastCoin[MAXCHANGE];		// store a dynamic copy of lastCoin used to make a specific change
int lastCall;					// keep track of change value for last function call

// Function Prototype deceleration 
int coinChange (int maxChange);

// Main program function
int main() {
	// Intialize global variables
	int i;
	for (i = 0; i < MAXCHANGE; i++)
	{
		coinsUsed[i] = 0;
		lastCoin[i] = 0;
		lastCall = 0;
	}
	
	// get user input and print change coins
	// 0 will terminate program
	int userInput = 0;
	int minCoins;
	int userCoins;
	do
	{
		// get user input
		printf("\nPlease enter an amount to get change for (0 to exit): ");
		scanf("%d",&userInput);
		
		// calculate change
		if (userInput != 0)
		{
			minCoins = coinChange (userInput);
			printf("\nminimum number of coins for %d cents is %d coins.\n", userInput, minCoins);
			
			// calculate and print change breakdown
			printf("coins used are:\n");
			for (i = 1; i < minCoins; i++)
			{
				userCoins = lastCoin[userInput];			// get a coin to use
				printf("%d + ",userCoins);					// print coin value
				userInput = userInput - userCoins;			// to get the next coin
			}
			userCoins = lastCoin[userInput];				// print last coin in sequance
			printf("%d\n",userCoins);						// without a plus sign
		}
	} while (userInput != 0);								// get another user input

	printf("\nGoodbye, have a nice day.\n\n");
	// return 0 to indicate successful termination
	return 0;
}


/*coinChange function
Objective: 	given coins of denominations coins[], make up change for maxChange cents,
			using the fewest number fo coins of the avilable denominations

Input:	an integer value for maxChange
		a set of varibles are defined golbaly to be used by the function
		to dynamicly store and reuse previous coin change calculations
		diffCoins, number of avilable coins to make change with
		coins[], coins denominations
		coinsUsed[MAXCHANGE], store a dynamic copy of coinsUsed for a specific change
		lastCoin[MAXCHANGE], store a dynamic copy of lastCoin used to make a specific change 

Output: the function outputs the min number of coins used for a change,
		but also alters the global arrays coinsUsed[], and lastCoin[]
*/

int coinChange (int maxChange)
{
	// check if maxChange is 0, return 0
	// since there are no ways of making change for 0 cents
	if (maxChange == 0)
		return 0;
	
	// if the number of coins was calculated for that change return value
	if (coinsUsed[maxChange] != 0)
		return coinsUsed[maxChange];
		
	// for this maxChange no caclulation was performed before,
	// accordingly we have to find the min number of coins
	// and save it for later use
	int cents;
	int minCoins;
	int newCoin;
	int j;
	//step 1
	for (cents = lastCall+1; cents <= maxChange ; cents++)	// steps 2, and 9 loop
	{
		// step 3
		minCoins = cents;		// assume that only cents will be used to provide change
		newCoin = 1;
		
		// find if we can provide change using fewer number of coins
		for (j = 1; j < diffCoins; j++)				// steps 4, and 7 loop
		{
			if (coins[j] > cents)					// step 5
				continue;							// skip to step 7, skip loop calculation
			
			// step 6
			if ((coinsUsed[cents - coins[j]] + 1) < minCoins)
			{
				minCoins = coinsUsed[cents - coins[j]] + 1;
				newCoin = coins[j];
			}
		}
		
		// step 8
		coinsUsed[cents] = minCoins;
		lastCoin[cents] = newCoin;
	}
	
	// array has been filled up to maxChange
	// update lastCall
	lastCall = maxChange;
	
	// step 10
	return minCoins;
}


