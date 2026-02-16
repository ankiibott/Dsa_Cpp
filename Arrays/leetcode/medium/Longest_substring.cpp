// The unordered_set stores every unique character 
// encountered in the current substring to provide a memory of 
// what has been seen.
// The if condition checks if the current character
//  already exists in the set to immediately stop the loop upon finding a duplicate.
//seen.end() means null.

//ps:-3.Longest Substring Without Repeating Characters

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