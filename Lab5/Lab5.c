#include <stdio.h>
#include <math.h>

//Virtual models of three functions
void space(int rowNumber);
int factorial(int n);
void choose(int n);

//Main function
int main(int argc, char **argv)
{
	//Declaration in integers of input from users and the output of rows in order
	int rowInput = 1, row;
	//Ask users for input
	while (rowInput >= 0) {
		printf ("Enter the number of rows: ");
		scanf ("%d", &rowInput);
		//Print out the pascal triangle by calling space and choose functions
		for (row = 1; row <= rowInput; row ++) {
			space(rowInput + 1 - row);
			choose(row);
		}
	}
	
	return 0;
}

//Function used to print the spaces before numbers in each row
void space(int rowNumber) {
	int count;
	for (count = 0; count < rowNumber - 1; count ++) {
		printf ("   ");
	}
}

//Function to calculate factorial
int factorial(int n) {
	int count;
	int product = 1;
	for (count = 1; count <= n; count ++) {
		product = product * count;
	}
	return (product);
}

//Function to determine n and r to print out the numbers
void choose (int n) {
	int count, right, result;
	for (count = 0, right = n - 1; count < n; count ++, right --) {
		result = factorial(n - 1) / (factorial(right) * (factorial(n - 1 - right)));
		//Statement used to print out both numbers and spaces between two numbers
		printf ("%-6d", result);
	}
	printf ("\n");
}