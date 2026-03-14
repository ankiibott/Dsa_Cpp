class NumArray {
private:
    vector<int> prefix;
public:
    //initialisation
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        
        int n = nums.size();
        prefix.resize(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};