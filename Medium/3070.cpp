class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = grid[i][j] + (i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0) - (((i > 0) && (j > 0)) ? dp[i - 1][j - 1] : 0);
                ans += dp[i][j] <= k;
            }
        }
        return ans;
    }
};