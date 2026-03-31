// Uses a monotonic stack to precompute the next greater 
// element for nums2, then maps it for nums1.
//ps:-496. Next Greater Element 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> nge(n2, -1);
        stack<int> st;

        for (int i = 0; i < n2; i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                int index = st.top();
                st.pop();
                nge[index] = nums2[i];
            }
            st.push(i);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }

        return ans;
    }
};