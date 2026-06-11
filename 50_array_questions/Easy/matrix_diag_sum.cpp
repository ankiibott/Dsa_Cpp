class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int total_sum = 0;
        
        int i = 0;
        while (i < n) {
            total_sum += mat[i][i];
            total_sum += mat[i][n - 1 - i];
            i++;
        }
        
        if (n % 2 == 0) {
            return total_sum;
        } else {
            return total_sum - mat[n / 2][n / 2];
        }
    }
};