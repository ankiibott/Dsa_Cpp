//logic :- perfrom binary search 
//constraint:-O(logn)
//ps-74


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            int l = 0;
            int h = n - 1;
            
            while (l <= h) {
                int mid = l + (h - l) / 2;
                
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return false;
    }
};