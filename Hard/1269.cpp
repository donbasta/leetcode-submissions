class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<int> dp(arrLen);
        dp[0] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= steps; i++) {
            vector<int> ndp(arrLen);
            for (int j = 0; j < arrLen; j++) {
                if (steps < j * 2) continue;
                if (j + 1 < arrLen) ndp[j] = (ndp[j] + dp[j + 1]) % MOD;
                ndp[j] = (ndp[j] + dp[j]) % MOD;
                if (j > 0) ndp[j] = (ndp[j] + dp[j - 1]) % MOD;
            }
            dp = ndp;
        }
        return dp[0];
    }
};