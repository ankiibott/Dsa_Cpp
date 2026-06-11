
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result;
        }

        int left = 1;
        int right = k;
        if (k < 0) {
            left = n - abs(k);
            right = n - 1;
        }

        int windowSum = 0;
        for (int i = left; i <= right; i++) {
            windowSum += code[i];
        }
        result[0] = windowSum;

        for (int i = 1; i < n; i++) {
            windowSum -= code[left % n];
            left++;
            
            right++;
            windowSum += code[right % n];
            
            result[i] = windowSum;
        }

        return result;
    }
};