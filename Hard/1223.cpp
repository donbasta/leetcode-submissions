class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[n][6][16], all[n][6];
        memset(dp, 0, sizeof(dp));
        memset(all, 0, sizeof(all));
        const int MOD = 1e9 + 7;
        for (int j = 0; j < 6; j++) {
            dp[0][j][1] = 1;
            all[0][j] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    if (j == k) continue;
                    dp[i][j][1] = (dp[i][j][1] + all[i - 1][k]) % MOD;
                }
                for (int k = 2; k <= rollMax[j]; k++) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
                for (int k = 1; k <= rollMax[j]; k++) {
                    all[i][j] = (all[i][j] + dp[i][j][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = (ans + all[n - 1][i]) % MOD;
        }
        return ans;
    }
};