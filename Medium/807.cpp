class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRow(n), maxCol(n);
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp = max(tmp, grid[i][j]);
            }
            maxRow[i] = tmp;
        }
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp = max(tmp, grid[j][i]);
            }
            maxCol[i] = tmp;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += min(maxRow[i], maxCol[j]) - grid[i][j];
            }
        }

        return ans;
    }
};