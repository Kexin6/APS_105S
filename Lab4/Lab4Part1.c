#include <stdio.h>

//Define a function that can print character ' ' before '^'
void printChar (int number, char charToPrint) {
	int count;
	for (count = 1; count <= number; count ++) {
		printf ("%c", charToPrint);
	}
}

int main(int argc, char **argv)
{
	//Define row, rol and input variables and ask the user to input a number
	int row, col, input;
	printf ("Enter the number of rows in the triangle: ");
	scanf ("%d", &input);
	row = 1;
	
	//Print the first row
	printChar(input - row, ' ');
	printf ("^");
	printf ("\n");
	
	//Print the second row until the row before last row
	for (row = 2; row <= input - 1; row ++) {
		printChar(input - row, ' ');
		printf ("^");
		printChar(2 * row - 3, ' ');
		printf ("^");
		printf ("\n");
	}
	
	//Print the last row
	row = input;
	while (row == input && input != 1) {
		printChar(2 * input - 1, '^');
		printf ("\n");
		row = 0;
	}
	return 0;
}
