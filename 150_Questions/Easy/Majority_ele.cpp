//logic :- not an optimal soln but , it 
// is said that majority ele lies at the middle of sorted array
//ps:-169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        sort(nums.begin(), nums.end());
        int k = n / 2;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > k) {
                return nums[i];
            }
        }
        return -1;
    }
};