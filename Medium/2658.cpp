class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int ans = 0;

        pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        const function<int(int, int)> ff = [&](int r, int c) -> int {
            queue<pair<int, int>> Q;
            Q.emplace(r, c);
            vis[r][c] = true;
            int tmp = grid[r][c];
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
                    Q.emplace(nx, ny);
                    tmp += grid[nx][ny];
                }
            }
            return tmp;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (vis[i][j]) continue;
                ans = max(ans, ff(i, j));
            }
        }
        return ans;
    }
};