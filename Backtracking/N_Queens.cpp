#include <iostream>
#include <cmath>

using namespace std;

// We use a global array to store queen positions 
// x[k] = i means Queen in row k is at column i
int x[20]; 
int n; // Size of the board (n x n)

// Function to check if placing a queen at (k, l) is safe
bool valid(int k, int l) {
    for (int i = 1; i < k; i++) {
        // 1. x[i] == l: Checks if another queen is in the same column
        // 2. abs(x[i] - l) == abs(i - k): Checks if another queen is on the same diagonal
        if (x[i] == l || abs(x[i] - l) == abs(i - k)) {
            return false;
        }
    }
    return true;
}

void NQueens(int k) {
    // Try placing a queen in each column (i) of the current row (k)
    for (int i = 1; i <= n; i++) {
        if (valid(k, i)) {
            x[k] = i; // Place the queen

            // Base Case: If we've placed queens in all rows, print the result
            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                // Recursive Step: Move to the next row
                NQueens(k + 1);
            }
            
            // Backtracking happens here: when the recursive call returns, 
            // the loop continues to the next 'i' to try a different column.
        }
    }
}

int main() {
    cout << "Enter the number of Queens: ";
    cin >> n;

    // Start the recursion from the first row
    NQueens(1);

    return 0;
}