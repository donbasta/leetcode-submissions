class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1));
        const int INF = 2e9;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, jobDifficulty[i - 1]);
            dp[i][1] = mx;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= d; j++) {
                int tmp = INF;
                int mxToday = 0;
                for (int k = i - 1; k >= j - 1; k--) {
                    mxToday = max(mxToday, jobDifficulty[k]);
                    tmp = min(tmp, dp[k][j - 1] + mxToday);
                }
                dp[i][j] = tmp;
            }
        }
        if (dp[n][d] == INF) return -1;
        return dp[n][d];
    }
};