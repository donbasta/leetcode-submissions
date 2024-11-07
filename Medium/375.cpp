class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i < n; i++) dp[i][i + 1] = i;
        for (int len = 3; len <= n; len++) {
            for (int j = 1; j + len - 1 <= n; j++) {
                int tmp = min(j + dp[j + 1][j + len - 1], j + len - 1 + dp[j][j + len - 2]);
                for (int k = j + 1; k < j + len - 1; k++) {
                    tmp = min(tmp, k + max(dp[j][k - 1], dp[k + 1][j + len - 1]));
                }
                dp[j][j + len - 1] = tmp;
            }
        }
        return dp[1][n];
    }
};