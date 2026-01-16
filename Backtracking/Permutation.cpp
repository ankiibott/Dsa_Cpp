#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Global or shared variables based on your pseudocode
string Str;          // The input string to permute
char Res[20];        // Array to store the current permutation result
bool sel[20];        // Boolean array to track selected elements
int n;               // Length of the string

void Perm(int k) {
    // Base Case: If we have filled all positions (k == n)
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << Res[i];
        }
        cout << endl;
    } else {
        // Recursive Step: Try every character in the string for the current position k
        for (int i = 0; i < n; i++) {
            // Check if character at index i is already used
            if (sel[i] == false) {
                Res[k] = Str[i]; // Place the character in result array
                sel[i] = true;   // Mark it as selected
                
                Perm(k + 1);     // Recursively move to the next position
                
                // BACKTRACKING: Unmark the character so it can be used 
                // in different positions for other permutations
                sel[i] = false; 
            }
        }
    }
}

int main() {
    cout << "Enter a string to permute: ";
    cin >> Str;
    
    n = Str.length();
    
    // Initialize the selection array to false
    for (int i = 0; i < n; i++) {
        sel[i] = false;
    }

    cout << "All possible permutations:" << endl;
    Perm(0); // Start the recursion from index 0

    return 0;
}