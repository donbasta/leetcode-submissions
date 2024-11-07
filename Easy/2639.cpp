class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i] = max(ret[i], (int)to_string(grid[j][i]).length());
            }
        }
        return ret;
    }
};