class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans = 0;
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<long long> val(n);
        const function<void(int, int)> dfs = [&](int v, int p) {
            val[v] = values[v];
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                val[v] += val[c];
            }
        };
        dfs(0, 0);
        for (int i = 0; i < n; i++) {
            if (val[i] % k == 0) ans++;
        }
        return ans;
    }
};