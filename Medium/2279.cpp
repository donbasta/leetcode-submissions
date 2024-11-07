class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b) -> bool {
            return capacity[a] - rocks[a] < capacity[b] - rocks[b];
        });
        for (int i = 0; i < n; i++) {
            if (additionalRocks < (capacity[idx[i]] - rocks[idx[i]])) {
                return i;
            }
            additionalRocks -= (capacity[idx[i]] - rocks[idx[i]]);
        }
        return n;
    }
};