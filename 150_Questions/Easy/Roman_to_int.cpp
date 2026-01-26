class Solution {
public:
    int romanToInt(string s) {
        int roman[128] = {};
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int totalnum = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 == s.length() || roman[s[i]] >= roman[s[i + 1]]) {
                totalnum += roman[s[i]];
            } else {
                totalnum -= roman[s[i]];
            }
        }

        return totalnum;
    }
};