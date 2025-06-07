#include <iostream>
#include <windows.h> 
using namespace std;

class TicTacToe {
private:
    char board[3][3];  
    char currentPlayer;

public:
    TicTacToe() : currentPlayer('X') {
       
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

   
    void displayBoard() {
        
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << endl;
        
    }

    
    bool checkWin() {
       
        for (int i = 0; i < 3; ++i) {
           
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    
    bool checkDraw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') return false;
        return true;
    }

    
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    
    bool takeInput() {
        int position;
        cout << "Player " << currentPlayer << ", choose a position (1-9): ";
        cin >> position;
        position--; 

        int row = position / 3;
        int col = position % 3;

        if (position < 0 || position >= 9 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    
    void playGame() {
        while (true) {
            displayBoard();
            if (!takeInput()) continue; 

            
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            
            switchPlayer();
        }
    }
};


int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}