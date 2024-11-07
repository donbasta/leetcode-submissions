class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2e9;
        vector<vector<int>> mn(m, vector<int>(n, INF));
        int ans = -INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int oth = INF;
                if (i > 0) oth = min(oth, mn[i - 1][j]);
                if (j > 0) oth = min(oth, mn[i][j - 1]);
                if ((i > 0) || (j > 0)) {
                    ans = max(ans, grid[i][j] - oth);
                }
                mn[i][j] = min(oth, grid[i][j]);
            }
        }
        return ans;
    }
};