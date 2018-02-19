#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(char board[26][26], int dimension);
void movechess (char* gridpoint, char player);

int main(int argc, char **argv)
{
	int dimensionInput, row, col;
	char board[26][26];
	char input[3];
	printf ("Enter the board dimension: ");
	scanf ("%d", &dimensionInput);
	
	for (col = 0; col < dimensionInput; col ++) {
		for (row = 0; row < dimensionInput; row ++) {
			if (col == dimensionInput / 2 - 1 && row == dimensionInput / 2 - 1|| col == dimensionInput / 2 && row == dimensionInput / 2) {
				board[row][col] = 'W';
			} else if (col == dimensionInput / 2 - 1 && row == dimensionInput / 2|| col == dimensionInput / 2 && row == dimensionInput / 2 - 1) {
				board[row][col] = 'B';
			} else {	
				board[row][col] = 'U';
			}
		}
	}
	printBoard(board, dimensionInput);
	printf ("Enter board configuration:\n");
	scanf ("%s", &input);
	while (input[0] != '!') {
		int row = (int) input[1] - 97;
		int col = (int) input[2] - 97;
		movechess(&board[row][col], input[0]);
		printBoard(board, dimensionInput);
		scanf ("%s", &input);
	}
	
	
	return 0;
}

void printBoard(char board[26][26], int dimension) {
	int row, col;
	for(row = -1; row < dimension; row ++){
		for(col = -2; col < dimension; col ++){
			char alphabet = (char) 97;
			if (row == -1 && col == -2) {
				printf (" ");
			} else if (col == -2) {
				printf ("%c", alphabet + row);
			} else if (col == -1) {
				printf (" ");
			} else if (row == -1 && (col != -2 || col != -1)) {
				printf ("%c", alphabet + col);
			} else {
				printf ("%c", board[row][col]);
			}
		}
		printf ("\n");
	}
}


void movechess(char* gridpoint, char player) {
	*gridpoint = player;
}

