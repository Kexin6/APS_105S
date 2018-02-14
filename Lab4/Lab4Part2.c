#include <stdio.h>
#include <math.h>

//Virtual model of two functions 
int convertBinaryToDecimal (int intInput);
int convertDecimalToBinary (int intInput);

//Main function of the code
int main(int argc, char **argv)
{
	//Declare users' input of characters as B or D 
	char charInput;
	int intInput;
	printf ("Enter B for conversion of Binary to Decimal, OR\nEnter D for conversion of Decimal to Binary: ");
	scanf ("%c", &charInput);
	if (charInput == 'B') {
		printf ("Enter your number: ");
		scanf ("%d", &intInput);
		printf ("%d in binary = %d in decimal\n", intInput, convertBinaryToDecimal(intInput));
	} else if (charInput == 'D') {
		printf ("Enter your number: ");
		scanf ("%d", &intInput);
		printf ("%d in decimal = %d in binary\n", intInput, convertDecimalToBinary(intInput));
	} else {
		printf ("Enter your number: Invalid input; Goodbye\n");
	}
	return 0;
}

//function of converting binary numbers to decimal numbers
int convertBinaryToDecimal (int intInput) {
	int remainder, countNumber, count, answer, result, preResult;
	remainder = intInput;
	preResult = 0;
	
	//Determine how many digits are there in the binary number
	for (countNumber = 1; remainder > 0; countNumber ++) {
		remainder = remainder / 10;
	}
	
	//Calculate the binary numbers and turn them into decimal numbers
	for (count = 0; count <= countNumber; count ++) {
		answer = intInput % 10;
		result = answer * pow (2, count) + preResult;
		intInput = intInput / 10;
		preResult = result;
	}
	return (result);
}

//Function of converting decimal numbers to binary numbers
int convertDecimalToBinary (int intInput) {
	int countNumber, remainder, count, answer, result, preResult;
	remainder = intInput;
	preResult = 0;
	
	//Determine how many digits will there be in the decimal number
	for (countNumber = 1; remainder > 0; countNumber ++) {
		remainder =  remainder / 2;
	}
	
	//Calculate the decimal numbers and turn them into binary numbers
	for (count = 0; count <= countNumber; count ++) {
		answer = intInput % 2;
		result = answer * pow (10, count) + preResult;
		intInput = intInput / 2;
		preResult = result;
	}
	return (result);
}

	/*int count, quotient, remainder, result;
	for (count = 1; quotient != 0; count ++) {
		quotient = intInput / 2;
		remainder = intInput % 2;
		intInput = intInput - quotient;
		printf ("%d", remainder);
		 * first digit * 1 second * 10 etc. */
		