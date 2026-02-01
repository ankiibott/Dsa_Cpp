class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = "";
        int j = 0;

        while (j < strs[0].size()) {
            char c = strs[0][j];
            int i = 1;
            
            while (i < strs.size()) {
                if (j >= strs[i].size() || strs[i][j] != c) {
                    return prefix;
                }
                i++;
            }
            
            prefix += c;
            j++;
        }
        
        return prefix;
    }
};