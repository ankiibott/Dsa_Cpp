//logic:- first while loop if spaces are there last also if not then move 
//till theres no spaces(2nd while loop)
//example:-s = "   fly me   to   the moon  "


//ps:-58. Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};