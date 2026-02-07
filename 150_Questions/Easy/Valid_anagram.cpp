//logic:- store s first , then check for every t if present then true else false;
//ps:-242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> count;
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
        }
        
        for (int i = 0; i < t.length(); i++) {
            if (count.find(t[i]) == count.end() || count[t[i]] == 0) {
                return false;
            }
            count[t[i]]--;
        }
        
        return true;
    }
};