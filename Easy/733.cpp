class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ret = image;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        vector<vector<bool>> vis(m, vector<bool>(n));
        function<void(int, int)> ff = [&](int r, int c) {
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (image[nr][nc] != image[r][c]) continue;
                if (vis[nr][nc]) continue;
                ret[nr][nc] = color;
                vis[nr][nc] = true;
                ff(nr, nc);
            }
        };

        vis[sr][sc] = true;
        ret[sr][sc] = color;
        ff(sr, sc);
        return ret;
    }
};