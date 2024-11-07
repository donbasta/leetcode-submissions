class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
        const int mod = 1e9 + 7;
        int tot = grid[0][0] % k;
        dp[0][0][tot] = 1;
        for (int i = 1; i < m; i++) {
            tot = (tot + grid[i][0]) % k;
            dp[i][0][tot] = 1;
        }
        tot = grid[0][0] % k;
        for (int i = 1; i < n; i++) {
            tot = (tot + grid[0][i]) % k;
            dp[0][i][tot] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int kk = 0; kk < k; kk++) {
                    int need = (kk - grid[i][j]) % k;
                    if (need < 0) need += k;
                    dp[i][j][kk] = (dp[i][j][kk] + dp[i - 1][j][need]) % mod;
                    dp[i][j][kk] = (dp[i][j][kk] + dp[i][j - 1][need]) % mod;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};