class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int prev_miss = 0;
        for (int i = 0; i < n; i++) {
            int missing = arr[i] - (i + 1);
            if (missing >= k) {
                return (i ? arr[i - 1] : 0) + (k - prev_miss);
            }
            prev_miss = missing;
        }
        return arr[n - 1] + (k - prev_miss);
    }
};