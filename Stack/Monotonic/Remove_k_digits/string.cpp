// Logic beats 75% for this approach on LeetCode
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k >= n) return "0";

        string stack = "";

        for (char c : num) {
            while (k > 0 && !stack.empty() && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }

        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        int start = 0;
        while (start < stack.size() && stack[start] == '0') {
            start++;
        }

        string result = stack.substr(start);
        return result == "" ? "0" : result;
    }
};