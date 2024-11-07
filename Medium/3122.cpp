class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(11));
        vector<int> tmp(10);
        dp[n - 1][10] = m;
        for (int i = 0; i < m; i++) {
            tmp[grid[i][n - 1]]++;
        }
        for (int i = 0; i <= 9; i++) {
            dp[n - 1][i] = m - tmp[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            vector<int> tmp(10);
            for (int j = 0; j < m; j++) {
                tmp[grid[j][i]]++;
            }
            for (int j = 0; j <= 9; j++) {
                int mn = INT_MAX;
                for (int k = 0; k <= 10; k++) {
                    if (k == j) continue;
                    mn = min(mn, dp[i + 1][k]);
                }
                dp[i][j] = (m - tmp[j]) + mn;
            }
            int mn = INT_MAX;
            for (int j = 0; j <= 10; j++) mn = min(mn, dp[i + 1][j]);
            dp[i][10] = m + mn;
        }
        
        int ans = INT_MAX;
        for (int i = 0; i <= 10; i++) ans = min(ans, dp[0][i]);
        return ans;
    }
};