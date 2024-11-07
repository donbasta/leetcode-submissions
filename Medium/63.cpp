class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                if ((i) && (obstacleGrid[i - 1][j] == 0)) dp[i][j] += dp[i - 1][j];
                if ((j) && (obstacleGrid[i][j - 1] == 0)) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};