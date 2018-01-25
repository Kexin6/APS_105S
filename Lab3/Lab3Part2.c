#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	//Declare numbers users should input as doubles and the calculation command as char
	double number1, number2, answer;
	char calculationCommand;
	
	//Ask the user to enter 2 numbers and the calculation command
	printf ("Enter first number: ");
	scanf ("%lf", &number1);
	printf ("Enter second number: ");
	scanf ("%lf", &number2);
	printf ("Enter calculation command (one of a, s, m, or d): ");
	scanf (" %c", &calculationCommand);
	
	//Compute the answer based on the numbers input and the calculation command chosen
	if (calculationCommand == 'a') {
		answer = number1 + number2;
		printf ("Sum of %.2lf and %.2lf is %.2lf\n", number1, number2, answer);
	} else if (calculationCommand == 's') {
		answer = number1 - number2;
		printf ("Difference of %.2lf from %.2lf is %.2lf\n", number1, number2, answer);
	} else if (calculationCommand == 'm') {
		answer = number1 * number2;
		printf ("Product of %.2lf and %.2lf is %.2lf\n", number1, number2, answer);
	} else if (calculationCommand == 'd') {
		if (number2 == 0) {
			printf ("Error, trying to divide by zero\n");
		} else {
			answer = number1 / number2;
			printf ("Division of %.2lf by %.2lf is %.2lf\n", number1, number2, answer);
		}
	} else {
		printf ("Error, unknown calculation command given\n");
	}
	
	return 0;
}
