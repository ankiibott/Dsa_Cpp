class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        //the first element in a array;
        int k = 1; 
        /*earlier I did i+1 and i as in if condition but the prblm with that is 
        at n-1 the i+1 goes out of the array , so therefore i-1*/
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
};