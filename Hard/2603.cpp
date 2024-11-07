class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int dp[n], mx[n];
        set<pair<int, int>> mx_chd[n];
        unordered_map<int, int> val[n];
        const function<void(int, int)> dfs = [&](int v, int p) {
            dp[v] = 0;
            mx[v] = -1;
            if (coins[v] == 1) mx[v] = 0;
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                if (mx[c] != -1) {
                    mx[v] = max(mx[v], mx[c] + 1);
                    val[v][c] = mx[c] + 1;
                } else {
                    val[v][c] = -1;
                }
                mx_chd[v].emplace(val[v][c], c);
                if (val[v][c] >= 3) {
                    dp[v] += (2 + dp[c]);
                }
            }
        };
        dfs(0, 0);

        int ans = INT_MAX;
        const function<void(int, int)> dfs_reroot = [&](int v, int p) {
            ans = min(ans, dp[v]);
            for (auto c : adj[v]) {
                if (c == p) continue;
                mx_chd[v].erase(make_pair(val[v][c], c));
                int mx_sisa = -1;
                if (!mx_chd[v].empty()) {
                    int tmp = mx_chd[v].rbegin()->first;
                    if (tmp == -1) {
                        mx_sisa = -1;
                    } else {
                        mx_sisa = tmp + 1;
                    }
                }
                if (mx_sisa == -1 && coins[v] == 1) mx_sisa = 1;
                mx_chd[c].emplace(mx_sisa, v);
                if (val[v][c] >= 3) {
                    dp[v] -= (2 + dp[c]);
                }
                if (mx_sisa >= 3) {
                    dp[c] += (2 + dp[v]);
                }
                dfs_reroot(c, v);
                if (mx_sisa >= 3) {
                    dp[c] -= (2 + dp[v]);
                }
                if (val[v][c] >= 3) {
                    dp[v] += (2 + dp[c]);
                }
                mx_chd[c].erase(make_pair(mx_sisa, v));
                mx_chd[v].emplace(val[v][c], c);
            }
        };
        dfs_reroot(0, 0);

        return ans;
    }
};