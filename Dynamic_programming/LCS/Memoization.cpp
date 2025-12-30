#include <iostream>
#include <string>
#include <algorithm> // For max()
#include <cstring>   // For memset

using namespace std;

// Global strings and memoization table based on your notes
string A = "-ace";
string B = "-abcde";
int L[100][100];

int LCS(int i, int j) {
    // 1. Base Case: If i or j is 0, length is 0
    if (i == 0 || j == 0) {
        L[i][j] = 0;
        return 0;
    }

    // 2. Check if the value is already in the memo table
    if (L[i][j] != -1) {
        return L[i][j];
    }

    // 3. Recursive logic with storage
    if (A[i] == B[j]) {
        // If characters match, add 1 and store in table
        L[i][j] = 1 + LCS(i - 1, j - 1);
    } 
    else {
        // If mismatch, take the max of the two options and store
        L[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));
    }

    return L[i][j];
}

int main() {
    int n = A.length() - 1;
    int m = B.length() - 1;

    // Initialize the memoization table with -1
    memset(L, -1, sizeof(L));

    cout << "Length of LCS (Memoized): " << LCS(n, m) << endl;

    return 0;
}