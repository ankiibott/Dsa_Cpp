//logic:- sort the string and then use it as a key in the map
//ps:-49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key: Sorted string, Value: List of original anagrams
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs) {
            string temp = s; 
            sort(temp.begin(), temp.end()); // Sorting creates the "unique key"
            mp[temp].push_back(s);          // Group the original word under that key
        }
        
        // Move grouped results from the map to the final vector
        vector<vector<string>> result;
        for (auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};