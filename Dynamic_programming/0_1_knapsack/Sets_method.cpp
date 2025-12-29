#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int w, v;
};

// Function to solve Knapsack using Sets Method
void solveKnapsack(int n, int W, vector<int>& weights, vector<int>& values) {
    // S stores pairs of (weight, value)
    vector<Pair> S = {{0, 0}};

    for (int i = 0; i < n; i++) {
        vector<Pair> nextS;
        int weight_i = weights[i];
        int value_i = values[i];

        // 1. Create S' by adding current item to all pairs in S
        vector<Pair> S_prime;
        for (auto p : S) {
            if (p.w + weight_i <= W) {
                S_prime.push_back({p.w + weight_i, p.v + value_i});
            }
        }

        // 2. Merge S and S_prime (keeping it sorted by weight)
        int i_s = 0, i_sp = 0;
        while (i_s < S.size() || i_sp < S_prime.size()) {
            Pair candidate;
            if (i_s < S.size() && (i_sp == S_prime.size() || S[i_s].w < S_prime[i_sp].w)) {
                candidate = S[i_s++];
            } else {
                candidate = S_prime[i_sp++];
            }

            // 3. Purging (Dominance Rule)
            // Only add if this candidate provides more value than the last added pair
            if (nextS.empty() || (candidate.v > nextS.back().v)) {
                // If weights are equal, the candidate with higher value replaces the last
                if (!nextS.empty() && nextS.back().w == candidate.w) {
                    nextS.back().v = max(nextS.back().v, candidate.v);
                } else {
                    nextS.push_back(candidate);
                }
            }
        }
        S = nextS;
    }

    // The last pair in the sorted set will have the maximum value
    cout << "Maximum Value in Knapsack: " << S.back().v << endl;
}

int main() {
    int n = 3; // Number of items
    int W = 6; // Max Capacity
    vector<int> values = {1, 2, 5};
    vector<int> weights = {2, 3, 4};

    solveKnapsack(n, W, weights, values);

    return 0;
}