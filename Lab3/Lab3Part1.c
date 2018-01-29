#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
	//Declare variables as integers
	int centNumber, centOutput, nickelNumber, dimeNumber, quarterNumber;
	//To determine whether to use a coma or not
	bool comma = false;
	
	//Use while loop to achieve user testing for several times
	while (1) {
		printf ("Please give an amount in cents less than 100: ");
		scanf ("%d", &centNumber);
		// Set comma to false again in order to begin a new loop with correct commas
		comma = false;
		
		// The way to quit the while loop and end the program is typing a number less than 0 or greater than 99
		if (centNumber >= 100 || centNumber <= 0) {
			printf ("Goodbye.\n");
			return 0;
		}
		printf ("%d cents: ", centNumber);
		
		//Define the conversion amongs different units of currency
		quarterNumber = centNumber / 25;
		dimeNumber = (centNumber - (25 * quarterNumber)) / 10;
		nickelNumber = (centNumber - (25 * quarterNumber + 10 * dimeNumber)) / 5;
		centOutput = centNumber - (25 * quarterNumber + 10 * dimeNumber +5 * nickelNumber);
		
		//Different situations in printing quarter based on whether it is 1 or others
		if (quarterNumber == 1) {
			printf ("%d quarter", quarterNumber);
			//For the next currency, comma is always true
			comma = true;
		} else if (quarterNumber > 1) {
			printf ("%d quarters", quarterNumber);
			comma = true;
		}
		
		//Different situations in printing dime based on whether it is 1 or others
		if (dimeNumber == 1) {
			//According to the previous situation, if comma is true, it will print out ", "
			if (comma == true) {
				printf (", ");
			}
			printf ("%d dime", dimeNumber);
			comma = true;
		} else if (dimeNumber >1) {
			if (comma == true) {
				printf (", ");
			}
			printf ("%d dimes", dimeNumber);
			comma = true;
		}
		
		//Different situations in printing nickel based on whether it is 1 or others
		if (nickelNumber == 1) {
			if (comma == true) {
				printf (", ");
			}
			printf ("%d nickel", nickelNumber);
			comma = true;
		} else if (nickelNumber > 1) {
			if (comma == true) {
				printf (", ");
			}
			printf ("%d nickels", nickelNumber);
			comma = true;
		}
		
		//Different situations in printing cent based on whether it is 1 or others
		if (centOutput == 1) {
			if (comma == true) {
				printf (", ");
			}
			printf ("%d cent", centOutput);
			comma = true;
		} else if (centOutput > 1 ) {
			if (comma == true) {
				printf (", ");
			}
			printf ("%d cents", centOutput);
			comma = true;
		}
		
		//Print out dot and new line character since there is nothing following
		printf (".\n");	
	}
	
	return 0;
	}
	



