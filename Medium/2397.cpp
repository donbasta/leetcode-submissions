class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        int val[m];
        memset(val, 0, sizeof(val));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) val[i] ^= (1 << j);
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << m); i++) {
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if (!((i >> j) & 1)) continue;
                tmp = (tmp | val[j]);
            }
            if (__builtin_popcount(tmp) <= numSelect) {
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
    }
};