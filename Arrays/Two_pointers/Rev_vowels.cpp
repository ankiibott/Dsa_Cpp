// Logic: Uses a two-pointer approach (start and end) 
// to find and swap vowels from both ends of the string until the pointers meet.
//ps:-345. Reverse Vowels of a String

class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;
        unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

        while (start < end) {
            if (vowels.find(s[start]) == vowels.end()) {
                start++;
            } 
            else if (vowels.find(s[end]) == vowels.end()) {
                end--;
            } 
            else {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};