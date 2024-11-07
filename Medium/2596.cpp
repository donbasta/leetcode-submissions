class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = make_pair(i, j);
                // cout << grid[i][j] << '\t';
            }
            // cout << '\n';
        }
        if (pos[0] != make_pair(0, 0)) {
            return false;
        }
        vector<pair<int, int>> dir = {
            {1, 2},
            {1, -2},
            {-1, 2},
            {-1, -2},
            {2, 1},
            {-2, 1},
            {2, -1},
            {-2, -1}
        };
        int cx = pos[0].first, cy = pos[0].second;
        for (int i = 1; i < n * n; i++) {
            int nx = pos[i].first, ny = pos[i].second;
            bool ok = false;
            for (int j = 0; j < 8; j++) {
                int tx = cx + dir[j].first, ty = cy + dir[j].second;
                if ((nx == tx) && (ny == ty)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
            cx = nx, cy = ny;
        }
        return true;
    }
};