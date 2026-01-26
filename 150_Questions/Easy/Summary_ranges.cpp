//logic :- i points to the start of the range and j points to the end of the range
// if i==j then only one number else range
//ps:-228. Summary Ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        int i = 0;
        
        while(i < n) {
            int j = i;
            while(j + 1 < n && nums[j + 1] == (long)nums[j] + 1) {
                j++;
            }
            if(i == j) {
                result.push_back(to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }
        return result;
    }
};