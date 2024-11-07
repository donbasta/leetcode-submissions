class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        const function<int(int, int)> flood_fill = [&](int r, int c) -> int {
            queue<pair<int, int>> Q;
            Q.emplace(r, c);
            vis[r][c] = true;
            int ret = 1;
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = now.first + dir[i].first;
                    int ny = now.second + dir[i].second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] == 0) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    ret++;
                    Q.emplace(nx, ny);
                }
            };
            return ret;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (vis[i][j]) continue;
                ans = max(ans, flood_fill(i, j));
            }
        }
        return ans;
    }
};