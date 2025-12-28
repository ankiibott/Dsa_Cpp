#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent the Disjoint Set (Subset ds)
struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n + 1, -1); // Initialize parent with -1
    }

    // Find operation (using basic recursion)
    int find(int i) {
        if (parent[i] < 0)
            return i;
        return find(parent[i]); 
    }

    // Union operation
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void kruskals(int n, int edge_data[][3], int numEdges) {
    bool selected[10] = {false}; // Array to track used edges
    int minCost = 0, edgeCount = 0;
    DisjointSet ds(n);

    cout << "Edges in MST:" << endl;

    // while(edgeCount < n - 1) as seen in your photo
    while (edgeCount < n - 1) {
        int min = INT_MAX;
        int index = -1;

        // Finding the minimum cost edge that hasn't been selected
        for (int i = 0; i < numEdges; i++) {
            if (selected[i] == false && edge_data[i][2] < min) {
                min = edge_data[i][2];
                index = i;
            }
        }

        if (index != -1) {
            int u = edge_data[index][0];
            int v = edge_data[index][1];

            // if(ds.Find(u) != ds.Find(v)) - Cycle Check
            if (ds.find(u) != ds.find(v)) {
                cout << u << " -- " << v << " == " << min << endl;
                minCost += min;
                selected[index] = true;
                edgeCount++;
                ds.unite(u, v);
            } else {
                // Mark as selected even if it forms a cycle so we don't check it again
                selected[index] = true; 
            }
        }
    }
    cout << "Total Minimum Cost: " << minCost << endl;
}

int main() {
    int n = 7;
    // Data from your handwritten table: {u, v, cost}
    int edges[9][3] = {
        {1, 2, 28}, {1, 6, 10}, {2, 3, 16},
        {2, 7, 14}, {3, 4, 12}, {4, 5, 22},
        {4, 7, 18}, {5, 6, 25}, {5, 7, 24}
    };

    kruskals(n, edges, 9);

    return 0;
}