class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        set<pair<long long, int>> chd[n];
        long long mx[n];
        memset(mx, 0, sizeof(mx));
        const function<void(int, int)> dfs = [&](int v, int p) {
            mx[v] = price[v];
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                chd[v].emplace(mx[c], c);
            }
            if (!chd[v].empty()) {
                mx[v] += chd[v].rbegin()->first;
            }
        };
        dfs(0, 0);
        long long dp[n];
        memset(dp, 0, sizeof(dp));
        const function<void(int, int)> dfs_reroot = [&](int v, int p) {
            long long tmp = 0;
            if (!chd[v].empty()) tmp = chd[v].rbegin()->first;
            dp[v] = price[v] + tmp;
            for (auto c : adj[v]) {
                if (c == p) continue;
                chd[v].erase(make_pair(mx[c], c));
                long long oth = 0;
                if (!chd[v].empty()) {
                    oth = chd[v].rbegin()->first;
                }
                chd[c].emplace(price[v] + oth, v);
                dfs_reroot(c, v);
                chd[c].erase(make_pair(price[v] + oth, v));
                chd[v].emplace(mx[c], c);
            }
        };
        dfs_reroot(0, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i] - price[i]);
        }
        return ans;
    }
};