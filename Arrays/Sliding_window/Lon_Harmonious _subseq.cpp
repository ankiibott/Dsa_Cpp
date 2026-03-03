//logic:- using hash map , if mutliple cases then max (frequency will be in consideration)
//ps:-594. Longest Harmonious Subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int x : nums) {
            counts[x]++;
        }

        int maxLen = 0;
        for (auto const& [num, freq] : counts) {
            if (counts.find(num + 1) != counts.end()) {
                int currlen = freq + counts[num + 1];
                maxLen = max(maxLen, currlen);
            }
        }

        return maxLen;
    }
};