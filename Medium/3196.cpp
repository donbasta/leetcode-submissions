class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2));
        dp[0][0] = nums[0];
        dp[0][1] = -1e18;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + nums[i];
            dp[i][1] = dp[i - 1][0] - nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};