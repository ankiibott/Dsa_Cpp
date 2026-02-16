//logic:- nested loops o(n^3)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long closestSum = INT_MAX / 2; 

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int currentSum = nums[i] + nums[j] + nums[k];
                    if (abs(target - currentSum) < abs(target - closestSum)) {
                        closestSum = currentSum;
                    }
                }
            }
        }
        return (int)closestSum;
    }
};