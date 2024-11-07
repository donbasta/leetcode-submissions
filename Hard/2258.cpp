class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto ok = [&](int T) -> bool {
            vector<vector<bool>> burn(m, vector<bool>(n)), vis(m, vector<bool>(n));
            queue<vector<int>> Q;
            for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    burn[i][j] = true;
                    Q.emplace(vector<int>{i, j, 0, 0});
                }
            }
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            while (!Q.empty()) {
                if (Q.front()[2] == T) {
                    break;
                }
                auto now = Q.front();
                Q.pop();
                int cx = now[0], cy = now[1], t = now[2];
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dx[i], ny = cy + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 2) continue;
                    if (burn[nx][ny]) continue;
                    burn[nx][ny] = true;
                    Q.emplace(vector<int>{nx, ny, t + 1, 0});
                }
            }

            if (burn[0][0]) return false;
            Q.emplace(vector<int>{0, 0, T, 1});
            int earliest = -1;
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                int cx = now[0], cy = now[1], t = now[2], state = now[3];
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dx[i], ny = cy + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 2) continue;
                    if (state == 0) {
                        if (burn[nx][ny]) continue;
                        burn[nx][ny] = true;
                        Q.emplace(vector<int>{nx, ny, t + 1, state});
                        if (nx == m - 1 && ny == n - 1) earliest = t + 1;
                    } else {
                        if (nx == m - 1 && ny == n - 1 && earliest == t + 1) return true;
                        if (burn[nx][ny]) continue;
                        if (vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.emplace(vector<int>{nx, ny, t + 1, state});
                        if (nx == m - 1 && ny == n - 1) return true;
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = n * m + 100, piv = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (ok(mid)) {
                piv = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (piv >= n * m + 100) piv = 1e9;
        return piv;
    }
};