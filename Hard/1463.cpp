class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -INF)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int mx = -INF;
                    for (int jj = j - 1; jj <= j + 1; jj++) {
                        for (int kk = k - 1; kk <= k + 1; kk++) {
                            if (jj < 0 || jj >= n || kk < 0 || kk >= n) continue;
                            if (dp[i - 1][jj][kk] == -INF) continue;
                            mx = max(mx, dp[i - 1][jj][kk]);
                        }
                    }
                    if (mx == -INF) continue;
                    int add = (j == k ? grid[i][j] : grid[i][j] + grid[i][k]);
                    dp[i][j][k] = add + mx;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[m - 1][i][j]);
            }
        }
        return ans;
    }
};