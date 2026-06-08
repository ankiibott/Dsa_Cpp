// Count the number of 1 bits in n by checking each least-significant 
// bit and shifting right.
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        while (n > 0) {
            if (n % 2 == 1) {
                count++;
            }
            n = n / 2;
        }
        
        return count;
    }
};