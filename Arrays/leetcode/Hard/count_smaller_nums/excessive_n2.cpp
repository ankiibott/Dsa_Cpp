//ps:-315:-Count of Smaller Numbers After Self


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        recur(0, nums, result);
        return result;
    }

    void recur(int k, vector<int>& nums, vector<int>& result) {
        if (k == nums.size()) {
            return;
        }

        int count = 0;
        for (int i = k + 1; i < nums.size(); i++) {
            if (nums[i] < nums[k]) {
                count++;
            }
        }
        result.push_back(count);
        recur(k + 1, nums, result);
    }
};