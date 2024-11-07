class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        const int MX = 1e4;
        const int D = 15;
        vector<vector<int>> dp(n, vector<int>(D));
        vector<int> pw(D);
        for (int i = 0; i < D; i++) {
            pw[i] = (1 << i);
        }
        const function<void(int, int)> dfs = [&](int v, int p) -> void {
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
            }
            vector<int> tmp(D);
            for (auto c : adj[v]) {
                for (int i = 0; i < D; i++) {
                    tmp[i] += dp[c][i];
                }
            }
            for (int i = 0; i < D; i++) {
                dp[v][i] = max(coins[v] / pw[i] - k + tmp[i], (i < D - 1) ? (coins[v] / pw[i + 1] + tmp[i + 1]) : 0);
            }
        };
        dfs(0, 0);
        return max(dp[0][0], dp[0][1]);
    }
};