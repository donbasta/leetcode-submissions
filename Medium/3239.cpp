class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t1 = 0, t2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                t1 += grid[i][j] != grid[i][n - 1 - j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                t2 += grid[j][i] != grid[m - 1 - j][i];
            }
        }
        
        return min(t1, t2);
    }
};