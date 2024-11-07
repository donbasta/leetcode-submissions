class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<double> p(n + 1);
        p[1] = 1;
        vector<vector<int>> adj(n + 1), adj2(n + 1);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        // cout << fixed << setprecision(5);

        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto c : adj[v]) {
                if (c == p) continue;
                adj2[v].push_back(c);
                dfs(c, v);
            }
        };
        dfs(1, 1);

        for (int i = 1; i <= t; i++) {
            vector<double> tmp(n + 1);
            for (int j = 1; j <= n; j++) {
                if (!adj2[j].empty()) {
                    for (auto v : adj2[j]) {
                        tmp[v] += p[j] * (double)1 / (double)adj2[j].size();
                    }
                } else {
                    tmp[j] += p[j];
                }
            }
            // for (int j = 1; j <= n; j++) {
            //     cout << j << ' ' << tmp[j] << '\n';
            // }
            swap(tmp, p);
        }
        return p[target];
    }
};