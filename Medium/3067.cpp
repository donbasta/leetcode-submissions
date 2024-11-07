class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<int> ret(n), dis(n), cnt(n);
        int root, ans;

        const function<void(int, int)> dfs = [&](int v, int p) {
            cnt[v] = (dis[v] == 0);
            for (auto [c, w] : adj[v]) {
                if (c == p) continue;
                dis[c] = (dis[v] + w) % signalSpeed;
                dfs(c, v);
                cnt[v] += cnt[c];
            }
            if (v == root) {
                ans = (cnt[v] - 1) * (cnt[v] - 1);
                for (auto [c, w] : adj[v]) ans -= cnt[c] * cnt[c];
                ans /= 2;
            }
        };

        for (int i = 0; i < n; i++) {
            root = i;
            fill(cnt.begin(), cnt.end(), 0);
            dis[i] = 0;
            dfs(i, i);
            ret[i] = ans;
        }
        return ret;
    }
};