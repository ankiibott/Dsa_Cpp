#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // n = number of items, m = max capacity
    int n = 4;
    int m = 5; // Example capacity

    // Using 1-based indexing as shown in your image (index 0 is a placeholder '-')
    int P[] = {0, 6, 5, 3, 8}; 
    int w[] = {0, 1, 2, 1, 2};

    // Initialize 2D table T with zeros
    // Size is (n+1) rows and (m+1) columns
    vector<vector<int>> T(n + 1, vector<int>(m + 1, 0));

    // Applying the exact for-loop structure from your image
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i] <= j) {
                // Your handwritten formula:
                T[i][j] = max(T[i - 1][j], T[i - 1][j - w[i]] + P[i]);
            } else {
                // If item weight is more than current capacity j
                T[i][j] = T[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit: " << T[n][m] << endl;

    return 0;
}