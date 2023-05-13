#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

char board[ROWS][COLS] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};

char player1 = 'X';
char player2 = 'O';

void printBoard() {
    cout << "   1   2   3  " << endl;
    cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin(char player) {
    // check for a win on the rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // check for a win on the columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // check for a win on the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    // no win condition found
    return false;
}

void takeTurn(char player, string color) {
    int row, col;
    bool validMove = false;
    do {
        cout << "Player " << player << ", it's your turn." << endl;
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;
        row--;
        col--;
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == ' ') {
            board[row][col] = player;
            validMove = true;
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    } while (!validMove);

    printBoard();

    if (checkWin(player)) {
        cout << "Congratulations, Player " << player << " (" << color << ") has won the game!" << endl;
        exit(0);
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    printBoard();

    while (true) {
        takeTurn(player1, "red");
        takeTurn(player2, "blue");
    }

    return 0;
}
