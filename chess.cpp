#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChessBoard {
public:
    vector<vector <char> > board;
    ChessBoard() {
        resetBoard();
    }

    void resetBoard() {
        board = {
                {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
        };
    }

    void displayBoard() {
        cout << "  a b c d e f g h" << endl;
        for (int i = 0; i < 8; i++) {
            cout << 8 - i << " ";
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << 8 - i << endl;
        }
        cout << "  a b c d e f g h" << endl;
    }

    bool movePiece(string from, string to) {
        int fromRow = 8 - (from[1] - '0');
        int fromCol = from[0] - 'a';
        int toRow = 8 - (to[1] - '0');
        int toCol = to[0] - 'a';
        
        if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
            toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
            cout << "Invalid move: Out of bounds!" << endl;
            return false;
        }

        if (board[fromRow][fromCol] == ' ') {
            cout << "Invalid move: No piece at source!" << endl;
            return false;
        }
        
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';
        return true;
    }
};

int main() {
    ChessBoard chess;
    string from, to;
    bool whiteTurn = true;
    
    while (true) {
        chess.displayBoard();
        cout << (whiteTurn ? "White's" : "Black's") << " move: ";
        cin >> from >> to;
        
        if (from == "quit" || to == "quit") break;
        
        if (chess.movePiece(from, to)) {
            whiteTurn = !whiteTurn;
        }
    }
    
    return 0;
}
