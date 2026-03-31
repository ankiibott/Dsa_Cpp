class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices; 
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int index = st.top();
                st.pop();
                result[index] = prices[index] - prices[i];
            }
            st.push(i);
        }

        return result;
    }
};