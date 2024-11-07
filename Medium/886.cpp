class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<bool> vis(n + 1);
        vector<int> col(n + 1, -1);
        vector<vector<int>> adj(n + 1);
        for (auto d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        function<bool(int)> dfs = [&](int v) -> bool {
            for (auto c : adj[v]) {
                if (vis[c]) {
                    if (col[c] == col[v]) return false;
                } else {
                    vis[c] = true;
                    col[c] = (col[v] ^ 1);
                    if (!dfs(c)) {
                        return false;
                    }
                }
            }
            return true;
        };

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            col[i] = 0;
            if (!dfs(i)) return false;
        }
        return true;
    }
};