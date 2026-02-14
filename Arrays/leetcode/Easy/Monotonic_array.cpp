class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return inc(nums) || dec(nums);
    }
    bool inc(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }
    bool dec(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};