//Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        vector<int> range;
        int n = nums.size();
        
        for (int i = 1; i <= n; i++) {
            range.push_back(i);
        }
        
        std::sort(nums.begin(), nums.end());
        
        int i = 0; 
        int j = 0; 
        
        while (i < range.size() && j < nums.size()) {
            
            if (range[i] == nums[j]) {
                i++;
                j++;
                
            } else if (range[i] < nums[j]) {
                result.push_back(range[i]);
                i++;
                
            } else { 
                j++;
            }
        }
        
        while (i < range.size()) {
            result.push_back(range[i]);
            i++;
        }
        
        return result;
    }
};