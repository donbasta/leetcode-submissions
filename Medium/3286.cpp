class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        set<pair<int, pair<int, int>>> se;
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        vector<vector<int>> dis(m, vector<int>(n, INF));
        se.emplace(grid[0][0], make_pair(0, 0));
        dis[0][0] = grid[0][0];

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!se.empty()) {
            auto now = *se.begin();
            se.erase(se.begin());
            int D = now.first, r = now.second.first, c = now.second.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (D + grid[nr][nc] < dis[nr][nc]) {
                    se.erase(make_pair(dis[nr][nc], make_pair(nr, nc)));
                    dis[nr][nc] = D + grid[nr][nc];
                    se.emplace(dis[nr][nc], make_pair(nr, nc));
                }
            }
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
        //     }
        // }
        return dis[m - 1][n - 1] <= health - 1;
    }
};