//566. Reshape the Matrix
//logic: flatten the original matrix into a list and then fill the reshaped matrix row by row

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (r * c != m * n) return mat;
        
        list<int> elt;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                elt.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int>> result(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result[i][j] = elt.front();
                elt.pop_front();
            }
        }
        
        return result;
    }
};