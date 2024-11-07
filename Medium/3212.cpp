class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> px(m, vector<int>(n));
        vector<vector<int>> py(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                px[i][j] = (grid[i][j] == 'X');
                py[i][j] = (grid[i][j] == 'Y');
                if (i) {
                    px[i][j] += px[i - 1][j], py[i][j] += py[i - 1][j];
                }
                if (j) {
                    py[i][j] += py[i][j - 1], px[i][j] += px[i][j - 1];
                }
                if ((i > 0) && (j > 0)) {
                    px[i][j] -= px[i - 1][j - 1], py[i][j] -= py[i - 1][j - 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (px[i][j] == py[i][j] && px[i][j] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};