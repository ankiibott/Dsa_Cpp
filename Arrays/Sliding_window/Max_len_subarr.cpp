class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxlen = 0;
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    int currmax = 0;
                    int temp_i = i;
                    int temp_j = j;
                    
                    while (temp_i < n && temp_j < m && nums1[temp_i] == nums2[temp_j]) {
                        currmax++;
                        temp_i++;
                        temp_j++;
                    }
                    maxlen = std::max(maxlen, currmax);
                }
            }
        }
        return maxlen;
    }
};