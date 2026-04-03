class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int indexToUpdate = st.top();
                st.pop();
                
                int count = i - indexToUpdate; 
                result[indexToUpdate] = count;
            }
            st.push(i);
        }
        return result;
    }
};