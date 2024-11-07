class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long INF = 1e18;
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -INF));
        vector<vector<long long>> ndp(n, vector<long long>(2, -INF));
        dp[0][0] = nums[0];
        ndp[0][0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = 1ll * nums[i] + ndp[i - 1][1];
            dp[i][0] = max(dp[i][0], 1ll * nums[i]);
            dp[i][1] = -(1ll * nums[i]) + ndp[i - 1][0];
            ndp[i][0] = max(ndp[i - 1][0], dp[i][0]);
            ndp[i][1] = max(ndp[i - 1][1], dp[i][1]);
        }
        return max(ndp[n - 1][0], ndp[n - 1][1]);
    }
};