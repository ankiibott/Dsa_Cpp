//ps:- 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + k && j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {IN
                    return true;
                }
            }
        }
        return false;
    }
};