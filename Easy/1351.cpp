class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x = 0, y = n - 1;
        int ans = 0;
        while (x < m) {
            if (y < 0) {
                ans += n;
                x++;
                continue;
            }
            while (x < m && grid[x][y] >= 0) {
                x++;
                ans += (n - y - 1);
            }
            if (x < m) {
                ans += (n - y - 1);
                while (y >= 0 && grid[x][y] < 0) {
                    y--, ans++;
                }
                x++;
            }
            // cout << x << ' ' << y << ' ' << ans << '\n';
        }
        return ans;
    }
};