class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        queue<pair<int, int>> Q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n)), colored(m, vector<bool>(n));
    
        int cur_col = grid[row][col];
        Q.emplace(row, col);
        vis[row][col] = true;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.first + dir[i].first;
                int ny = now.second + dir[i].second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] != cur_col) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                Q.emplace(nx, ny);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) continue;
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) colored[i][j] = true;
                else {
                    int cek = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dir[k].first, nj = j + dir[k].second;
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        cek += grid[ni][nj] != cur_col;
                    }
                    colored[i][j] = (cek >= 1);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (colored[i][j]) grid[i][j] = color;
            }
        }
        return grid;
    }
};