#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// The dimensions array 'd'
// If we have matrices A(10x30), B(30x5), C(5x60), 
// then d = {10, 30, 5, 60}
int d[] = {10, 30, 5, 60}; 

int m(int i, int j) {
    // Base case: If there is only one matrix, the cost is 0
    if (i == j) {
        return 0;
    }

    int mincost = INT_MAX;

    // Try every possible split point 'k' between i and j
    for (int k = i; k < j; k++) {
        // Recursive formula from your notes:
        // cost = m(i, k) + m(k+1, j) + d[i-1] * d[k] * d[j]
        int current_cost = m(i, k) + m(k + 1, j) + (d[i - 1] * d[k] * d[j]);

        if (current_cost < mincost) {
            mincost = current_cost;
        }
    }

    return mincost;
}

int main() {
    // For 3 matrices (A, B, C), the range is from index 1 to 3
    int n = sizeof(d) / sizeof(d[0]) - 1;
    
    cout << "Minimum cost of multiplication is: " << m(1, n) << endl;

    return 0;
}