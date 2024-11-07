class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        vector<vector<int>> dis(m, vector<int>(n, INF));
        set<pair<int, pair<int, int>>> se;
        dis[0][0] = 0;
        se.emplace(0, make_pair(0, 0));

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!se.empty()) {
            auto now = *se.begin();
            se.erase(se.begin());
            int D = now.first, r = now.second.first, c = now.second.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] + D < dis[nr][nc]) {
                    se.erase(make_pair(dis[nr][nc], make_pair(nr, nc)));
                    dis[nr][nc] = grid[nr][nc] + D;
                    se.emplace(dis[nr][nc], make_pair(nr, nc));
                }
            }
        }
        return dis.back().back();
    }
};