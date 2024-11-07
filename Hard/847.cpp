class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        const int INF = 2e9;
        int dp[1 << n][n];
        for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) dp[i][j] = INF;
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                int prv_mask = i ^ (1 << j);
                for (auto c : graph[j]) {
                    if (!((prv_mask >> c) & 1)) continue;
                    if (dp[prv_mask][c] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[prv_mask][c] + 1);
                }
            }
            for (int _ = 0; _ < n; _++) {
                for (int j = 0; j < n; j++) {
                    if (!((i >> j) & 1)) continue;
                    for (auto c : graph[j]) {
                        if (!((i >> c) & 1)) continue;
                        if (dp[i][c] == INF) continue;
                        dp[i][j] = min(dp[i][j], dp[i][c] + 1);
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[(1 << n) - 1][i]);
        }
        return ans;
    }
};