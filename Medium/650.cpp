class Solution {
public:
    int minSteps(int n) {
        int dp[n + 1][n + 1];
        const int INF = 2e9;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = INF;

        //dp[i][j] --> i A's and j A's on buffer to copy
        dp[1][0] = 0;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = INF;
            for (int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i][j], dp[i - j][j] + 1);
                tmp = min(tmp, dp[i][j]);
            }
            dp[i][i] = tmp + 1;
        }
        int ans = INF;
        for (int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
        return ans;
    }
};