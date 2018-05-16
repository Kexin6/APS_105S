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
int checkFlipsInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol);
int checkFlipsEightDirections(char board[][26], int dimension, char row, char col, char color);
void computerPlay(char board[][26], int dimension, char color);
char decideWinner(char board[][26], int dimension);
bool isThereMove(char board[][26], int dimension, char color);
//int goldenCorners(char board[][26], int dimension, char row, char col, char color);
int checkScore(char board[][26], int dimension, char row, char col, char color);
int oppoLimited(char copyBoard[][26], int dimension, char row, char col, char color) ;
int numberOfChess(char board[][26], int dimension);

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
	const int numberFlips = 3, opponentMovesEliminated = 7;
	
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
	bool legal = false;
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
		legal = false;
		return (legal);
	}
	
	//Check legal moves within the boundary
	while (bound == true) {
		row += deltaRow;
		col += deltaCol;
		bound = positionInBounds(dimension, row, col);
		if (bound == false) {
			return false;
		}
		if (board[row - 97][col - 97] == color) {
			legal = true;
			return (legal);
		} else if (board[row - 97][col - 97] == 'U') {
			legal = false;
			return (legal);
		} else {
			legal = false;
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
int checkFlipsInDirection(char board[][26], int dimension, char row, char col, char color, int deltaRow, int deltaCol) {
	bool bound = positionInBounds(dimension, row + deltaRow, col + deltaCol);
	int flip = 0;
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
			flip ++;
		} else if (board[row - 97][col - 97] == 'U') {
			return 0;
		} else if (board[row - 97][col - 97] == color){
			return flip;
		}
	}
}	

//It adds up the score of one grid point from all directions
int checkFlipsEightDirections(char board[][26], int dimension, char row, char col, char color) {
	int result = 0;
	for (int deltaRow = -1; deltaRow <= 1; deltaRow ++) {
		for (int deltaCol = -1; deltaCol <= 1; deltaCol ++) {
			if (!(deltaRow == 0 && deltaCol == 0)){
					int flip = checkFlipsInDirection(board, dimension, row, col, color, deltaRow, deltaCol);
					result += flip;				
			}
		}
	}
	return result;
}

