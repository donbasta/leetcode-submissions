class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int INF = 2e9;
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<vector<int>> dis(m, vector<int>(n, INF));

        if (grid[0][0] != 0) return -1;

        queue<pair<int, int>> Q;
        Q.emplace(0, 0);
        dis[0][0] = 0;
        vis[0][0] = true;

        vector<pair<int, int>> dirs = {
            {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}
        };

        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto dir : dirs) {
                int nx = now.first + dir.first;
                int ny = now.second + dir.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= m) continue;
                if (vis[nx][ny]) continue;
                if (grid[nx][ny] != 0) continue;
                Q.emplace(nx, ny);
                dis[nx][ny] = min(dis[nx][ny], dis[now.first][now.second] + 1);
                vis[nx][ny] = true;
            }
        }

        return (dis[m - 1][n - 1] == INF ? -1 : dis[m - 1][n - 1] + 1);
    }
};