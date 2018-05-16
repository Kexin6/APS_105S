#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Prototypes of functions used.
void printBoard(char board[26][26], int dimension);
void movechess(char* gridpoint, char player);
bool positionInBounds(int dimension, char row, char col);
bool checkLegalInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol);
bool checkEightDirections(char board[][26], int dimension, char row, char col, char color);
void reverseInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol);
void reverseEightDirections(char board[][26], int dimension, char row, char col, char color);
int checkScoreInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol);
int checkScoreEightDirections(char board[][26], int dimension, char row, char col, char color);
void computerPlay(char board[][26], int dimension, char color);
char decideWinner(char board[][26], int dimension);
bool isThereMove(char board[][26], int dimension, char color);


//Main function
int main(int argc, char **argv){
	//Declaration of variables needed
	int dimensionInput, row, col;
	char board[26][26];
	bool validFlag = true;
	char computerColor;
	char playerInput[2];
	bool done = false;
	bool canMoveW = true;
	bool canMoveB = true;
	
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
	
	//It asks the user to input who plays first
	printf ("Computer plays (B/W) : ");
	scanf (" %c", &computerColor);
	printBoard(board, dimensionInput);
	char firstColor = computerColor;
	
	while (!done) {
		canMoveW = isThereMove(board, dimensionInput, 'W');
		canMoveB = isThereMove(board, dimensionInput, 'B');
		
		//The following block of codes is conducted if computer plays B
		if (firstColor == 'B') {
				if (canMoveB == true || canMoveW == true){
				//computer plays function first
				if (canMoveB == true) {
					computerPlay(board, dimensionInput, 'B');
					printBoard(board, dimensionInput);
				} else {
					printf ("B player has no valid move.\n");
				}			
			}
			canMoveW = isThereMove(board, dimensionInput, 'W');
			canMoveB = isThereMove(board, dimensionInput, 'B');
			//Player plays next
			if (canMoveW == true) {
				if (canMoveW == true && validFlag == true) {
					printf ("Enter move for colour W (RowCol): ");
					scanf ("%s", &playerInput);
					bool check = checkEightDirections(board, dimensionInput, playerInput[0], playerInput[1], 'W');
					//To check if the player has inputed a valid move
					if (check == true) {
						reverseEightDirections(board, dimensionInput, playerInput[0], playerInput[1], 'W');
						movechess(&board[playerInput[0] - 97][playerInput[1] - 97], 'W');
						printBoard(board, dimensionInput);
					} else {
						validFlag = false;
						printf ("Invalid move.\nB player wins.\n");
						done = true;
						return 0;
					}
				} else {
					printf ("W player has no valid move.\n");
				}
			}
			
		//The following block of codes is conducted if computer plays W
		} else if (firstColor == 'W') {
			canMoveW = isThereMove(board, dimensionInput, 'W');
			canMoveB = isThereMove(board, dimensionInput, 'B');
			//Player plays first
			if (canMoveB == true) {
				if (canMoveB == true && validFlag == true) {
					printf ("Enter move for colour B (RowCol): ");
					scanf ("%s", &playerInput);
					bool check = checkEightDirections(board, dimensionInput, playerInput[0], playerInput[1], 'B');
					//It checks if player's move is valid or not
					if (check == true) {
						reverseEightDirections(board, dimensionInput, playerInput[0], playerInput[1], 'B');
						movechess(&board[playerInput[0] - 97][playerInput[1] - 97], 'B');
						printBoard(board, dimensionInput);
					} else {
						validFlag = false;
						printf ("Invalid move.\nW player wins.\n");
						done = true;
						return 0;
					}
				} else {
					printf ("B player has no valid move.\n");
				}
			}
			
			canMoveW = isThereMove(board, dimensionInput, 'W');
			canMoveB = isThereMove(board, dimensionInput, 'B');
			//Computer plays next
			if (canMoveB == true || canMoveW == true) {
				if (canMoveW == true){
					computerPlay(board, dimensionInput, 'W');
					printBoard(board, dimensionInput);
				} else {
					printf ("W player has no valid move.\n");
				}
			}
			
		}
		
		canMoveW = isThereMove(board, dimensionInput, 'W');
		canMoveB = isThereMove(board, dimensionInput, 'B');
		//If there is no valid move for both players, the game is done
		if (canMoveW == false && canMoveB == false) {
			done = true;
		}
	}

	//It decides on the winner
	char winner = decideWinner(board, dimensionInput);
	if (winner == 'D') {
		printf ("Draw!\n");
	} else {
		printf ("%c player wins.\n", winner);
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
		if (bound == false) {
			return false;
		}
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
	
	//Determine whether the grid to test is empty. If it is not empty, then the player cannot place chess there
	if (board[row - 97][col - 97] != 'U') {
		return false;
	}
	
	//Check whether each direction can be changed
	for (int deltaRow = -1; deltaRow <= 1; deltaRow ++) {
		for (int deltaCol = -1; deltaCol <= 1; deltaCol ++) {
			if (!(deltaRow == 0 && deltaCol == 0)) {
				if (checkLegalInDirection(board, dimension, row, col, color, deltaRow, deltaCol) == true) {
					result = true;
					return result;
				} else {
					result = false;
				}
			}
		}
	}
	return result;
}

//It reverses the chess in one direction
void reverseInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol) {
	bool check = checkLegalInDirection(board, dimension, row, col, color, deltaRow, deltaCol);
	if (check == true) {
		row += deltaRow;
		col += deltaCol;
		while (board[(int) row - 97][(int) col - 97] != color) {
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

//It checks the score in one direction
int checkScoreInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol) {
	bool bound = positionInBounds(dimension, row + deltaRow, col + deltaCol);
	int score = 0;
	char oppo;
	row = (int) row;
	col = (int) col;
	
	//It identifies who is the opponent and who is the player
	if (color == 'W') {
		oppo = 'B';
	} else if (color == 'B') {
		oppo = 'W';
	}

	//It improves the efficiency by identifying whether the first grid point being tested is the opponent color
	if (board[row - 97 + deltaRow][col - 97 + deltaCol] != oppo && bound == true) {
		return 0;
	} else if (bound == false) {
		return 0;
	}
	
	//It calculates the score for one possible direction
	while (bound == true) {
		row += deltaRow;
		col += deltaCol;
		bound = positionInBounds(dimension, row, col);
		if (bound == false) {
			return 0;
		}
		
		if (board[row - 97][col - 97] == oppo) {
			score ++;
		} else if (board[row - 97][col - 97] == 'U') {
			return 0;
		} else if (board[row - 97][col - 97] == color){
			return score;
		}
	}
}	

//It adds up the score of one grid point from all directions
int checkScoreEightDirections(char board[][26], int dimension, char row, char col, char color) {
	int result = 0;
	for (int deltaRow = -1; deltaRow <= 1; deltaRow ++) {
		for (int deltaCol = -1; deltaCol <= 1; deltaCol ++) {
			if (!(deltaRow == 0 && deltaCol == 0)){
					int score = checkScoreInDirection(board, dimension, row, col, color, deltaRow, deltaCol);
					result += score;				
			}
		}
	}
	//printf ("RESULT: %d\n", result);
	return result;
}

//This function controls the computer's chess move after knowing the highest score move
void computerPlay(char board[][26], int dimension, char color) {
	int maxScore = 0;
	int score[26][26];
	int i, j;
	int row, col;
	bool check = true;
	bool bound = true;
	bool thereIsMove = true;

	for (row = 0; row < dimension; row ++) {
		for (col = 0; col < dimension; col ++) {
			check = checkEightDirections(board, dimension, row + 97, col + 97, color);
			if (board[row][col] == 'U' && check == true && thereIsMove == true){
				score[row][col] = checkScoreEightDirections(board, dimension, (char) (row + 97), (char) (col + 97), color);
				if (score[row][col] > maxScore) {
					maxScore = score[row][col];
					i = row;
					j = col;
				}
			} 
		}
	}
	
	//Calling the following functions help reverse the chesses and place the chess
	reverseEightDirections(board, dimension, i + 97, j + 97, color);
	movechess(&board[i][j], color);
	printf ("Computer places %c at %c%c.\n", color, (i + 97), (j + 97)); 
}

//It decides the winner by determining how many W or B are there and choose the one with more number
char decideWinner(char board[][26], int dimension) {
	int white = 0, black = 0;
	for (int row = 0; row < dimension; row ++) {
		for (int col = 0; col < dimension; col ++) {
			if (board[row][col] == 'W') {
				white ++;
			} else if (board[row][col] == 'B') {
				black ++;
			}
		}
	}	
	if (white > black) {
		return ('W');
	} else if (black > white) {
		return ('B');
	} else if (black == white) {
		return ('D');
	}
}

//It determines whether there is valid move remaining for the player
bool isThereMove(char board[][26], int dimension, char color) {
	bool check = false;
	for (int row = 0; row < dimension; row ++) {
		for (int col = 0; col < dimension; col ++) {
			if ((checkEightDirections(board, dimension, row + 97, col + 97, color) == true) && board[row][col] == 'U'){
				check = true;
			} 
		}
	}
	return check;
}
