#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to make handling objects easier than a 2D array
struct Item {
    double profit;
    double weight;
    double ratio;
};

// Custom sorting function to sort by ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double knapsack(int n, int m, double profits[], double weights[]) {
    vector<Item> items(n);

    // 1. Initialize objects and calculate profit/weight ratio
    for (int i = 0; i < n; i++) {
        items[i].profit = profits[i];
        items[i].weight = weights[i];
        items[i].ratio = profits[i] / weights[i];
    }

    // 2. Sort(obj, n) as per your notes
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int currentCapacity = m;

    // 3. Main Loop: for(int i=0; i<n; i++)
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= currentCapacity) {
            // Take the whole item
            totalProfit += items[i].profit;
            currentCapacity -= items[i].weight;
        } else {
            // Take the fraction (Greedy Choice)
            // profit = profit + obj[0][i] * (m / obj[1][i])
            totalProfit += items[i].profit * ((double)currentCapacity / items[i].weight);
            break; // Knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    int n = 3; // Number of items
    int m = 50; // Max capacity

    double profits[] = {60, 100, 120};
    double weights[] = {10, 20, 30};

    double maxProfit = knapsack(n, m, profits, weights);

    cout << "Maximum Profit in Knapsack: " << maxProfit << endl;

    return 0;
}