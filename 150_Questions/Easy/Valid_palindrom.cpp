//logic:-Sanitize the string first using isalnum() to ignore 
// noise, then use two pointers (start and end) to compare characters inward
//ps:-125. Valid Palindrome


class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                check += tolower(s[i]);
            }
        }
        
        int i = 0;
        int j = check.size() - 1;
        
        while (i < j) {
            if (check[i] != check[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};