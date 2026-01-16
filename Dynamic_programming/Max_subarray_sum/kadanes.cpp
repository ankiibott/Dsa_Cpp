#include <iostream>
#include <vector>

int Kadanes(int A[], int n) {
    int start = 0, end = 0, substart = 0;
    int maxSub = A[0];
    int prevSum = A[0];

    for (int i = 1; i < n; i++) {
        if (prevSum < 0) {
            prevSum = A[i];
            substart = i;
        } else {
            prevSum = prevSum + A[i];
        }

        if (prevSum > maxSub) {
            maxSub = prevSum;
            start = substart;
            end = i;
        }
    }

    return maxSub;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << Kadanes(arr, n) << std::endl;
    
    return 0;
}