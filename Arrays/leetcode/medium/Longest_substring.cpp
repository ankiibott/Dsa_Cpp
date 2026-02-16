class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            int currentLength = 0;

            for (int j = i; j < n; j++) {
                if (seen.find(s[j]) != seen.end()) {
                    break;
                }
                seen.insert(s[j]);
                currentLength++;
            }
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};