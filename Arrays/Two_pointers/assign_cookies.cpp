
//ps:-455. Assign Cookies
// Use two pointers to greedily 
// match the smallest sufficient cookie to the least greedy child
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                count++;
                i++;
                j++;
            }
            else if(g[i]>s[j]) j++;
        }
        return count;
    }
};