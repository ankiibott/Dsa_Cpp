// Check if n is a positive power of two by dividing by 2 until the value is no longer even.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; 

        while (n % 2 == 0) {
            n = n / 2;
        }

        return n == 1;
    }
};