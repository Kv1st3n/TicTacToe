#include <stdio.h>

void drawBoard(char board[4][4], int rows, int cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void updateBoard(int rows, int cols, char board[4][4], char symbol) {

	if (rows >= 0 && rows < 4 && cols >= 0 && cols < 4) {
		board[rows][cols] = symbol;
	}
	else {
		printf("Error: Out of bounds!\n");
	}

}

int isGameOver(char board[4][4]) {


	for (int i = 1; i < 4; i++) {

		if (board[i][1] != '_' && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
			return 1;
		}

		if (board[1][i] != '_' && board[1][i] == board[2][i] && board[2][i] == board[3][i]) {
			return 1;
		}

	}

	// check diagonal
	if (board[1][1] != '_' && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
		return 1;
	}
	if (board[1][3] != '_' && board[1][3] == board[2][2] && board[2][2] == board[3][1]) {
		return 1;
	}


	// check if nothing is empty
	for (int i = 1; i < 4; i++) {

		for (int j = 1; j < 4; j++) {

			if (board[i][j] == '_') {
				return 0;
			}
		}

		return 0;
	}
}

int checkIfSquareIsOccupied(char board[4][4], int row, int col){

	if (board[row][col] != '_') {
		printf("Square already taken! Try again.\n");
		return 1;
	}

	return 0;

}

void anyMovesLeft(char board[4][4]) {

}

char switchPlayer(int switchSymbol) {
	
	if (switchSymbol % 2 == 0) {
		return 'X';
	}
	else {
		return 'O';
	}
}

int main() {

	int row;
	int col;

	char board[4][4] = {
		{' ', '1', '2', '3'},
		{'1', '_', '_', '_'},
		{'2', '_', '_', '_'},
		{'3', '_', '_', '_'}
	};

	drawBoard(board, 4, 4);

	int round = 0;
	int switchSymbol = 0;

	while (round < 9) {

		char symbol = 'X';

		char playerSymbol = switchPlayer(switchSymbol);

		printf("Enter row: ");
		if (scanf_s("%d", &row) != 1) {
			printf("Invalid input! Please enter a number.\n");
			return 1;
		}

		printf("Enter column: ");
		if (scanf_s("%d", &col) != 1) {
			printf("Invalid input! Please enter a number.\n");
			return 1;
		}

		switchSymbol++;

		if (!checkIfSquareIsOccupied(board, row, col)) {
			updateBoard(row, col, board, playerSymbol);
			drawBoard(board, 4, 4);
		}
		else {
			drawBoard(board, 4, 4);
		}


		if (isGameOver(board)) {
			drawBoard(board, 4, 4);
			return 0;
		}

		round++;

	}

	printf("It's a draw!\n");
	return 0;
}