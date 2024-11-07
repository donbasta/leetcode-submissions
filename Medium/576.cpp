class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[m][n][maxMove + 1];
        memset(dp, 0, sizeof(dp));
        dp[startRow][startColumn][0] = 1;
        const int MOD = 1e9 + 7;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 1; i < maxMove; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    for (int x = 0; x < 4; x++) {
                        int nj = j + dx[x], nk = k + dy[x];
                        if (nj < 0 || nj >= m || nk < 0 || nk >= n) continue;
                        dp[j][k][i] = (dp[j][k][i] + dp[nj][nk][i - 1]) % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int out = 0;
                if (i == 0) out++;
                if (i == m - 1) out++;
                if (j == 0) out++;
                if (j == n - 1) out++;
                if (out == 0) continue;
                for (int k = 0; k < maxMove; k++) {
                    ans = (1ll * ans + 1ll * out * dp[i][j][k]) % MOD;
                }
            }
        }
        return ans;
    }
};