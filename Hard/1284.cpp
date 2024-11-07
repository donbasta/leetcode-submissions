class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int tot = m * n;
        int mxMask = (1 << tot) - 1;
        const int INF = 1e9;
        int ans = INF;
        for (int i = 0; i <= mxMask; i++) {
            int steps = 0;
            vector<vector<int>> tmp(m, vector<int>(n));
            for (int x = 0; x < m; x++) for (int y = 0; y < n; y++) tmp[x][y] = mat[x][y];
            for (int j = 0; j < tot; j++) {
                if (!((1 << j) & i)) continue;
                steps++;
                int x = j / n;
                int y = j % n;
                tmp[x][y] ^= 1;
                if (x > 0) tmp[x - 1][y] ^= 1;
                if (x < m - 1) tmp[x + 1][y] ^= 1;
                if (y > 0) tmp[x][y - 1] ^= 1;
                if (y < n - 1) tmp[x][y + 1] ^= 1;
            }
            bool ok = true;
            for (int x = 0; x < m; x++) for (int y = 0; y < n; y++) ok &= (tmp[x][y] == 0);
            if (ok) {
                ans = min(ans, steps);
            }
        }
        if (ans == INF) return -1;
        return ans;
    }
};