#include <vector>
using namespace std;
//logic:-merge sort



class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }

        vector<int> count(n, 0);
        vector<pair<int, int>> temp(n);
        mergeSort(0, n - 1, v, count, temp);
        return count;
    }

    void mergeSort(int left, int right, vector<pair<int, int>>& v, vector<int>& count, vector<pair<int, int>>& temp) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid, v, count, temp);
        mergeSort(mid + 1, right, v, count, temp);

        merge(left, mid, right, v, count, temp);
    }

    void merge(int left, int mid, int right, vector<pair<int, int>>& v, vector<int>& count, vector<pair<int, int>>& temp) {
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (v[i].first <= v[j].first) {
                temp[k++] = v[j++];
            } else {
                count[v[i].second] += (right - j + 1);
                temp[k++] = v[i++];
            }
        }

        while (i <= mid) temp[k++] = v[i++];
        while (j <= right) temp[k++] = v[j++];

        for (int i = left; i <= right; i++) {
            v[i] = temp[i];
        }
    }
};