class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;
        vector<int> ans;

        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = m-1;
        int count=0;

        while(count<total){
            
            for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
                count+=1;
            }
            rowStart+=1;
            if(count==total)break;
            
            for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
                count+=1;
            }
            colEnd-=1;
            if(count==total)break;

            for(int i=colEnd;i>=colStart;i--){
                ans.push_back(matrix[rowEnd][i]);
                count+=1;
            }
            rowEnd-=1;
            if(count==total)break;
            
            for(int i=rowEnd;i<=rowStart;i--){
                ans.push_back(matrix[i][colStart]);
                count+=1;
            }
            colStart+=1;
            if(count==total)break;
    
        }
        return ans;
    }
};