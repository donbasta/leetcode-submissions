class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += grid[i][j] == 1;
                col[j] += grid[i][j] == 1;
            }
        }
        // for (int i = 0; i < m; i++) cout << row[i] << ' ';
        // cout << '\n';
        // for (int i = 0; i < n; i++) cout << col[i] << ' ';
        using ll = long long;
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                ans += 1ll * (row[i] - 1) * (col[j] - 1);
            }
        }
        return ans;
    }
};