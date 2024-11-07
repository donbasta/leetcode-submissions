class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ret;
        vector<bool> vis(n);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;
        vector<vector<int>> adj(n);
        for (auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        function<void(int, int)> dfs = [&](int v, int p) {
            vis[v] = true;
            tin[v] = low[v] = timer++;
            for (int c : adj[v]) {
                if (c == p) continue;
                if (vis[c]) {
                    low[v] = min(low[v], tin[c]);
                } else {
                    dfs(c, v);
                    low[v] = min(low[v], low[c]);
                    if (low[c] > tin[v]) {
                        ret.push_back(vector<int>{v, c});
                    }
                }
            }
        };
        dfs(0, -1);
        return ret;
    }
};