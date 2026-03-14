

// Uses prefix sum to find the relative min 
// and max of the sequence to determine how 
// many times its total range fits within the [lower, upper] bounds.
//ps:-2145. Count the Hidden Sequences
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + differences[i];
        }

        long long max_val = prefix[0];
        long long min_val = prefix[0];

        for (int i = 0; i <= n; i++) {
            max_val = max(max_val, prefix[i]);
            min_val = min(min_val, prefix[i]);
        }

        long long sequence_height = max_val - min_val;
        long long box_height = (long long)upper - lower;

        if (sequence_height > box_height) {
            return 0;
        }

        return (int)(box_height - sequence_height + 1);
    }
};