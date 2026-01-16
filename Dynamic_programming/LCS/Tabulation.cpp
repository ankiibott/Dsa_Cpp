#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::max

using namespace std;

int LCS(string A, string B) {
    int m = A.length();
    int n = B.length();

    // Create a 2D array (table) of size (m+1) x (n+1)
    // We initialize everything to 0 to handle the base cases automatically
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Fill the table using the logic from your pseudocode
    // i and j represent the lengths of the prefixes of A and B
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match (Note: strings are 0-indexed, so we use i-1 and j-1)
            if (A[i - 1] == B[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } 
            // If characters don't match, take the maximum from the top or left cell
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // The bottom-right cell contains the length of the LCS
    return L[m][n];
}

int main() {
    // Example from your image: A = "ace", B = "abcde"
    string A = "ace";
    string B = "abcde";

    cout << "Length of LCS is: " << LCS(A, B) << endl;

    return 0;
}