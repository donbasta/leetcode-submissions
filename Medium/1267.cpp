class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> pos;
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans++;
                    row[i]++, col[j]++;
                    pos.emplace_back(i, j);
                }
            }
        }
        for (auto e : pos) {
            if (row[e.first] == 1 && col[e.second] == 1) ans--;
        }
        return ans;
    }
};