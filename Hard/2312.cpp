class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
        long long dp[m + 1][n + 1], pcs[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        memset(pcs, -1, sizeof(pcs));

        for (auto p : prices) {
            pcs[p[0]][p[1]] = p[2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                long long tmp = 0;
                if (pcs[i][j] != -1) {
                    tmp = pcs[i][j];
                }
                for (int x = 1; x <= i - 1; x++) {
                    tmp = max(tmp, dp[x][j] + dp[i - x][j]);
                }
                for (int x = 1; x <= j - 1; x++) {
                    tmp = max(tmp, dp[i][x] + dp[i][j - x]);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[m][n];
    }
};