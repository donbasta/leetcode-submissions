class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        const int INF = 2e9;
        for (int i = 0; i < n; i++) dp[0][i] = grid[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = INF;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    tmp = min(tmp, dp[i - 1][k]);
                }
                dp[i][j] = tmp + grid[i][j];
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};