//logic:- if without multiplication or with multiplication , find max , it can be either in maxsofar or minsofar 
//note:- but as a result we store obv the maxsofar as it we need longest product array
//ps:-152:- Maximum product sum

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            if (curr < 0) {
                swap(maxSoFar, minSoFar);
            }
            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);

            result = max(result, maxSoFar);
        }
        return result;
    }
};