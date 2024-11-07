class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int pref[m][n];
        memset(pref, 0, sizeof(pref));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = mat[i][j];
                if (i) tmp += pref[i - 1][j];
                if (j) tmp += pref[i][j - 1];
                if ((i > 0) && (j > 0)) tmp -= pref[i - 1][j - 1];
                pref[i][j] = tmp;
            }
        }
        const function<int(int, int, int, int)> get = [&](int r1, int r2, int c1, int c2) -> int {
            int ans = pref[r2][c2];
            if (r1 > 0) ans -= pref[r1 - 1][c2];
            if (c1 > 0) ans -= pref[r2][c1 - 1];
            if ((r1 > 0) && (c1 > 0)) ans += pref[r1 - 1][c1 - 1];
            return ans;
        };
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = get(max(0, i - k), min(m - 1, i + k), max(0, j - k), min(n - 1, j + k));
            }
        }
        return ret;
    }
};