class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int n = nums.size();
        
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                h = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        if (result[0] == -1) return result;

        l = 0; h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                result[1] = mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return result;
    }
};