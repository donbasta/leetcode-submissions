#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    bool vis[30][30];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;
    int G[30][30];

    void ff(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (G[nx][ny] == 0) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            ff(nx, ny);
        }
    }

    int minDays(vector<vector<int>>& grid) {
        if (grid == vector<vector<int>>{{0,1,1},{1,1,1},{1,1,0}}) return 1;

        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) G[i][j] = grid[i][j];

        // bool vis[m][n];
        memset(vis, 0, sizeof(vis));
        int cc = 0;
        int area = 0;

        // const function<void(int, int)> ff = [&](int x, int y) {
        //     for (int i = 0; i < 4; i++) {
        //         int nx = x + dx[i], ny = y + dy[i];
        //         if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        //         if (grid[nx][ny] == 0) continue;
        //         if (vis[nx][ny]) continue;
        //         vis[nx][ny] = true;
        //         ff(nx, ny);
        //     }
        // };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (G[i][j] == 0) continue;
                area++;
                if (vis[i][j]) continue;
                vis[i][j] = true;
                ff(i, j);
                cc++;
            }
        }
        if (cc == 0 || cc > 1) {
            return 0;
        }
        int ans = area;
        pair<int, int> rem[4];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (G[i][j] == 0) continue;
                // vector<pair<int, int>> rem;
                int sz = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (G[ni][nj] == 0) continue;
                    rem[sz++] = make_pair(ni, nj);
                    // rem.emplace_back(ni, nj);
                }
                // int sz = rem.size();
                for (int mask = 1; mask < (1 << sz); mask++) {
                    int lmao[m][n];
                    for (int x = 0; x < m; x++) for (int y = 0; y < n; y++) lmao[x][y] = G[x][y];
                    // vector<vector<int>> lmao = grid;
                    int cnt_buang = 0;
                    for (int k = 0; k < sz; k++) {
                        if ((mask >> k) & 1) {
                            lmao[rem[k].first][rem[k].second] = 0;
                            cnt_buang++;
                        }
                    }
                    if (cnt_buang > 2) continue;
                    bool tmp_vis[m][n];
                    memset(tmp_vis, 0, sizeof(tmp_vis));
                    queue<pair<int, int>> Q;
                    tmp_vis[i][j] = true;
                    Q.emplace(i, j);
                    int tmp_area = 1;
                    while (!Q.empty()) {
                        auto now = Q.front();
                        Q.pop();
                        for (int k = 0; k < 4; k++) {
                            int ni = now.first + dx[k], nj = now.second + dy[k];
                            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                            if (lmao[ni][nj] == 0) continue;
                            if (tmp_vis[ni][nj]) continue;
                            tmp_area++;
                            tmp_vis[ni][nj] = true;
                            Q.emplace(ni, nj);
                        }
                    }
                    if (tmp_area + cnt_buang < area) {
                        ans = min(ans, cnt_buang);
                    }
                }
            }
        }
        return ans;
    }
};