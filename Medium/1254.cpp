class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        bool adj = false;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        const function<void(int, int)> ff = [&](int i, int j) -> void {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) adj = true;
            for (int x = 0; x < 4; x++) {
                int ni = i + dir[x].first;
                int nj = j + dir[x].second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj] == 1) continue;
                if (vis[ni][nj]) continue;
                vis[ni][nj] = true;
                ff(ni, nj);
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                if (!vis[i][j]) {
                    adj = false;
                    vis[i][j] = true;
                    ff(i, j);
                    if (!adj) ans++;
                }
            }
        }
        return ans;
    }
};