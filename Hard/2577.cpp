class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        set<pair<int, pair<int, int>>> Q;
        const int INF = 2e9;
        vector<vector<int>> mn(m, vector<int>(n, INF));
        Q.emplace(0, make_pair(0, 0));
        mn[0][0] = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!Q.empty()) {
            auto now = *Q.begin();
            Q.erase(Q.begin());
            int D = now.first, r = now.second.first, c = now.second.second;
            for (int j = 0; j < 4; j++) {
                int nr = r + dx[j], nc = c + dy[j];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (mn[nr][nc] != INF) continue;
                int dis;
                if (grid[nr][nc] <= D) dis = D + 1;
                else {
                    dis = grid[nr][nc];
                    if ((dis + D) % 2 == 0) dis++;
                }
                if (dis < mn[nr][nc]) {
                    Q.erase(make_pair(mn[nr][nc], make_pair(nr, nc)));
                    mn[nr][nc] = dis;
                    Q.emplace(mn[nr][nc], make_pair(nr, nc));
                }
            }
        }
        return mn[m - 1][n - 1];
    }
};