class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 2e9;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, INF)));
        if (houses[0] == 0) {
            for (int i = 1; i <= n; i++) dp[1][i][1] = cost[0][i - 1];
        } else {
            dp[1][houses[0]][1] = 0;
        }
        for (int i = 2; i <= m; i++) {
            if (houses[i - 1] != 0) {
                for (int k = 1; k <= target; k++) {
                    dp[i][houses[i - 1]][k] = dp[i - 1][houses[i - 1]][k];
                    for (int t = 1; t <= n; t++) {
                        if (t == houses[i - 1]) continue;
                        dp[i][houses[i - 1]][k] = min(dp[i][houses[i - 1]][k], dp[i - 1][t][k - 1]);
                    }
                }
            } else {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= target; k++) {
                        dp[i][j][k] = dp[i - 1][j][k] + cost[i - 1][j - 1];
                        for (int t = 1; t <= n; t++) {
                            if (t == j) continue;
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][t][k - 1] + cost[i - 1][j - 1]);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[m][i][target]);
        }
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         for (int k = 1; k <= target; k++) {
        //             cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
        //         }
        //     }
        // }
        if (ans == INF) return -1;
        return ans;
    }
};