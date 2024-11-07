class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    vis[i][j] = true;
                    Q.emplace(i, j);
                }
            }
        }
        pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.first + dir[i].first;
                int ny = now.second + dir[i].second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                ret[nx][ny] = ret[now.first][now.second] + 1;
                Q.emplace(nx, ny);
            }
        }
        return ret;
    }
};