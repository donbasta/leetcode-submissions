class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i <= min((m - 1) / 2, (n - 1) / 2); i++) {
            vector<pair<int, int>> layer;
            for (int j = i; j <= m - 1 - i; j++) {
                layer.emplace_back(j, i);
            }
            for (int j = i + 1; j <= n - 1 - i; j++) {
                layer.emplace_back(m - 1 - i, j);
            }
            for (int j = m - i - 2; j >= i; j--) {
                layer.emplace_back(j, n - 1 - i);
            }
            for (int j = n - 2 - i; j >= i + 1; j--) {
                layer.emplace_back(i, j);
            }
            int sz = layer.size();
            vector<pair<int, int>> now(sz);
            for (int i = 0; i < sz; i++) {
                int prv = (i - k) % sz;
                if (prv < 0) prv += sz;
                ret[layer[i].first][layer[i].second] = grid[layer[prv].first][layer[prv].second];
            }
        }
        return ret;
    }
};