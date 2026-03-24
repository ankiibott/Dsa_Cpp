// Repeatedly iterates backward and removes elements
//  strictly less than their immediate left neighbor until 
// the array becomes entirely non-decreasing.
//ps:-2258. Escape the Spreading Fire
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int rounds = 0;
        while (!non_dec(nums)) {
            rounds++;
            for (int i = nums.size() - 1; i > 0; i--) {
                if (nums[i - 1] > nums[i]) {
                    nums.erase(nums.begin() + i);
                }
            }
        }
        return rounds;
    }

    bool non_dec(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
};