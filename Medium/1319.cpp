class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        const function<void(int)> dfs = [&](int v) -> void {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c);
            }
        };
        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            cc++;
            dfs(i);
        }
        int cable = connections.size();
        if (cable < n - 1) return -1;
        return cc - 1;
    }
};