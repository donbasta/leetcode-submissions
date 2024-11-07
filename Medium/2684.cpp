class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int> dp(m, 1);

        int n = grid[0].size();
        int ret = 1;
        for (int i = 1; i < n; i++) {
            vector<int> ndp(m, -1);
            for (int j = 0; j < m; j++) {
                for (int prv = max(0, j - 1); prv <= min(m - 1, j + 1); prv++) {
                    if (grid[j][i] <= grid[prv][i - 1]) continue;
                    if (dp[prv] == -1) continue;
                    ndp[j] = max(ndp[j], dp[prv] + 1);
                }
            }
            dp.swap(ndp);
            ret = max(ret, *max_element(dp.begin(), dp.end()));
        }
        return ret - 1;
    }
};