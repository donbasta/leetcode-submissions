class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int row[m], col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        int M = 2e5;
        vector<pair<int, int>> val[2 * M + 1];
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                val[mat[i][j] + M].emplace_back(i, j);
                mx = max(mx, mat[i][j] + M);
                mn = min(mn, mat[i][j] + M);
            }
        }
        int ans = 1;
        for (int i = mx; i >= mn; i--) {
            if (val[i].empty()) continue;
            vector<pair<pair<int, int>, int>> q;
            for (auto c : val[i]) {
                int x = c.first, y = c.second;
                int tmp = 1 + max(row[x], col[y]);
                ans = max(ans, tmp);
                q.emplace_back(c, tmp);
            }
            for (auto qq : q) {
                row[qq.first.first] = max(row[qq.first.first], qq.second);
                col[qq.first.second] = max(col[qq.first.second], qq.second);
            }
        }
        return ans;
    }
};