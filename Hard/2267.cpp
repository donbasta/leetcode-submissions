class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool dp[m][n][m + n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    if (grid[i][j] == ')') return false;
                    dp[i][j][1] = true;
                } else if (i == 0) {
                    for (int k = 0; k <= j + 1; k++) {
                        if (grid[i][j] == '(' && k >= 1) dp[i][j][k] = dp[i][j - 1][k - 1];
                        if (grid[i][j] == ')' && k + 1 < m + n) dp[i][j][k] = dp[i][j - 1][k + 1];
                    }
                } else if (j == 0) {
                    for (int k = 0; k <= i + 1; k++) {
                        if (grid[i][j] == '(' && k >= 1) dp[i][j][k] = dp[i - 1][j][k - 1];
                        if (grid[i][j] == ')' && k + 1 < m + n) dp[i][j][k] = dp[i - 1][j][k + 1];
                    }
                } else {
                    for (int k = 0; k < m + n; k++) {
                        if (grid[i][j] == '(' && k >= 1) {
                            dp[i][j][k] = dp[i - 1][j][k - 1] || dp[i][j][k];
                            dp[i][j][k] = dp[i][j - 1][k - 1] || dp[i][j][k];
                        } else if (grid[i][j] == ')' && k + 1 < m + n) {
                            dp[i][j][k] = dp[i - 1][j][k + 1] || dp[i][j][k];
                            dp[i][j][k] = dp[i][j - 1][k + 1] || dp[i][j][k];
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};