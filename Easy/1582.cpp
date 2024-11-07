class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int row[m], col[n];
        int spec[m][n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(spec, 0, sizeof(spec));
        for (int i = 0; i < m; i++) {
            int pos = -1;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    pos = j;
                    row[i]++;
                }
            }
            if (row[i] == 1) {
                spec[i][pos]++;
            }
        }
        for (int i = 0; i < n; i++) {
            int pos = -1;
            for (int j = 0; j < m; j++) {
                if (mat[j][i] == 1) {
                    col[i]++;
                    pos = j;
                }
            }
            if (col[i] == 1) {
                spec[pos][i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += (spec[i][j] == 2);
            }
        }
        return ans;
    }
};