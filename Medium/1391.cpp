class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        bool vis[m][n];
        memset(vis, false, sizeof(vis));

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        bool ar[6][4] = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {1, 0, 0, 1},
            {1, 1, 0, 0},
            {0, 0, 1, 1},
            {0, 1, 1, 0}
        };

        queue<pair<int, int>> Q;
        Q.emplace(0, 0);
        vis[0][0] = true;
        while (!Q.empty()) {
            auto now = Q.front();
            int r = now.first, c = now.second;
            int val = grid[r][c];
            Q.pop();
            for (int i = 0; i < 4; i++) {
                if (!ar[val - 1][i]) continue;
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (vis[nr][nc]) continue;
                if (!ar[grid[nr][nc] - 1][(i + 2) % 4]) continue;
                vis[nr][nc] = true;
                Q.emplace(nr, nc);
            }
        }
        return vis[m - 1][n - 1];
    }
};