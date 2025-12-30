#include <iostream>
#include <string>
#include <algorithm> // For max()

using namespace std;

// Strings from your handwritten notes (using '-' for index 0)
string A = "-ace";
string B = "-abcde";

int LCS(int i, int j) {
    // 1. Base Case: If either string is exhausted, LCS length is 0
    if (i == 0 || j == 0) {
        return 0;
    }

    // 2. If characters match: Move diagonally (i-1, j-1) and add 1
    if (A[i] == B[j]) {
        return 1 + LCS(i - 1, j - 1);
    } 
    // 3. If characters don't match: Take the maximum of two possibilities
    else {
        return max(LCS(i - 1, j), LCS(i, j - 1));
    }
}

int main() {
    // Lengths of strings (excluding the '-' at index 0)
    int n = A.length() - 1;
    int m = B.length() - 1;

    cout << "Length of LCS is: " << LCS(n, m) << endl;

    return 0;
}