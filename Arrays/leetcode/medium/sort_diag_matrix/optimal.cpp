/*(O(N^2 \log N)): The standard optimal approach is 
to extract each diagonal into a list, sort the list, and put it back.*/


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for (int i = 0; i < n; i++) {
            sortDiagonal(grid, i, 0, false);
        }

        for (int j = 1; j < n; j++) {
            sortDiagonal(grid, 0, j, true);
        }

        return grid;
    }

    void sortDiagonal(vector<vector<int>>& grid, int row, int col, bool ascending) {
        int n = grid.size();
        vector<int> diagValues;
        
        int i = row, j = col;
        while (i < n && j < n) {
            diagValues.push_back(grid[i][j]);
            i++;
            j++;
        }

        if (ascending) {
            sort(diagValues.begin(), diagValues.end());
        } else {
            sort(diagValues.rbegin(), diagValues.rend());
        }

        i = row;
        j = col;
        int k = 0;
        while (i < n && j < n) {
            grid[i][j] = diagValues[k++];
            i++;
            j++;
        }
    }
};