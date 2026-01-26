//logic:- if reaches n then means found , the reason of 
// not using for loop is because we wont get the starting index of haystach

//ps:-28. Find the Index of the First Occurrence in a String

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        if (n > m) return -1;

        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};