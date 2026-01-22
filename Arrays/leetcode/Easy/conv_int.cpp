
//ps:-1317. Convert Integer to the Sum of Two No-Zero Integers
//logic :- checks %10 if x%10==0 then true rest false 

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {};
    }

    bool hasZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }
};