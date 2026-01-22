class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiagSq = 0;
        int maxArea = 0;
        
        for (int i = 0; i < dimensions.size(); i++) {
            long long currentDiagSq = (long long)dimensions[i][0] * dimensions[i][0] + (long long)dimensions[i][1] * dimensions[i][1];
            int currentArea = dimensions[i][0] * dimensions[i][1];
            
            if (currentDiagSq > maxDiagSq) {
                maxDiagSq = currentDiagSq;
                maxArea = currentArea;
            } else if (currentDiagSq == maxDiagSq) {
                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }
            }
        }
        
        return maxArea;
    }
};