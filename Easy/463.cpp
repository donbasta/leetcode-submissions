class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};