class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int dp[k + 1][n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) dp[0][i] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + stayScore[i - 1][j];
                for (int l = 0; l < n; l++) {
                    if (l == j) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][l] + travelScore[l][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[k][i]);
        }
        return ans;
    }
};