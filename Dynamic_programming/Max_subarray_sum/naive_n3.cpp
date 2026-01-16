#include <iostream>
#include <climits> // For INT_MIN
#include <vector>

using namespace std;

// Function based on your pseudocode
int maxSub(int A[], int n) {
    int maxSum = INT_MIN; // Equivalent to MIN_INT in your notes
    int start = 0, end = 0;

    // Loop i: Picks the starting point of the subarray
    for (int i = 0; i < n; i++) {
        // Loop j: Picks the ending point of the subarray
        for (int j = i; j < n; j++) {
            int sum = 0;
            
            // Loop k: Calculates the sum of the subarray from A[i] to A[j]
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }

            // Update maxSum if the current subarray sum is greater
            if (sum > maxSum) {
                maxSum = sum;
                start = i; // Tracking the indices (optional)
                end = j;
            }
        }
    }
    
    // Printing indices for your reference
    cout << "Subarray found between indices " << start << " and " << end << endl;
    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxSub(arr, n);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}