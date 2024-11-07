class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            vector<int> ndp(amount + 1);
            for (int j = 0; j <= amount; j++) {
                for (int k = 0; k <= j; k++) {
                    if (k * coins[i] > j) break;
                    ndp[j] += dp[j - coins[i] * k];
                }
            }
            dp = ndp;
        }
        return dp[amount];
    }
};