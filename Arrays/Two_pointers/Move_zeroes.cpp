//ps:-283. Move Zeroes
//logic:- if 0 at prev then swap in rest cases just move prev++ and curr++ and in else case 
// 0 val at both pointer then simply move curr++ until targets a int other than zero.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prev = 0;
        int curr = 0;

        while (curr < nums.size()) {
            if (nums[prev] == 0 && nums[curr] != 0) {
                std::swap(nums[prev], nums[curr]);
                prev++;
                curr++;
            } 
            else if (nums[prev] != 0 && nums[curr] != 0) {
                prev++;
                curr++;
            } 
            else if (nums[prev] != 0 && nums[curr] == 0) {
                prev++;
                curr++;
            } 
            else {
                curr++;
            }
        }
    }
};