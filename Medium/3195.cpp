class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = INT_MAX, r = INT_MIN, u = INT_MIN, d = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    r = max(r, j);
                    u = max(u, i);
                    d = min(d, i);
                }
            }
        }
        return (u - d + 1) * (r - l + 1);
    }
};