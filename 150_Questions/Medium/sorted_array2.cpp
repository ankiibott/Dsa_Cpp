//logic:- not an optimal obv but still if same then count++ else reset count to 1 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 1;
        int count = 1;
        int k = 1;

        while(i < nums.size()){
            if(nums[i] == nums[i-1]){
                count++;
            } else {
                count = 1;
            }

            if(count <= 2){
                nums[k] = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};