int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int rec(pair<int, int> pos, pair<int, int> end, int rem, vector<vector<int>>& G, vector<vector<bool>>& V) {
        if (pos == end) {
            if (rem == 0) return 1;
            else return 0;
        }
        int m = G.size(), n = G[0].size();
        int cx = pos.first, cy = pos.second;
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (G[nx][ny] == -1) continue;
            if (V[nx][ny]) continue;
            V[nx][ny] = true;
            rem--;
            ans += rec(make_pair(nx, ny), end, rem, G, V);
            rem++;
            V[nx][ny] = false;
        }
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> start, end;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int rem = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) 
            if (grid[i][j] == 1) { start = make_pair(i, j); }
            else if (grid[i][j] == 0) { rem++; }
            else if (grid[i][j] == 2) { end = make_pair(i, j); }
        vis[start.first][start.second] = true;
        return rec(start, end, rem + 1, grid, vis);
    }
};