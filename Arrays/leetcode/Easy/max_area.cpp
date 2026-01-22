/*logic :- 
take maxdiag and currdiag similar with area as well :-
now if currdiag>maxdiag then obv change max to curr
if not or is equal then check for area and then update area 
*/

//ps:-3000. Maximum Area of Longest Diagonal Rectangle

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