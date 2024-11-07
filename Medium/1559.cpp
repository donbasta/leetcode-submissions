class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sz = m * n;
        vector<vector<int>> adj(sz);
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int now = i * n + j;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k].first, nj = j + dir[k].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    int nx = ni * n + nj;
                    if (grid[ni][nj] == grid[i][j]) {
                        adj[now].push_back(nx);
                    }
                }
            }
        }
        vector<bool> vis(sz);
        const function<bool(int, int)> dfs = [&](int v, int par) -> bool {
            vis[v] = true;
            for (auto c : adj[v]) {
                if (c == par) continue;
                if (vis[c]) return true;
                if (dfs(c, v)) return true;
            }
            return false;
        };
        for (int i = 0; i < sz; i++) {
            if (vis[i]) continue;
            if (dfs(i, -1)) {
                return true;
            }
        }
        return false;
    }
};