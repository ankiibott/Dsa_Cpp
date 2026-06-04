// logic :- 
// find the pivot where left sum equals right sum, with
//  right sum computed as total_sum - left_sum - nums[i]

//724. Find Pivot Index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int left_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            left_sum += nums[i];
        }

        return -1;
    }
};