#include <iostream>
#include <climits>

using namespace std;

// Defining a large value for infinity
#define INF INT_MAX

void findMST(int n, int cost[10][10]) {
    // Arrays from your notes
    int near[n + 1];
    bool selected[n + 1];
    
    // Initialize
    for (int i = 0; i <= n; i++) {
        selected[i] = false;
        near[i] = INF; 
    }

    int minCost = 0;
    
    // Starting with node 1 (as seen in your 'u=1' note)
    int u = 1;
    selected[u] = true;

    // Initializing the 'near' array based on the starting node
    for (int i = 1; i <= n; i++) {
        if (!selected[i]) {
            near[i] = u;
        }
    }

    // Your main loop: runs n-1 times to find n-1 edges
    for (int i = 1; i < n; i++) {
        int min = INF;
        int v = -1;

        // Finding the vertex 'j' that is not selected and has the minimum cost edge
        for (int j = 1; j <= n-2; j++) { // the reason it termate upto n-2 is because the first is already taken , as total edge shud be n-1 so therefore 1 already used then n-2
            if (!selected[j] && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                v = j;
            }
        }

        // Update total cost and mark vertex as selected
        if (v != -1) {
            u = near[v]; // The other end of the min edge
            cout << "Edge found: " << u << " -> " << v << " Cost: " << min << endl;
            minCost += min;
            selected[v] = true;

            // Update 'near' array: Check if other nodes are closer to the newly added vertex 'v'
            for (int k = 1; k <= n; k++) {
                if (!selected[k] && cost[k][v] < cost[k][near[k]]) {
                    near[k] = v;
                }
            }
        }
    }

    cout << "\nTotal Minimum Cost: " << minCost << endl;
}

int main() {
    int n = 7; // Number of nodes as seen in your graph (1 to 7)
    
    // Initialize cost matrix with INF
    int cost[10][10];
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cost[i][j] = (i == j) ? 0 : INF;

    // Example edges based on your drawing
    cost[1][6] = cost[6][1] = 10;
    cost[6][5] = cost[5][6] = 25;
    cost[5][4] = cost[4][5] = 22;
    // ... add other edges here ...

    findMST(n, cost);

    return 0;
}