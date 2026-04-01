class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            int currentIdx = i % n;
            
            while (!st.empty() && nums[currentIdx] > nums[st.top()]) {
                result[st.top()] = nums[currentIdx];
                st.pop();
            }
            
            if (i < n) {
                st.push(i);
            }
        }
        
        return result;
    }
};