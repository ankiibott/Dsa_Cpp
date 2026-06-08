// logic :- Add two binary strings from right to left, tracking carry.
// Convert char digits to ints with - '0' and convert sum bits back to char with + '0'
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0'; 
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};