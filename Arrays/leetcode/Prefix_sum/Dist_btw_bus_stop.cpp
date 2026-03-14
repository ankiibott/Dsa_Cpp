//ps:-1184. Distance Between Bus Stops
// Computes prefix sums to find 
// the clockwise distance and subtracts 
// it from the total distance for the counter-clockwise path, 
// returning the minimum of the two.
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            swap(start, destination);
        }
        int n = distance.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + distance[i];
        }
        long long clockwise_dist = prefix[destination] - prefix[start];
        long long total_dist = prefix[n];
        long long counter_clockwise_dist = total_dist - clockwise_dist;

        return (int)min(clockwise_dist, counter_clockwise_dist);
    }
};