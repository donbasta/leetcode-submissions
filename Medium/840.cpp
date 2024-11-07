class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                int r1 = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1];
                int r2 = grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
                int r3 = grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                int c1 = grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1];
                int c2 = grid[i - 1][j] + grid[i][j] + grid[i + 1][j];
                int c3 = grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1];
                int d1 = grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
                int d2 = grid[i + 1][j - 1] + grid[i][j] + grid[i - 1][j + 1];
                if (r2 != r1 || r3 != r1 || c1 != r1 || c2 != r1 || c3 != r1 || d1 != r1 || d2 != r1) continue;
                set<int> se;
                for (int kk = i - 1; kk <= i + 1; kk++) for (int ll = j - 1; ll <= j + 1; ll++) se.insert(grid[kk][ll]);
                if (se.size() < 9 || *se.begin() != 1 || *se.rbegin() != 9) continue;
                ans++;
            }
        }
        return ans;
    }
};