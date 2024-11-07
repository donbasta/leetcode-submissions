class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v2(m, vector<int>(n)), v5(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                while (grid[i][j] % 2 == 0) {
                    grid[i][j] /= 2, v2[i][j]++;
                }
                while (grid[i][j] % 5 == 0) {
                    grid[i][j] /= 5, v5[i][j]++;
                }
            }
        }
        vector<vector<int>> v2v(m, vector<int>(n));
        vector<vector<int>> v2h(m, vector<int>(n));
        vector<vector<int>> v5v(m, vector<int>(n));
        vector<vector<int>> v5h(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            v2h[i][0] = v2[i][0];
            v5h[i][0] = v5[i][0];
            for (int j = 1; j < n; j++) {
                v2h[i][j] = v2h[i][j - 1] + v2[i][j];
                v5h[i][j] = v5h[i][j - 1] + v5[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            v2v[0][i] = v2[0][i];
            v5v[0][i] = v5[0][i];
            for (int j = 1; j < m; j++) {
                v2v[j][i] = v2v[j - 1][i] + v2[j][i];
                v5v[j][i] = v5v[j - 1][i] + v5[j][i];
            }
        }

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<int>> vpv = {{v2v[i][j], v5v[i][j]}, {v2v[m - 1][j] - (i ? v2v[i - 1][j] : 0), v5v[m - 1][j] - (i ? v5v[i - 1][j] : 0)}};
                vector<vector<int>> vph = {{v2h[i][n - 1] - (j ? v2h[i][j - 1] : 0), v5h[i][n - 1] - (j ? v5h[i][j - 1] : 0)}, {v2h[i][j], v5h[i][j]}};

                for (auto a : vpv) {
                    for (auto b : vph) {
                        ret = max(ret, min(a[0] + b[0] - v2[i][j], a[1] + b[1] - v5[i][j]));
                    }
                }
            }
        }

        return ret;
    }
};