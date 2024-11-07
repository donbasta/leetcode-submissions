class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fac) {
        using ll = long long;
        int n = robot.size();
        int m = fac.size();
        sort(robot.begin(), robot.end());
        sort(fac.begin(), fac.end());

        const ll INF = 2e12;
        ll dp[n][m][n + 1];
        ll pr[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pr[i][j] = INF;
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (fac[i][1] > 0) {
                dp[0][i][fac[i][1] - 1] = pr[0][i] = abs(fac[i][0] - robot[0]);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int lim = fac[j][1];
                ll add = abs(fac[j][0] - robot[i]);
                for (int k = lim - 2; k >= 0; k--) {
                    if (dp[i - 1][j][k + 1] != INF) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k + 1] + add);
                        pr[i][j] = min(pr[i][j], dp[i][j][k]);
                    }
                }
                if (lim > 0) {
                    for (int k = j - 1; k >= 0; k--) {
                        if (pr[i - 1][k] != INF) {
                            dp[i][j][lim - 1] = min(dp[i][j][lim - 1], pr[i - 1][k] + add);
                            pr[i][j] = min(pr[i][j], dp[i][j][lim - 1]);
                        }
                    }
                }
            }
        }
        ll ans = INF;
        for (int i = 0; i < m; i++) {
            ans = min(ans, pr[n - 1][i]);
        }
        return ans;
    }
};