#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    while (true) {
        printBoard(board);
        
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        
        // Make the move
        board[row-1][col-1] = currentPlayer;
        
        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        
        // Check for a draw
        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
        
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
