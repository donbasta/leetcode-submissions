class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<int> rp(m), prp(m), srp(m);
        vector<vector<int>> p(m, vector<int>(n)), s(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            int lmao = 1;
            for (int j = 0; j < n; j++) {
                lmao = (1ll * lmao * grid[i][j]) % MOD;
            }
            rp[i] = lmao;
        } 
        prp[0] = rp[0];
        for (int i = 1; i < m; i++) {
            prp[i] = (1ll * prp[i - 1] * rp[i]) % MOD;
        }
        srp[m - 1] = rp[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            srp[i] = (1ll * srp[i + 1] * rp[i]) % MOD;
        }
        for (int i = 0; i < m; i++) {
            p[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                p[i][j] = (1ll * p[i][j - 1] * grid[i][j]) % MOD;
            }
            s[i][n - 1] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                s[i][j] = (1ll * s[i][j + 1] * grid[i][j]) % MOD;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tot = 1;
                if (i > 0) tot = (1ll * tot * prp[i - 1]) % MOD;
                if (i < m - 1) tot = (1ll * tot * srp[i + 1]) % MOD;
                if (j > 0) tot = (1ll * tot * p[i][j - 1]) % MOD;
                if (j < n - 1) tot = (1ll * tot * s[i][j + 1]) % MOD;
                res[i][j] = tot;
            }
        }
        return res;
    }
};