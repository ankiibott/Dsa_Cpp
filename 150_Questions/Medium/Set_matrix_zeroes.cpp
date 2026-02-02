class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> temp = matrix;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(temp[i][j] == 0){
                    matrixUpdate(matrix, i, j);
                }
            }
        }
    }

    void matrixUpdate(vector<vector<int>>& matrix, int row, int col){
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            matrix[i][col] = 0;
        }
        
        for(int i = 0; i < n; i++){
            matrix[row][i] = 0;
        }
    }
};