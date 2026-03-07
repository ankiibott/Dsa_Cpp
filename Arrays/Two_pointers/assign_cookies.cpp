class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factors of children and sizes of cookies in ascending order
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        
        int i=0; // Pointer for children (greed factor)
        int j=0; // Pointer for cookies (size)
        int count=0; // Number of satisfied children
        
        // Iterate with two pointers as long as there are children and cookies left to check
        while(i<g.size() && j<s.size()){
            // If the current cookie size is sufficient to satisfy the current child's greed
            if(g[i]<=s[j]){
                count++; // The child is satisfied
                i++; // Move to the next child
                j++; // Move to the next cookie
            }
            // If the cookie is too small, try the next larger cookie for the same child
            else if(g[i]>s[j]) j++;
        }
        return count;
    }
};