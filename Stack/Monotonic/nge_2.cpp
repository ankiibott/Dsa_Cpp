// Logic: Use a monotonic stack to find the next greater 
// element for a circular array by simulating doubling the array
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> result(n, -1);
        // Loop 2*n times to simulate a circular array (as 
        // if the array was appended to itself)
        for (int i = 0; i < 2 * n; i++) {
            // i % n maps the abstract index (0 to 2n-1) 
            // back to the original array bounds (0 to n-1)
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