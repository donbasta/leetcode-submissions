class Solution {
public:
    int countHousePlacements(int n) {
        vector<vector<int>> dp(n, vector<int>(4));
        if (n == 1) return 4;
        if (n == 2) return 9;
        dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = 1, dp[0][3] = 1;
        dp[1][0] = 4, dp[1][1] = 2, dp[1][2] = 2, dp[1][3] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 2; i < n; i++) {
            dp[i][0] = (1ll * dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
            dp[i][1] = (1ll * dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (1ll * dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][3] = (1ll * dp[i - 1][0]) % MOD;
        }
        return (1ll * dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3]) % MOD;
    }
};