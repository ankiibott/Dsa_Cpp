//logic:- not an optimal way of solving  it O(n^3)
//ps:-5. Longest Palindromic Substring
class Solution {
public:
    bool palindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int maxlength = 0;
        string result = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (palindrome(s, i, j) == true) {
                    int currlength = j - i + 1;
                    
                    if (currlength > maxlength) {
                        maxlength = currlength;
                        result = s.substr(i, currlength);
                    }
                }
            }
        }
        return result;
    }
};