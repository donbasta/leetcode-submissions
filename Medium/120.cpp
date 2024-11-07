class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<long long>> dp(n);
        for (int i = 0; i < n; i++) dp[i].resize(i + 1);
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                long long tmp = 1e18;
                if (j > 0) tmp = min(tmp, 1ll * triangle[i][j] + dp[i - 1][j - 1]);
                if (j < i) tmp = min(tmp, 1ll * triangle[i][j] + dp[i - 1][j]);
                dp[i][j] = tmp;
            }
        }
        long long ans = 1e18;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};