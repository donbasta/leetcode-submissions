class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int MOD = 1e9 + 7;
        int dp[n + 1][k + 1][m + 1];
        int ndp[n + 1][k + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        memset(ndp, 0, sizeof(ndp));

        for (int l = 1; l <= m; l++) {
            dp[1][1][l] = 1;
            ndp[1][1][l] = (ndp[1][1][l - 1] + 1) % MOD;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = 1; l <= m; l++) {
                    int tmp = (1ll * dp[i - 1][j][l] * l) % MOD;
                    tmp = (tmp + ndp[i - 1][j - 1][l - 1]) % MOD;
                    dp[i][j][l] = tmp;
                    ndp[i][j][l] = (ndp[i][j][l - 1] + tmp) % MOD;
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + dp[n][k][i]) % MOD;
        }
        return ans;
    }
};