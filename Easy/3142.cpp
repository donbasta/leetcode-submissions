class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < n; i++) {
            bool ok = true;
            if (i > 0) ok = (grid[0][i] != grid[0][i - 1]);
            for (int j = 0; j < m - 1; j++) {
                ok &= (grid[j][i] == grid[j + 1][i]);
            }
            if (!ok) return false;
        }
        return true;
    }
};