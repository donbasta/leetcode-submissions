class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                if (vis[i][j]) continue;
                ans++;
                
                queue<pair<int, int>> Q;
                Q.emplace(i, j);
                vis[i][j] = true;
                while (!Q.empty()) {
                    auto now = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = now.first + dir[k].first;
                        int ny = now.second + dir[k].second;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (grid[nx][ny] == '0') continue;
                        if (vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.emplace(nx, ny);
                    }
                }
            }
        }
        return ans;
    }
};