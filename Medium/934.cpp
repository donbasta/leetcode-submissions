class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> cc(n, vector<int>(n));
        vector<vector<bool>> vis(n, vector<bool>(n));
        int cnt = 0;

        pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        const function<void(int, int, int)> ff = [&](int i, int j, int col) -> void {
            cc[i][j] = col;
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k].first, nj = j + dir[k].second;
                if (ni <  0 || ni >= n || nj < 0 || nj >= n) continue;
                if (grid[ni][nj] == 0) continue;
                if (vis[ni][nj]) continue;
                vis[ni][nj] = true;
                ff(ni, nj, col);
            }
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (vis[i][j]) continue;
                vis[i][j] = true;
                ff(i, j, ++cnt);
            }
        }
        assert (cnt == 2);

        queue<pair<int, int>> Q;
        vector<vector<int>> dis(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cc[i][j] == 1) Q.emplace(i, j), vis[i][j] = true;
            }
        }
        
        vis.assign(n, vector<bool>(n, false));
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int ni = now.first + dir[i].first, nj = now.second + dir[i].second;
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (vis[ni][nj]) continue;
                if (cc[ni][nj] == 2) {
                    return dis[now.first][now.second];
                } else if (cc[ni][nj] == 0) {
                    dis[ni][nj] = dis[now.first][now.second] + 1;
                    vis[ni][nj] = true;
                    Q.emplace(ni, nj);
                }
            }
        }

        return -1;
    }
};