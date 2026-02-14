class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
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
        int totalSize = even.size() + odd.size();
        
        for(int i = 0; i < totalSize; i++){ 
            if(i % 2 == 0){
                nums.push_back(even[i / 2]);
            } else {
                nums.push_back(odd[i / 2]);
            }
        }
        return nums;
    }
};