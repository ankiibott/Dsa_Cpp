#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

// Define the maximum number of vertices
#define V 10 

void dijkstra(int cost[V][V], int n, int s) {
    // d[i] will hold the shortest distance from source s to i
    int d[V]; 
    // selected[i] will be true if vertex i is included in shortest path tree
    bool selected[V]; 

    // 1. Initialization (Matches your lines 1-5)
    for (int i = 1; i <= n; i++) {
        selected[i] = false;
        d[i] = cost[s][i];
    }

    d[s] = 0;
    selected[s] = true;

    // 2. Main Loop (Matches your 'k' loop)
    // We need to find n-1 more vertices
    for (int k = 1; k < n; k++) {
        int min_dist = INT_MAX;
        int u = -1;

        // Find the unselected vertex with the minimum distance
        for (int i = 1; i <= n; i++) {
            if (!selected[i] && d[i] < min_dist) {
                min_dist = d[i];
                u = i;
            }
        }

        // Mark the picked vertex as processed
        if (u != -1) {
            selected[u] = true;

            // 3. Relaxation Step (Matches your 'v' loop)
            // Update d[v] only if it's not selected and there is a shorter path through u
            for (int v = 1; v <= n; v++) {
                if (!selected[v] && cost[u][v] != INT_MAX) {
                    if (d[u] + cost[u][v] < d[v]) {
                        d[v] = d[u] + cost[u][v];
                    }
                }
            }
        }
    }

    // Print the results
    cout << "Vertex \t Distance from Source " << s << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " \t\t " << (d[i] == INT_MAX ? -1 : d[i]) << endl;
    }
}

int main() {
    int n = 3; // Number of vertices based on your drawing
    int s = 1; // Starting source vertex
    
    // Initialize cost matrix with a large value (infinity)
    int cost[V][V];
    for(int i=0; i<V; i++) 
        for(int j=0; j<V; j++) 
            cost[i][j] = (i == j) ? 0 : INT_MAX;

    // Adding edges from your drawing:
    // 1 -> 2 cost 1
    // 1 -> 3 cost 5
    // 2 -> 3 cost 3
    cost[1][2] = 1; cost[2][1] = 1;
    cost[1][3] = 5; cost[3][1] = 5;
    cost[2][3] = 3; cost[3][2] = 3;

    dijkstra(cost, n, s);

    return 0;
}