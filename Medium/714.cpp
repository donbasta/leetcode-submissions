class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // dp[i][0] = max(dp[i - 1][1] + prices[i] - fee, dp[i - 1][0])
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);

        int a = 0, b = -2e9;
        for (int i = 0; i < n; i++) {
            int ca = max(b + prices[i] - fee, a);
            int cb = max(b, a - prices[i]);
            a = ca, b = cb;
        }
    
        return a;
    }
};