// Mini Game Project - Tic Tac Toe
// Submitted by: Shivam Kumar
// B.Tech ECE
// Date: 24 May 2026

#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }

    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

bool makeMove(int choice, char player) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() {
    int choice, moves = 0;
    char player = 'X';

    cout << "===== Tic Tac Toe =====\n";

    while(moves < 9) {
        displayBoard();

        cout << "Player " << player << ", enter position (1-9): ";
        cin >> choice;

        if(choice < 1 || choice > 9 || !makeMove(choice, player)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        moves++;

        if(checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "It's a draw!\n";

    return 0;
}