#include <iostream>

using namespace std;

// The Sudoku grid (9x9)
int S[10][10]; 

// Bounding function: Checks if placing 'val' at S[r][c] is valid
bool isValid(int r, int c, int val) {
    // 1. Check Row: ensures val isn't already in row r
    for (int i = 1; i <= 9; i++) {
        if (S[r][i] == val) return false;
    }

    // 2. Check Column: ensures val isn't already in column c
    for (int i = 1; i <= 9; i++) {
        if (S[i][c] == val) return false;
    }

    // 3. Check 3x3 Block: based on your pseudocode's block index logic
    int blockRow = r - (r - 1) % 3;
    int blockCol = c - (c - 1) % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (S[blockRow + i][blockCol + j] == val) {
                return false;
            }
        }
    }

    return true; // Bounding function passed
}

void sudoku(int r, int c) {
    // Base Case: If we reach row 10, column 1, the board is complete
    if (r == 10 && c == 1) {
        cout << "\nSolved Sudoku Grid:" << endl;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << S[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Determine the next cell coordinates
    int nextR = (c == 9) ? r + 1 : r;
    int nextC = (c == 9) ? 1 : c + 1;

    // If the current cell is not empty (pre-filled), skip to the next
    if (S[r][c] != 0) {
        sudoku(nextR, nextC);
    } else {
        // Try digits 1-9
        for (int i = 1; i <= 9; i++) {
            if (isValid(r, c, i)) {
                S[r][c] = i;        // Choice
                sudoku(nextR, nextC); // Explore
                S[r][c] = 0;        // Backtrack (Reset)
            }
        }
    }
}

int main() {
    cout << "Enter the 9x9 Sudoku grid (use 0 for empty cells):" << endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> S[i][j];
        }
    }

    sudoku(1, 1);

    return 0;
}