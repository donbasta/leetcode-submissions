class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        function<void(int, vector<bool>&, vector<vector<int>>&)> dfs = [&](int v, vector<bool>& vis, vector<vector<int>>& adj) {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c, vis, adj);
            }
        };

        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> adj(n);
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                adj[edges[j][0] - 1].push_back(edges[j][1] - 1);
                adj[edges[j][1] - 1].push_back(edges[j][0] - 1);
            }
            vector<bool> vis(n);
            vis[0] = true;
            dfs(0, vis, adj);
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (!vis[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return edges[i];
        }
        return vector<int>{-1, -1};
    }
};