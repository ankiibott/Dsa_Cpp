// Logic beats 29% for this approach on LeetCode
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k >= n) return "0";

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (k > 0 && !st.empty() && num[i] < num[st.top()]) {
                st.pop();
                k--;
            }
            st.push(i);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string temp = "";
        while (!st.empty()) {
            temp += num[st.top()];
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        int start = 0;
        while (start < temp.size() && temp[start] == '0') {
            start++;
        }

        string result = temp.substr(start);
        return result == "" ? "0" : result;
    }
};