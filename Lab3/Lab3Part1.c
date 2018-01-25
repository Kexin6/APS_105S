#include <stdio.h>

int main(int argc, char **argv)
{
	//Declare variables as integers
	int centNumber, centNumber2, nickelNumber, dimeNumber, quarterNumber;
	
	//Use while loop to achieve user testing for several times
	while (1) {
		printf ("Please give an amount in cents less than 100: ");
		scanf ("%d", &centNumber);
		
		// The way to quit the while loop and end the program is typing a number less than 0 or greater than 99
		if (centNumber >= 100 || centNumber <= 0) {
			printf ("Goodbye\n");
			return 0;
		}
		printf ("%d cents: ", centNumber);
		
		//Define the conversion amongs different units of currency
		quarterNumber = centNumber / 25;
		dimeNumber = (centNumber - (25 * quarterNumber)) / 10;
		nickelNumber = (centNumber - (25 * quarterNumber + 10 * dimeNumber)) / 5;
		centNumber2 = centNumber - (25 * quarterNumber + 10 * dimeNumber +5 * nickelNumber);
		
		//Different situations in printing quarter based on whether it is 0, 1 or others
		if (quarterNumber == 1) {
			if (centNumber == 25) {
				printf ("%d quarter.", quarterNumber);
			} else {
				printf ("%d quarter, ", quarterNumber);
			}
		} else if (quarterNumber == 0) {
			;
		} else {
			if (centNumber == 50 || centNumber == 75){
				printf ("%d quarters.", quarterNumber);
			} else {
				printf ("%d quarters, ", quarterNumber);
			}
		}
		
		//Different situations in printing dime based on whether it is 0, 1 or others
		if (dimeNumber == 1) {
			if (centNumber == 10) {
				printf ("%d dime.", dimeNumber);
			} else {
				printf ("%d dime, ", dimeNumber);
			}
		} else if (dimeNumber == 0) {
			;
		} else {
			if (centNumber == 20 || centNumber == 30 || centNumber == 40 || centNumber == 60 || centNumber == 70 || centNumber == 80 || centNumber == 90) {
				printf ("%d dimes.", dimeNumber);
			} else {
				printf ("%d dimes, ", dimeNumber);
			}
		}
		
		//Different situations in printing nickel based on whether it is 0, 1 or others
		if (nickelNumber == 1) {
			if (centNumber == 5) {
				printf ("%d nickel.", nickelNumber);
			} else {
				printf ("%d nickel, ", nickelNumber);
			}
		} else if (nickelNumber == 0) {
			;
		} else {
			if (centNumber == 15 || centNumber == 35 || centNumber == 45 || centNumber == 55 || centNumber == 65 || centNumber == 85 || centNumber == 95) {
				printf ("%d nickels.", nickelNumber);
			} else {
				printf ("%d nickels, ", nickelNumber);
			}
		}
		
		//Different situations in printing cent based on whether it is 0, 1 or others
		if (centNumber2 == 1) {
			printf ("%d cent.", centNumber2);
		} else if (centNumber2 == 0) {
			;
		} else {
			printf ("%d cents.", centNumber2);
		}
		printf ("\n");	
	}
	
	return 0;
	}
	



