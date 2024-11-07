class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int A[m][n], B[m][n];
        memset(A, 0, sizeof(A)), memset(B, 0, sizeof(B));
        A[0][0] = B[m - 1][n - 1] = 1;
        const int MOD = 1e9 + 9;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (grid[i][j] == 0) continue;
                if (i) A[i][j] = (A[i][j] + A[i - 1][j]) % MOD;
                if (j) A[i][j] = (A[i][j] + A[i][j - 1]) % MOD;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                if (grid[i][j] == 0) continue;
                if (i < m - 1) B[i][j] = (B[i][j] + B[i + 1][j]) % MOD;
                if (j < n - 1) B[i][j] = (B[i][j] + B[i][j + 1]) % MOD;
            }
        }
        int cek = A[m - 1][n - 1];
        assert(B[0][0] == cek);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == m - 1 && j == n - 1) continue;
                int lol = (1ll * A[i][j] * B[i][j]) % MOD;
                if (lol == cek) {
                    return true;
                }
            }
        }
        return false;
    }
};