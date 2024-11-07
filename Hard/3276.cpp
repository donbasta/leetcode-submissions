class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int pos[101];
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] |= (1 << i);
            }
        }
        int ve[10];
        int sz = 0;
        int ret = 0;
        for (int i = 100; i >= 0; i--) {
            if (pos[i] == 0) continue;
            bool ok = true;
            for (int j = 0; j < (1 << sz); j++) {
                int tmp = pos[i];
                int cnt = 1 + __builtin_popcount(j);
                for (int k = 0; k < sz; k++) {
                    if ((j >> k) & 1) { tmp |= pos[ve[k]]; }
                }
                if (__builtin_popcount(tmp) < cnt) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            ve[sz++] = i;
            ret += i;
            if (sz >= m) {
                break;
            }
        }
        return ret;
    }
};