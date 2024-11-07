class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> bawah(m, vector<int>(n)), kanan(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (land[j][i] == 0) continue;
                if (j == m - 1 || land[j + 1][i] == 0) {
                    bawah[j][i] = j;
                } else {
                    bawah[j][i] = bawah[j + 1][i];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (land[i][j] == 0) continue;
                if (j == n - 1 || land[i][j + 1] == 0) {
                    kanan[i][j] = j;
                } else {
                    kanan[i][j] = kanan[i][j + 1];
                }
            }
        }
        vector<vector<int>> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) continue;
                if ((i > 0 && land[i - 1][j] == 1) || (j > 0 && land[i][j - 1] == 1)) {
                    continue;
                }
                int p = bawah[i][j];
                int q = kanan[i][j];
                ret.emplace_back(vector<int>{i, j, p, q});
            }
        }
        return ret;
    }
};