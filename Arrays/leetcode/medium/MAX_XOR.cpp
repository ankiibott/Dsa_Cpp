//ps:-421. Maximum XOR of Two Numbers in an Array

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int high = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int currentVal = nums[i] ^ nums[j];
                if(currentVal > high) {
                    high = currentVal;
                }
            }
        }
        return high;
    }
};