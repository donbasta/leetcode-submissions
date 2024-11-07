class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<int>> idx(m, vector<int>(n, -1));
        vector<vector<bool>> vis1(m, vector<bool>(n)), vis2(m, vector<bool>(n));
        int id = 0;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        const function<void(int, int, int)> ff1 = [&](int ci, int cj, int val) {
            for (int i = 0; i < 4; i++) {
                int ni = ci + dx[i], nj = cj + dy[i];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid1[ni][nj] == 0) continue;
                if (vis1[ni][nj]) continue;
                vis1[ni][nj] = true;
                idx[ni][nj] = val;
                ff1(ni, nj, val);
            }
        };

        const function<bool(int, int, int)> ff2 = [&](int ci, int cj, int val) -> bool {
            bool ans = true;
            for (int i = 0; i < 4; i++) {
                int ni = ci + dx[i], nj = cj + dy[i];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid2[ni][nj] == 0) continue;
                if (vis2[ni][nj]) continue;
                vis2[ni][nj] = true;
                if (idx[ni][nj] != val) ans = false;
                ans &= ff2(ni, nj, val);
            }
            return ans;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid1[i][j] == 0) continue;
                if (vis1[i][j]) continue;
                vis1[i][j] = true;
                idx[i][j] = id;
                ff1(i, j, id);
                id++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 0) continue;
                if (vis2[i][j]) continue;
                if (idx[i][j] == -1) continue;
                if (ff2(i, j, idx[i][j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};