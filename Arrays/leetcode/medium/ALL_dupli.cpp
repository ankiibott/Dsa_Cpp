//ps:-442. Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty()) return {};
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                result.push_back(nums[i]);
                i++; 
            }
        }
        
        return result;
    }
};