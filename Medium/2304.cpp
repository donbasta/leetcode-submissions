class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        const int INF = 2e9;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(m * n, INF);
        for (int i = 0; i < n; i++) {
            dp[i] = grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = i * n; j < (i + 1) * n; j++) {
                int tmp = INF;
                for (int k = (i - 1) * n; k < i * n; k++) {
                    tmp = min(tmp, dp[k] + moveCost[grid[k / n][k % n]][j % n]);
                }
                dp[j] = tmp + grid[j / n][j % n];
            }
        }
        int ans = INF;
        for (int i = (m - 1) * n; i < m * n; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};