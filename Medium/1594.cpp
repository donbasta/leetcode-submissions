class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        using ll = long long;
        int m = grid.size(), n = grid[0].size();
        ll D[m][n], E[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ll a = LLONG_MIN, b = LLONG_MAX;
                if (i == 0 && j == 0) {
                    a = b = grid[i][j];
                }
                if (i > 0) {
                    a = max(a, 1ll * grid[i][j] * D[i - 1][j]);
                    a = max(a, 1ll * grid[i][j] * E[i - 1][j]);
                    b = min(b, 1ll * grid[i][j] * D[i - 1][j]);
                    b = min(b, 1ll * grid[i][j] * E[i - 1][j]);
                }
                if (j > 0) {
                    a = max(a, 1ll * grid[i][j] * D[i][j - 1]);
                    a = max(a, 1ll * grid[i][j] * E[i][j - 1]);
                    b = min(b, 1ll * grid[i][j] * D[i][j - 1]);
                    b = min(b, 1ll * grid[i][j] * E[i][j - 1]);
                }
                D[i][j] = a, E[i][j] = b;
            }
        }
        if (D[m - 1][n - 1] < 0) return -1;
        const ll MOD = 1e9 + 7;
        return (D[m - 1][n - 1] % (MOD));
    }
};