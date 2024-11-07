class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n));

        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    Q.emplace(i, j);
                    vis[i][j] = true;
                }
            }
        } 

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.first + dir[i].first;
                int ny = now.second + dir[i].second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                dis[nx][ny] = dis[now.first][now.second] + 1;
                Q.emplace(nx, ny);
            }
        }

        return dis;
    }
};