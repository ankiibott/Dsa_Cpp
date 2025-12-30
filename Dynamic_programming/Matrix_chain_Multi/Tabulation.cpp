#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Sample dimensions: A(10x30), B(30x5), C(5x60)
int d[] = {10, 30, 5, 60}; 

void matrixChainTabulation(int n) {
    // M[i][j] stores the minimum cost
    // K[i][j] stores the best split point 'k' to reconstruct the solution
    int M[100][100] = {0};
    int K[100][100] = {0};

    // 1. Base Case: Cost is 0 when multiplying one matrix (i == j)
    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;
    }

    // 2. Fill the table for chain lengths (diff) from 1 to n-1
    for (int diff = 1; diff < n; diff++) {
        for (int i = 1; i <= n - diff; i++) {
            int j = i + diff;
            M[i][j] = INT_MAX;

            // 3. Try every possible split point k between i and j
            for (int k = i; k < j; k++) {
                // cost = LeftPart + RightPart + MultiplicationCost
                int cost = M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);

                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    K[i][j] = k;    // Store the split point
                }
            }
        }
    }

    cout << "Minimum multiplication cost: " << M[1][n] << endl;
}

int main() {
    int n = sizeof(d) / sizeof(d[0]) - 1; // Number of matrices
    matrixChainTabulation(n);
    return 0;
}