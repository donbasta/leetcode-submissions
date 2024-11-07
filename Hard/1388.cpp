class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n, vector<int>(n / 3 + 1));
        dp[0][1] = slices[0];
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 1; j <= n / 3; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= 2) dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + slices[i]);
            }
        }
        int ans = dp[n - 2][n / 3];
        vector<vector<int>> dp2(n, vector<int>(n / 3 + 1));
        dp2[1][1] = slices[1];
        for (int i = 2; i <= n - 1; i++) {
            for (int j = 1; j <= n / 3; j++) {
                dp2[i][j] = dp2[i - 1][j];
                if (i >= 2) dp2[i][j] = max(dp2[i][j], dp2[i - 2][j - 1] + slices[i]);
            }
        }
        ans = max(ans, dp2[n - 1][n / 3]);
        return ans;
    }
};