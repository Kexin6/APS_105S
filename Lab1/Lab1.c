#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	//Declare five variables as doubles
	double number1, number2, number3, mean, standardDeviation; 
	
	//Ask for the user to enter three numbers
	printf ("Enter three numbers: "); 
	//Get three numbers from the user
	scanf ("%lf %lf %lf", &number1, &number2, &number3); 
	
	//Calculation of mean
	mean= (number1 + number2 + number3) / 3; 
	//Calculation of standard deviation
	standardDeviation=sqrt(pow((number1 - mean), 2) /2 + pow((number2 - mean), 2)/ 2 + pow((number3 - mean), 2)/ 2);
	
	//Output of the results based on calculations of user's inputs of numbers
	printf ("The mean is %.2lf and the standard deviation is %.2lf\n", mean, standardDeviation); 
	return 0;
}
