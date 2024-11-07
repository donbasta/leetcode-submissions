class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();

        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][(i + 2) % n] = v[i] * v[(i + 1) % n] * v[(i + 2) % n];
        }
        for (int len = 4; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = (i + len - 1) % n;
                long long tmp = INT_MAX;
                tmp = min(tmp, 1ll * dp[i][(j + n - 1) % n] + 1ll * v[i] * v[(j + n - 1) % n] * v[j]);
                tmp = min(tmp, 1ll * dp[(i + 1) % n][j] + 1ll * v[i] * v[(i + 1) % n] * v[j]);
                for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
                    tmp = min(tmp, 1ll * dp[i][k] + dp[k][j] + 1ll * v[i] * v[k] * v[j]);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};