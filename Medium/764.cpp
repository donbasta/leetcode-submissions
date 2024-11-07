class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int u[n][n], d[n][n], l[n][n], r[n][n], grid[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1;
                u[i][j] = -1, d[i][j] = n, l[i][j] = -1, r[i][j] = n;  
            }
        }
        for (auto e : mines) {
            grid[e[0]][e[1]] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (i > 0) {
                    if (grid[i - 1][j] == 0) u[i][j] = i;
                    else u[i][j] = u[i - 1][j];
                } else {
                    u[i][j] = i;
                }
                if (j > 0) {
                    if (grid[i][j - 1] == 0) l[i][j] = j;
                    else l[i][j] = l[i][j - 1];
                } else {
                    l[i][j] = j;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                if (i < n - 1) {
                    if (grid[i + 1][j] == 0) d[i][j] = i;
                    else d[i][j] = d[i + 1][j];
                } else {
                    d[i][j] = i;
                }
                if (j < n - 1) {
                    if (grid[i][j + 1] == 0) r[i][j] = j;
                    else r[i][j] = r[i][j + 1];
                } else {
                    r[i][j] = j;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int lu = (i - u[i][j] + 1);
                int ld = (d[i][j] - i + 1);
                int ll = (j - l[i][j] + 1);
                int lr = (r[i][j] - j + 1);
                // cout << i << ' ' << j << ' ' << lu << ' ' << ld << ' ' << ll << ' ' << lr << '\n';
                ans = max(ans, min({lu, ld, ll, lr}));
            }
        }
        return ans;
    }
};