class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt[2][3];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j) && (i <= n / 2)) cnt[0][grid[i][j]]++;
                else if ((i >= n / 2) && (j == n / 2)) cnt[0][grid[i][j]]++;
                else if ((i + j == n - 1) && (j >= n / 2)) cnt[0][grid[i][j]]++;
                else cnt[1][grid[i][j]]++;
            }
        }
        int cy = n + (n / 2);
        int ans = 2e9;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                int change_y = cy - cnt[0][i];
                int change_not_y = n * n - cy - cnt[1][j];
                ans = min(ans, change_y + change_not_y);
            }
        }
        return ans;
    }
};