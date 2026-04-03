class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int x : arr) {
            if (st.empty() || x > st.top()) {
                st.push(x);
            } else {
                int current_max = st.top();
                while (!st.empty() && x < st.top()) {
                    st.pop();
                }
                st.push(current_max);
            }
        }
        return st.size();
    }
};