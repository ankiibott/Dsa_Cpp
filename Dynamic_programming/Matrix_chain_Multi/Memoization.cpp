#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <cstring> // For memset

using namespace std;

// Global variables for convenience (common in competitive programming/learning)
int d[] = {10, 30, 5, 60}; // Matrix dimensions
int M[100][100];           // Memoization table (size depends on input constraints)

int m(int i, int j) {
    // 1. Base case from your notes: if start and end are same, cost is 0
    if (i == j) {
        M[i][j] = 0;
        return 0;
    }

    // 2. Check if the value is already calculated (Memoization check)
    if (M[i][j] != -1) {
        return M[i][j];
    }

    // 3. Initialize M[i][j] to a very large value
    M[i][j] = INT_MAX;
    int cost = 0;

    // 4. Try every possible split point k
    for (int k = i; k < j; k++) {
        // Store recursive results in the memo table as per your notes
        M[i][k] = m(i, k);
        M[k + 1][j] = m(k + 1, j);

        // Calculate total cost for this split
        cost = M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);

        // If this cost is better, update the memo table
        if (cost < M[i][j]) {
            M[i][j] = cost;
        }
    }

    return M[i][j];
}

int main() {
    int n = sizeof(d) / sizeof(d[0]) - 1;

    // Initialize the memoization table with -1 (indicates "not calculated")
    memset(M, -1, sizeof(M));

    cout << "Minimum cost (Memoized): " << m(1, n) << endl;

    return 0;
}