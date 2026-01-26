//logic :- we inc if same else dec 
// if at any point count==0 then false 
//ps:-383. Ransom Note 


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counts;
        
        for (char c : magazine) {
            counts[c]++;
        }
        
        for (char c : ransomNote) {
            if (counts[c] == 0) {
                return false;
            }
            counts[c]--;
        }
        
        return true;
    }
};