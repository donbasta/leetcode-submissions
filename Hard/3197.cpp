class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m][n][m][n];
        memset(dp, -1, sizeof(dp));

        auto min_area = [&](int x1, int y1, int x2, int y2) -> int {
            if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
            int l = INT_MAX, r = INT_MIN, u = INT_MIN, d = INT_MAX;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    if (grid[i][j] == 1) {
                        l = min(l, j);
                        r = max(r, j);
                        u = max(u, i);
                        d = min(d, i);
                    }
                }
            }
            int area = 0;
            if (l != INT_MAX) area = (u - d + 1) * (r - l + 1);
            return dp[x1][y1][x2][y2] = area;
        };

        int ret = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                int l1 = min_area(0, 0, m - 1, i);
                int l2 = min_area(0, i + 1, m - 1, j);
                int l3 = min_area(0, j + 1, m - 1, n - 1);
                ret = min(ret, l1 + l2 + l3);
            }
        }
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j + 1 < m; j++) {
                int l1 = min_area(0, 0, i, n - 1);
                int l2 = min_area(i + 1, 0, j, n - 1);
                int l3 = min_area(j + 1, 0, m - 1, n - 1);
                ret = min(ret, l1 + l2 + l3);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int l1 = min_area(0, 0, m - 1, i);
                int l2 = min_area(0, i + 1, j, n - 1);
                int l3 = min_area(j + 1, i + 1, m - 1, n - 1);
                ret = min(ret, l1 + l2 + l3);

                l1 = min_area(0, i + 1, m - 1, n - 1);
                l2 = min_area(0, 0, j, i);
                l3 = min_area(j + 1, 0, m - 1, i);
                ret = min(ret, l1 + l2 + l3);

                l1 = min_area(0, 0, j, n - 1);
                l2 = min_area(j + 1, 0, m - 1, i);
                l3 = min_area(j + 1, i + 1, m - 1, n - 1);
                ret = min(ret, l1 + l2 + l3);

                l1 = min_area(0, 0, j, i);
                l2 = min_area(0, i + 1, j, n - 1);
                l3 = min_area(j + 1, 0, m - 1, n - 1);
                ret = min(ret, l1 + l2 + l3);
            }
        }
        return ret;
    }
};