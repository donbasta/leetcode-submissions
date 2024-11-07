class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    Q.emplace(i, j);
                }
            }
        }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = now.first + dx[j], ny = now.second + dy[j];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (dis[nx][ny] != -1) continue;
                dis[nx][ny] = dis[now.first][now.second] + 1;
                Q.emplace(nx, ny);
            }
        }
        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dis[i][j]);
            }
        }
        if (ans == 0) return -1;
        return ans;
    }
};