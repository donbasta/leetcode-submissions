class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        using ll = long long;

        int n = grid.size();
        ll dp[n][n + 1][n + 1];
        // ll ndp[n][n + 1]; 
        ll mdp[n][n + 1];
        ll co[n][n + 1];
        memset(dp, 0, sizeof(dp));
        // memset(ndp, 0, sizeof(ndp));
        memset(mdp, 0, sizeof(mdp));
        memset(co, 0, sizeof(co));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                co[i][j + 1] = co[i][j] + grid[j][i];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int u = 0; u <= n; u++) {
                for (int v = 0; v <= n; v++) {
                    ll c1 = 0;
                    if (v > u) c1 = co[i][v] - co[i][u];
                    ll c0 = 0;
                    if (u > v) c0 = co[i - 1][u] - co[i - 1][v];
                    dp[i][u][v] = max(dp[i][u][v], mdp[i - 1][v] + c1 + c0);
                    for (int w = v + 1; w <= n; w++) {
                        ll p = w + 1, q = max(u, w);
                        ll c2 = 0;
                        if (q >= p) c2 = co[i - 1][q] - co[i - 1][p - 1];
                        dp[i][u][v] = max(dp[i][u][v], dp[i - 1][v][w] + c1 + c2);
                    }
                }
            }
            for (int u = 0; u <= n; u++) {
                for (int v = 0; v <= u; v++) {
                    mdp[i][u] = max(mdp[i][u], dp[i][u][v]);
                }
            }

        }
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                ans = max(ans, dp[n - 1][i][j]);
            }
        }
        return ans;
    }
};