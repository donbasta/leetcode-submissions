class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        using ll = long long;
        ll prf[m][n], suf[m][n], dp[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = points[i][j];
                } else {
                    dp[i][j] = max(prf[i - 1][j] - j + points[i][j], suf[i - 1][j] + j + points[i][j]);
                }
            }
            prf[i][0] = dp[i][0];
            for (int j = 1; j < n; j++) {
                prf[i][j] = max(prf[i][j - 1], dp[i][j] + j);
            }
            suf[i][n - 1] = dp[i][n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; j--) {
                suf[i][j] = max(suf[i][j + 1], dp[i][j] - j);
            }
        }
        ll ans = -1e18;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[m - 1][i]);
        }
        return ans;
    }
};