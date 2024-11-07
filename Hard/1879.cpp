class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, INT_MAX);
        for (int i = 0; i < n; i++) dp[1 << i] = nums1[0] ^ nums2[i];
        for (int mask = 1; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            if (cnt == 1) continue;
            for (int k = 0; k < n; k++) {
                if (!((mask >> k) & 1)) continue;
                dp[mask] = min(dp[mask], dp[mask ^ (1 << k)] + (nums1[cnt - 1] ^ nums2[k]));
            }
        }
        return dp[(1 << n) - 1];
    }
};