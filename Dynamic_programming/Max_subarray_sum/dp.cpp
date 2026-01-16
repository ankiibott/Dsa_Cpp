#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int dpsum(int A[], int n) {
    int S[n];
    S[0] = A[0];

    for (int i = 1; i < n; i++) {
        if (S[i - 1] < 0) {
            S[i] = A[i];
        } else {
            S[i] = S[i - 1] + A[i];
        }
    }

    int max = S[0];
    for (int i = 1; i < n; i++) {
        if (S[i] > max) {
            max = S[i];
        }
    }

    return max;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << dpsum(arr, n) << endl;
    
    return 0;
}