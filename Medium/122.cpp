class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1];
        int mx = -prices[0];
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i - 1], mx + prices[i]);
            mx = max(mx, dp[i - 1] - prices[i]);
        }
        return dp[n - 1];
    }
};