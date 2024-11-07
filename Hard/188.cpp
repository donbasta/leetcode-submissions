class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i][j] = maximum of (prices[i] - prices[t] + ndp[t - 1][j - 1]) over t < i

        const int INF = 2e9;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        vector<vector<int>> ndp(n + 1, vector<int>(k + 1, -INF));
        vector<vector<int>> mx(n + 1, vector<int>(k + 1, -INF));
        
        mx[0][0] = -INF;
        for (int i = 1; i <= n; i++) {
            mx[i][0] = max(mx[i - 1][0], -prices[i - 1]);
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= min(i / 2, k); j++) {
                dp[i][j] = prices[i - 1] + mx[i - 1][j - 1];
                ndp[i][j] = max(ndp[i - 1][j], dp[i][j]);
                mx[i][j] = max(mx[i - 1][j], ndp[i - 1][j] - prices[i - 1]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = max(ans, ndp[n][i]);
        }
        return ans;

    }
};