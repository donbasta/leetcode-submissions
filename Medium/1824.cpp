class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        const int INF = 2e9;
        vector<vector<int>> dp(n, vector<int>(3, INF));
        dp[0][1] = 0;
        dp[0][0] = dp[0][2] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                if (obstacles[i - 1] != j + 1) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                dp[i][j] = min(dp[i][j], dp[i][(j + 1) % 3] + 1);
                dp[i][j] = min(dp[i][j], dp[i][(j + 2) % 3] + 1);
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};