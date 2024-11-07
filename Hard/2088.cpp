class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        int ans = 0;
        vector<vector<int>> lol(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1) {
                    lol[i][j] = (grid[i][j] == 1);
                } else {
                    if (grid[i][j] == 0) lol[i][j] = 0;
                    else {
                        if (j == 0 || j == n - 1) {
                            lol[i][j] = grid[i][j] == 1;
                        } else {
                            int mn = INF;
                            mn = min(mn, lol[i + 1][j]);
                            if (j > 0) mn = min(mn, lol[i + 1][j - 1]);
                            if (j < n - 1) mn = min(mn, lol[i + 1][j + 1]);
                            lol[i][j] = mn + 1;
                        }
                    }
                }
                ans += (lol[i][j] - 1) * (lol[i][j] > 0);
            }
        }
        // for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cout << i << ' ' << j << ' ' << lol[i][j] << '\n';
        // cout << ans << '\n';
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) lol[i][j] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    lol[i][j] = (grid[i][j] == 1);
                } else {
                    if (grid[i][j] == 0) lol[i][j] = 0;
                    else {
                        if (j == 0 || j == n - 1) {
                            lol[i][j] = grid[i][j] == 1;
                        } else {
                            int mn = INF;
                            mn = min(mn, lol[i - 1][j]);
                            if (j > 0) mn = min(mn, lol[i - 1][j - 1]);
                            if (j < n - 1) mn = min(mn, lol[i - 1][j + 1]);
                            lol[i][j] = mn + 1;
                        }
                    }
                }
                ans += (lol[i][j] - 1) * (lol[i][j] > 1);
            }
        }
        return ans;
    }
};