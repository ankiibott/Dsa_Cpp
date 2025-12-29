#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Globally defining arrays for simplicity, matching your handwritten logic
int w[] = {0, 2, 3, 4}; // Weights (0-index is a dummy)
int p[] = {0, 1, 2, 5}; // Profits (0-index is a dummy)

// Your handwritten logic converted to C++
int knap(int n, int m) {
    // Base Case: No items left or capacity is 0
    if (n == 0 || m == 0) {
        return 0;
    }

    // If weight of current item is less than or equal to capacity
    if (w[n] <= m) {
        // Option 1: Don't include the item
        int no = knap(n - 1, m);
        
        // Option 2: Include the item
        int yes = knap(n - 1, m - w[n]) + p[n];

        // Return the maximum of the two
        return (no > yes) ? no : yes;
    } 
    else {
        // Weight is too much, cannot include item
        return knap(n - 1, m);
    }
}

int main() {
    int items = 3;    // Total number of items
    int capacity = 6; // Total capacity (m)

    cout << "Maximum Profit: " << knap(items, capacity) << endl;

    return 0;
}