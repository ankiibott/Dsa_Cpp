#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global arrays based on your notes
int w[] = {0, 1, 2, 1, 2}; // Weights (from your image)
int p[] = {0, 10, 20, 30, 40}; // Example Profits
int T[100][100]; // DP Table (Memoization table)

int knap(int n, int m) {
    // 1. Base Case: If no items left or capacity is 0
    if (n == 0 || m == 0) {
        T[n][m] = 0;
        return 0;
    }

    // 2. Check if the value is already calculated (Memoization)
    if (T[n][m] != -1) {
        return T[n][m];
    }

    // 3. Choice Diagram Logic
    if (w[n] <= m) {
        int no = knap(n - 1, m);
        int yes = knap(n - 1, m - w[n]) + p[n];
        
        // Store and return the result
        T[n][m] = (no > yes) ? no : yes;
    } else {
        // If weight of current item > capacity, exclude it
        T[n][m] = knap(n - 1, m);
    }

    return T[n][m];
}

int main() {
    int items = 4;    // As shown in your 'w' array (indices 1 to 4)
    int capacity = 6;

    // Initialize the table with -1
    for (int i = 0; i <= items; i++) {
        for (int j = 0; j <= capacity; j++) {
            T[i][j] = -1;
        }
    }

    cout << "Maximum Profit: " << knap(items, capacity) << endl;

    return 0;
}