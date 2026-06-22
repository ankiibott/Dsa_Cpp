// logic:- Sort both strings and compare from the end to find 
// the extra character in t.
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        stack<char> st;
        for (int i = 0; i < t.length(); i++) {
            st.push(t[i]);
        }
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == st.top()) {
                st.pop();
            } else {
                return st.top();
            }
        }
        
        return st.top();
    }
};