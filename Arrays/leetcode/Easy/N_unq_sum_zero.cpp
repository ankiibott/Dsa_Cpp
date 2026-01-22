//ps:- 1304. Find N Unique Integers Sum up to Zero
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int i = 0;
        int j = n - 1;
        int val = 1;
        
        while (i < j) {
            result[i] = val;
            result[j] = -val;
            i++;
            j--;
            val++;
        }
        
        return result;
    }
};