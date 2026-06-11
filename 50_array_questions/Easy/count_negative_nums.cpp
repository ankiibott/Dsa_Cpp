// Two-pointer approach: start from top-right,
//  move left if negative (all below are negative too), else move down

//ps:- 1351. Count Negative Numbers in a Sorted Matrix
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = n - 1;
        int count = 0;
        
        while (i < m && j >= 0) {
            if (grid[i][j] < 0) {
                count += (m - i);
                j--;
            } else {
                i++;
            }
        }
        
        return count;
    }
};