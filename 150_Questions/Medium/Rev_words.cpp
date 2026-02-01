//logic :- Iterate backwards from the end of the string to identify and 
// extract each word, skipping extra 
// spaces, and append them to a result string separated by single spaces.

//ps:- 151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int i = s.length() - 1;

        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;
            
            if(i < 0) break;
            
            int right = i;
            while(i >= 0 && s[i] != ' ') i--;
            
            string word = s.substr(i + 1, right - i);
            
            if(result.length() == 0) result = word;
            else result = result + " " + word;
        }
        return result;
    }
};