class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1 << n));
        for (int i = 0; i < n; i++) {
            dp[i][1 << i] = 1;
        }
        for (int i = 1; i < (1 << n); i++) {
            if (__builtin_popcount(i) == 1) continue;
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    if (!((i >> k) & 1)) continue;
                    if (nums[k] % nums[j] != 0 && nums[j] % nums[k] != 0) continue;
                    dp[j][i] = (dp[j][i] + dp[k][i ^ (1 << j)]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i][(1 << n) - 1]) % MOD;
        }
        return ans;
    }
};