//This function controls the computer's chess move after knowing the highest score move
void computerPlay(char board[][26], int dimension, char color) {
	int maxScore = -999999999;
	int score[26][26];
	int i, j;
	int row, col;
	bool check = true;
	int myScore;
	int oppoScore;
	int LIMIT = 100;
    int chessNumber = numberOfChess(board, dimension);
    if (dimension <= 10){
		LIMIT = 9999;
	}
	
	for (row = 0; row < dimension; row ++) {
        if (maxScore > LIMIT) {
            break;
        }
		for (col = 0; col < dimension; col ++) {
			check = checkEightDirections(board, dimension, row + 97, col + 97, color);
			
			if (board[row][col] == 'U' && check == true){
				myScore = checkScore(board, dimension, (char) (row + 97), (char) (col + 97), color);
				oppoScore = oppoLimited(board, dimension, row + 97, col + 97, color);

				score[row][col] = myScore + oppoScore;
				if (score[row][col] > maxScore) {
					maxScore = score[row][col];
					i = row;
					j = col;
					if (maxScore > LIMIT) {
						break;
					}
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

//This function calculates my score
int checkScore(char board[][26], int dimension, char row, char col, char color) {
	bool bound, check;
	int flip;
	int myCorner;
	int result;
	int stableSides, unstablePoints;
	double flipWeight, cornerWeight, sideWeight, unstableWeight;
	//Weight of each component
	if (dimension == 6 || dimension == 10) {
		flipWeight = 1, cornerWeight = 30, sideWeight = 20, unstableWeight = -30;
	} else if (dimension == 18 && color == 'W'|| dimension == 16) {
		flipWeight = 1, cornerWeight = 1000, sideWeight = 200, unstableWeight = -200;
	} else if (dimension == 18 && color == 'B') {
		flipWeight = 1, cornerWeight = 1000, sideWeight = 200, unstableWeight = -5;
	} else if (dimension == 20 && color == 'W') {
		flipWeight = 1, cornerWeight = 100, sideWeight = 100, unstableWeight = -5;
	} else if (dimension >= 20 && color == 'B') {
		flipWeight = 150, cornerWeight = 400, sideWeight = 300, unstableWeight = -150;
	} else if (dimension >= 22) {
		flipWeight = 100, cornerWeight = 30, sideWeight = 20, unstableWeight = -10;
	}else if (dimension == 8) {
		flipWeight = 140, cornerWeight = 1000, sideWeight = 60, unstableWeight = -5;
	} else {
		flipWeight = 1, cornerWeight = 30, sideWeight = 20, unstableWeight = -10;
	}
	
	
	bound = positionInBounds(dimension, row, col);
	check = checkEightDirections(board, dimension, row, col, color) ;
	if (bound == false || check == false || board[row - 97][col - 97] != 'U') {
		return 0;
	} else {
		flip = checkFlipsEightDirections(board, dimension, row, col, color) ;
		if ((row == 'a' && col == 'a') || (row == 'a' && col == dimension + 96) || (row == dimension + 96 && col == 'a') || (row == dimension + 96 && col == dimension + 96)) {
			myCorner = 99;
		} else {
			myCorner = 0;
		}
	
		if (row == 'a' || row == dimension + 96 || col == dimension + 96 || col == 'a') {
			stableSides = 5;
		} else {
			stableSides = 0;
		}
		if (board[0][0] != color || board[0][dimension - 1] != color || board[dimension - 1][0] != color || board[dimension - 1][dimension - 1] != color ) {
			if ((row == 'b' && col == 'b') || (row == 'b' && col == dimension + 95) || (row == dimension + 95 && col == 'b') || (row == dimension + 95 && col == dimension + 95) || (row == 'b' && col == 'a') || (row == 'a' || col == 'b') || (row == dimension + 95 && col == 'a') || (row == dimension + 96 && col == 'b') || (row == dimension + 96 && col == dimension == 95) || (row == dimension + 95 && col == dimension + 96) || (row == 'a' && col == dimension + 95) || (row == 'b' && col == dimension + 96)) {
				unstablePoints = 4;
			} else {
				unstablePoints = 0;
			}

		}
		
		
	}
	result = flipWeight * flip + cornerWeight * myCorner + sideWeight * stableSides + unstableWeight * unstablePoints;
	
	return result;
}

//This function looks ahead to see the opponent score
int oppoLimited(char board[][26], int dimension, char row, char col, char color) {
	bool bound, check, thereIsMove;
	char copyBoard[26][26];
	char oppo;
	int oppoAvailable = 0;
	int scoreLimited;
	int oppoCorner;
	int oppoStableSides;
	int oppoAvailableWeight, oppoCornerWeight, oppoSidesWeight;
	if (dimension == 18 && color == 'B') {
		oppoAvailableWeight = -50, oppoCornerWeight = -150, oppoSidesWeight = 0;
	} else if (dimension == 16) {
		oppoAvailableWeight = -100, oppoCornerWeight = -500, oppoSidesWeight = -200;
	} else if (dimension >= 20 && color == 'W') {
		oppoAvailableWeight = -50, oppoCornerWeight = -150, oppoSidesWeight = -100;
	} else if (dimension >= 20 && color == 'B') {
		oppoAvailableWeight = -100, oppoCornerWeight = -1000, oppoSidesWeight = -1500;
	} else if (dimension == 8) {
		oppoAvailableWeight = -200, oppoCornerWeight = -1500, oppoSidesWeight = -200;
	} else {
		oppoAvailableWeight = -50, oppoCornerWeight = -99, oppoSidesWeight = 0;
	}
	
	if (color == 'W') {
		oppo = 'B';
	} else if (color == 'B') {
		oppo = 'W';
	}
	
	for (int i = 0; i < dimension; i ++) {
		for (int j = 0; j < dimension; j ++) {
			copyBoard[i][j] = board[i][j];
		}
	}
	
	reverseEightDirections(copyBoard, dimension, row, col, color);
	movechess(&copyBoard[row][col], color);
		for (int oppoRow = 0; oppoRow < dimension; oppoRow ++) {
			for (int oppoCol = 0; oppoCol < dimension; oppoCol ++) {
				bound = positionInBounds(dimension, oppoRow + 97, oppoCol + 97);
				check = checkEightDirections(copyBoard, dimension, oppoRow + 97, oppoCol + 97, oppo);
				thereIsMove = isThereMove(copyBoard, dimension, oppo);
				if (bound == true && check == true && copyBoard[oppoRow][oppoCol] == 'U' && thereIsMove == true) {
			
					oppoAvailable ++;
					if ((oppoRow == 0 && oppoCol == 0) || (oppoRow == 0 && oppoCol == dimension - 1) || (oppoRow == dimension - 1 && oppoCol == 0) || (oppoRow == dimension - 1 && oppoCol == dimension - 1)) {
						oppoCorner = 10;
					} else {
						oppoCorner = 0;
					}	
					if (oppoRow == 0 || oppoRow == dimension - 1|| oppoCol == dimension - 1 || oppoCol == 0) {
						oppoStableSides = 5;
					} else {
						oppoStableSides = 0;
					}
				} else {
					check = false;
				}
			}
		}
	
	//Calculation of score for opponent side
	scoreLimited = oppoAvailableWeight * oppoAvailable + oppoCornerWeight * oppoCorner + oppoSidesWeight * oppoStableSides;
	return scoreLimited;		
}

int numberOfChess(char board[][26], int dimension) {
    bool bound;
    int count = 0;
    for (int i = 0; i < dimension; i ++) {
        for (int j = 0; j < dimension; j ++) {
            bound = positionInBounds(dimension, i + 97, j + 97);
            if (bound && board[i][j] != 'U') {
                count ++;
            }
        }
    }
    return count;
}