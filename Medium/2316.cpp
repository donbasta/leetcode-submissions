class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);
        const function<void(int)> dfs = [&](int v) -> void {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                cnt++;
                vis[c] = true;
                dfs(c);
            }
        };

        vector<int> sz;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt = 1;
                vis[i] = true;
                dfs(i);
                sz.push_back(cnt);
            }
        }

        long long sm = 0;
        long long sq = 0;
        for (auto e : sz) {
            sm += e;
            sq += 1ll * e * e;
        }
        long long ans = (sm * sm - sq) / 2;
        return ans;
    }
};