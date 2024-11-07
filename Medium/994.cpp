class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<vector<int>> dis(m, vector<int>(n, INF));
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    Q.emplace(i, j);
                    vis[i][j] = true;
                    dis[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int ni = now.first + dir[i].first;
                int nj = now.second + dir[i].second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj] == 0) continue;
                if (vis[ni][nj]) continue;
                vis[ni][nj] = true;
                dis[ni][nj] = dis[now.first][now.second] + 1;
                Q.emplace(ni, nj);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (!vis[i][j]) return -1;
                    ans = max(ans, dis[i][j]);
                }
            }
        }
        assert(ans != INF);
        return ans;
    }
};