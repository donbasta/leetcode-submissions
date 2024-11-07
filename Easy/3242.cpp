class neighborSum {
public:
    vector<pair<int, int>> ve;
    int n;
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    vector<vector<int>> grid;
    neighborSum(vector<vector<int>>& grid) : grid(grid) {
        n = grid.size();
        ve.resize(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ve[grid[i][j]] = make_pair(i, j);
            }
        }
    }
    
    int adjacentSum(int value) {
        int px = ve[value].first, py = ve[value].second;
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i], ny = py + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            ret += grid[nx][ny];
        }
        return ret;
    }
    
    int diagonalSum(int value) {
        int px = ve[value].first, py = ve[value].second;
        int ret = 0;
        for (int i = 4; i < 8; i++) {
            int nx = px + dx[i], ny = py + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            ret += grid[nx][ny];
        }
        return ret;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */