class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 2e9;
        vector<int> dp(amount + 1, INF);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        int n = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] > i) break;
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        if (dp[amount] == INF) dp[amount] = -1; 
        return dp[amount];
    }
};