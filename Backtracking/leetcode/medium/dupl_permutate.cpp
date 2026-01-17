//logic:- is same as permutations just check for the duplicates
//ps:-47:-Permutation-ii


class Solution {
public:
    void Perm(int k, vector<vector<int>>& result, vector<int>& nums, vector<int>& Res, vector<bool>& sel) {
        int n = nums.size();
        if (k == n) {
            result.push_back(Res);
        } else {
            for (int i = 0; i < n; i++) {
                if (sel[i] == false) {
                    if (i > 0 && nums[i] == nums[i - 1] && sel[i - 1] == false) continue;
                    Res[k] = nums[i];
                    sel[i] = true;
                    Perm(k + 1, result, nums, Res, sel);
                    sel[i] = false;
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> Res(n);
        vector<bool> sel(n, false);
        sort(nums.begin(), nums.end());
        Perm(0, result, nums, Res, sel);
        return result;
    }
};