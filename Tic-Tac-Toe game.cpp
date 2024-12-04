#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
    vector<vector<char>> board;
    char currentMarker;
    int currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentMarker('X'), currentPlayer(1) {}

    void drawBoard() {
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    }

    bool placeMarker(int slot) {
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentMarker;
            return true;
        } else {
            return false;
        }
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    void displayResult() {
        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw()) {
            cout << "It's a draw!" << endl;
        }
    }

    void play() {
        while (true) {
            drawBoard();
            cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
            int slot;
            cin >> slot;

            if (slot < 1 || slot > 9) {
                cout << "Invalid slot! Please try again." << endl;
                continue;
            }

            if (!placeMarker(slot)) {
                cout << "Slot occupied! Try another slot." << endl;
                continue;
            }

            if (checkWin() || checkDraw()) {
                drawBoard();
                displayResult();
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.play();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
