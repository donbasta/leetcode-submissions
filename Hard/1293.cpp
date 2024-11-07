class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        vector<vector<vector<int>>> dis(m, vector<vector<int>>(n, vector<int>(k + 1, INF)));
        set<pair<int, vector<int>>> se;
        dis[0][0][0] = 0;
        se.emplace(0, vector<int>{0, 0, 0});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!se.empty()) {
            auto now = *se.begin();
            se.erase(se.begin());
            int D = now.first, r = now.second[0], c = now.second[1], kk = now.second[2];
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] == 0) {
                    if (D + 1 < dis[nr][nc][kk]) {
                        se.erase(make_pair(dis[nr][nc][kk], vector<int>{nr, nc, kk}));
                        dis[nr][nc][kk] = D + 1;
                        se.emplace(dis[nr][nc][kk], vector<int>{nr, nc, kk});
                    }
                } else {
                    if (D - 1 != dis[nr][nc][kk - grid[r][c]]) {
                        if (kk < k && D + 1 < dis[nr][nc][kk + 1]) {
                            se.erase(make_pair(dis[nr][nc][kk + 1], vector<int>{nr, nc, kk + 1}));
                            dis[nr][nc][kk + 1] = D + 1;
                            se.emplace(dis[nr][nc][kk + 1], vector<int>{nr, nc, kk + 1});
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= k; i++) {
            ans = min(ans, dis.back().back()[i]);
        }
        if (ans == INF) return -1;
        return ans;
    }
};