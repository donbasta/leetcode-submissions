class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> adj[2 * n * (n + 1)];
        auto connect = [&](int x, int y) { adj[x].push_back(y), adj[y].push_back(x); };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = j + n * i;
                int d =  j + n * (i + 1);
                int l = n * n + n + i + n * j;
                int r = n * n + n + i + n * (j + 1);
                if (grid[i][j] == '/') {
                    connect(u, l), connect(d, r);
                } else if (grid[i][j] == '\\') {
                    connect(d, l), connect(u, r);
                } else {
                    connect(u, l), connect(l, d), connect(d, r), connect(r, u);
                }
            }
        }

        bool vis[2 * n * (n + 1)];
        memset(vis, false, sizeof(vis));
        function<void(int)> dfs = [&](int x) {
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c);
            }
        };

        int ans = 0;
        for (int i = 0; i < 2 * n * (n + 1); i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};