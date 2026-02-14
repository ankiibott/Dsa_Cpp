//logic:- even and odd separate and then nums.clear() and then push_back
//ps:-905. Sort Array By Parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i = 0; i < even.size(); i++){
            nums.push_back(even[i]);
        }
        for(int i = 0; i < odd.size(); i++){
            nums.push_back(odd[i]);
        }
        return nums;
    }
};