#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Prototypes of functions used.
void printBoard(char board[26][26], int dimension);
void movechess(char* gridpoint, char player);
bool positionInBounds(int dimension, char row, char col);
bool checkLegalInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol);
bool checkEightDirections(char board[][26], int dimension, char row, char col, char color);
void printLegalMoves(int dimension, char board[][26], char color);
bool isThereAMove(char board[][26], int dimension, char color);
void reverseInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol);
void reverseEightDirections(char board[][26], int dimension, char row, char col, char color);

//Main function
int main(int argc, char **argv){
	//Declaration of variables needed
	int dimensionInput, row, col;
	char board[26][26];
	char input[3], moveInput[3];
	bool validFlag, thereIsMoveFlagW, thereIsMoveFlagB;
	
	//Ask for user input in board dimension
	printf ("Enter the board dimension: ");
	scanf ("%d", &dimensionInput);
	
	//Initialize W and B in the board
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
	
	//Print out board and ask for configuration input
	printBoard(board, dimensionInput);
	printf ("Enter board configuration:\n");
	scanf ("%s", &input);
	while (input[0] != '!') {
		int row = (int) input[1] - 97;
		int col = (int) input[2] - 97;
		movechess(&board[row][col], input[0]);
		scanf ("%s", &input);
	}
	printBoard(board, dimensionInput);
	
	//Check if there is a move
	validFlag = true;
	thereIsMoveFlagW = true; 
	thereIsMoveFlagB = true;
	while (thereIsMoveFlagW == true && thereIsMoveFlagB == true && validFlag == true) {
		printLegalMoves(dimensionInput, board, 'W');
		printLegalMoves(dimensionInput, board, 'B');
		printf ("Enter a move:\n");
		scanf ("%s", &moveInput);
		
		//Check all directions for valid move and change the board according to user input
		bool check = checkEightDirections(board, dimensionInput, moveInput[1], moveInput[2], moveInput[0]); 
		if (check == true) {
			printf ("Valid move.\n");
			reverseEightDirections(board, dimensionInput, moveInput[1], moveInput[2], moveInput[0]);
			printBoard(board, dimensionInput);
		} else {
			printf ("Invalid move.\n");
			printBoard(board, dimensionInput);
			validFlag = false;
		}		
		thereIsMoveFlagW = isThereAMove(board, dimensionInput, 'W');
		thereIsMoveFlagB = isThereAMove(board, dimensionInput, 'B');	

	}

	return 0;
}

//It prints out the initialized board.
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

//It helps the play move the chess and change the board.
void movechess(char* gridpoint, char player) {
	*gridpoint = player;
}

//It checks whether the move is within the scope of the board or not.
bool positionInBounds(int dimension, char row, char col) {
	if (((int) row - 97 < dimension) && ((int) col - 97 < dimension) && ((int) row >= 97) && ((int) col >= 97)) {
		return true;
	} else {
		return false;
	}
}

//It checks whether it is legao to move in one direction of a postion.
bool checkLegalInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol) {
	bool bound = positionInBounds(dimension, row + deltaRow, col + deltaCol);
	bool available = false;
	char oppo;
	row = (int) row;
	col = (int) col;
	
	//Defines color as user and oppo as opponent
	if (color == 'W') {
		oppo = 'B';
	} else if (color == 'B') {
		oppo = 'W';
	}

	//If the first blank is not opponent color, the move is illegal immediately
	if (board[row - 97 + deltaRow][col - 97 + deltaCol] != oppo && bound == true) {
		available = false;
		return (available);
	}
	
	//Check available moves within the boundary
	while (bound == true) {
		row += deltaRow;
		col += deltaCol;
		bound = positionInBounds(dimension, row, col);
		if (board[row - 97][col - 97] == color) {
			available = true;
			return (available);
		} else if (board[row - 97][col - 97] == 'U') {
			available = false;
			return (available);
		} else {
			available = false;
		}
	}
	return false;
	
}

//It checks whether it is legal to move in eight directions of a position.
bool checkEightDirections(char board[][26], int dimension, char row, char col, char color) {
	bool result = false;
	for (int deltaRow = -1; deltaRow <= 1; deltaRow ++) {
		for (int deltaCol = -1; deltaCol <= 1; deltaCol ++) {
			if (!(deltaRow == 0 && deltaCol == 0)) {
				if (checkLegalInDirection(board, dimension, row, col, color, deltaRow, deltaCol) == true ) {
					result = true;
					return result;
				} else {
					result = false;
				}
			}
		}
	}
}

// It prints out the available moves for both W and B sides.
void printLegalMoves(int dimension, char board[][26], char color) {
	printf ("Available moves for %c:\n", color);
	for (int row = 0; row < dimension; row ++) {
		for (int col = 0; col < dimension; col ++) {
			if (board[row][col] == 'U'){
				if (checkEightDirections(board, dimension, (char) (row + 97), (char) (col + 97), color) == true) {
					printf ("%c%c\n", (char) (row + 97), (char) (col + 97));
				} 
			}
		}
	}
}

//It determines whether there can be any other moves
bool isThereAMove(char board[][26], int dimension, char color) {
	bool thereIsMove = false;
	for (int row = 0; row < dimension; row ++) {
		for (int col = 0; col < dimension; col ++) {
			if (board[row][col] == 'U' && ((checkEightDirections(board, dimension, row, col, 'W') == true) || (checkEightDirections(board, dimension, row, col, 'B') == true))) {
				thereIsMove = true;
			}
		}
	}
	return thereIsMove;
}

//It reverses the chess in one direction
void reverseInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol) {
	bool check = checkLegalInDirection(board, dimension, row, col, color, deltaRow, deltaCol);
	if (check == true) {
		while (board[(int) row -97][(int) col -97] != color) {
			board[(int) row - 97][(int) col - 97] = color;
			row += deltaRow;
			col += deltaCol;
		}
	}
}

//It reverses the chess in all possible directions
void reverseEightDirections(char board[][26], int dimension, char row, char col, char color) {
	bool bound = positionInBounds (dimension, row, col);
	for (int deltaRow = -1; deltaRow <= 1; deltaRow ++) {
		for (int deltaCol = -1; deltaCol <= 1; deltaCol ++) {
			if (!(deltaRow == 0 && deltaCol == 0) && bound == true){
				reverseInDirection(board, dimension, row, col, color, deltaRow, deltaCol);
				bound = positionInBounds (dimension, row, col);
			}
		}
	}
}