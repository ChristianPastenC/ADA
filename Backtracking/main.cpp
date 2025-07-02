#include <iostream>
using namespace std;

class Sudoku {
private:
    static const int SIZE = 9;
    int board[SIZE][SIZE];

public:
    // Constructor to initialize the board
    Sudoku(int initialBoard[SIZE][SIZE]) {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                board[i][j] = initialBoard[i][j];
    }

    // Print the Sudoku board with 3x3 separators
    void printBoard() const {
        for (int row = 0; row < SIZE; ++row) {
            if (row != 0 && row % 3 == 0)
                cout << "------+-------+------" << endl;

            for (int col = 0; col < SIZE; ++col) {
                if (col != 0 && col % 3 == 0)
                    cout << "| ";

                cout << board[row][col] << " ";
            }
            cout << endl;
        }
    }

    // Solve the Sudoku using backtracking
    bool solve() {
        int row, col;

        if (!findEmptyCell(row, col))
            return true; // Solved

        for (int num = 1; num <= 9; ++num) {
            if (isSafe(row, col, num)) {
                board[row][col] = num;

                if (solve())
                    return true;

                board[row][col] = 0; // Backtrack
            }
        }

        return false; // Trigger backtracking
    }

private:
    // Check if it's safe to place a number in board[row][col]
    bool isSafe(int row, int col, int num) const {
        for (int i = 0; i < SIZE; ++i) {
            if (board[row][i] == num || board[i][col] == num)
                return false;
        }

        // Check 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[startRow + i][startCol + j] == num)
                    return false;

        return true;
    }

    // Find an empty cell
    bool findEmptyCell(int &row, int &col) const {
        for (row = 0; row < SIZE; ++row) {
            for (col = 0; col < SIZE; ++col) {
                if (board[row][col] == 0)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "-------- First Board --------" << endl;
    int boardA[9][9] = {
        {5, 0, 0, 9, 1, 3, 7, 2, 0},
        {3, 0, 0, 0, 8, 0, 5, 0, 9},
        {0, 9, 0, 2, 5, 0, 0, 8, 0},
        {6, 8, 0, 4, 7, 0, 2, 3, 0},
        {0, 0, 9, 5, 0, 0, 4, 6, 0},
        {7, 0, 4, 0, 0, 0, 0, 0, 5},
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 8, 9, 1, 6, 0, 0},
        {8, 5, 0, 7, 2, 0, 0, 0, 3}
    };

    Sudoku sudokuA(boardA);

    cout << "Unsolved Board:" << endl;
    sudokuA.printBoard();

    if (sudokuA.solve()) {
        cout << "\nSolved Board:" << endl;
        sudokuA.printBoard();
    } else {
        cout << "\nNo solution exists for this Sudoku." << endl;
    }

    cout << "\n-------- Second Board --------" << endl;

    int boardB[9][9] = {
        {6, 9, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 9, 6, 0, 0, 0},
        {0, 8, 0, 7, 5, 3, 0, 9, 0},
        {0, 2, 0, 3, 7, 4, 5, 6, 1},
        {3, 6, 0, 0, 0, 5, 0, 2, 0},
        {0, 0, 0, 9, 6, 0, 3, 7, 8},
        {0, 0, 6, 0, 3, 1, 0, 8, 4},
        {0, 4, 5, 8, 0, 7, 6, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 5, 7}
    };

    Sudoku sudokuB(boardB);

    cout << "Unsolved Board:" << endl;
    sudokuB.printBoard();

    if (sudokuB.solve()) {
        cout << "\nSolved Sudoku:" << endl;
        sudokuB.printBoard();
    } else {
        cout << "\nNo solution exists for this Sudoku." << endl;
    }

    return 0;
}
