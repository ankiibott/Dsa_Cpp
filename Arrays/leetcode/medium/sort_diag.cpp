class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n - 1; i++) {
                for(int j = 0; j < n - 1; j++) {
                    if(i >= j){
                        non_inc(grid, i, j);
                    } else {
                        non_dec(grid, i, j);
                    }
                }
            }
        }
        return grid;
    }

    void non_inc(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] < grid[i + 1][j + 1]){
            swap(grid[i][j], grid[i + 1][j + 1]);
        }
    }

    void non_dec(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] > grid[i + 1][j + 1]){
            swap(grid[i][j], grid[i + 1][j + 1]);
        }
    }
};