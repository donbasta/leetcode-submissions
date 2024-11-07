class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int sh, int sw) {
        int h = grid.size();
        int w = grid[0].size();

        int p1[h][w], p2[h][w], ok[h][w];
        memset(ok, 0, sizeof(ok));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                p1[i][j] = grid[i][j];
                if (i) p1[i][j] += p1[i - 1][j];
                if (j) p1[i][j] += p1[i][j - 1];
                if (i > 0 && j > 0) p1[i][j] -= p1[i - 1][j - 1];
            }
        }
        
        auto g1 = [&](int a, int b, int c, int d) -> int {
            int ret = p1[c][d];
            if (a) ret -= p1[a - 1][d];
            if (b) ret -= p1[c][b - 1];
            if (a > 0 && b > 0) ret += p1[a - 1][b - 1];
            return ret;
        };

        auto g2 = [&](int a, int b, int c, int d) -> int {
            int ret = p2[c][d];
            if (a) ret -= p2[a - 1][d];
            if (b) ret -= p2[c][b - 1];
            if (a > 0 && b > 0) ret += p2[a - 1][b - 1];
            return ret;
        };

        for (int i = 0; i <= h - sh; i++) {
            for (int j = 0; j <= w - sw; j++) {
                if (g1(i, j, i + sh - 1, j + sw - 1) == 0) {
                    ok[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                p2[i][j] = ok[i][j];
                if (i) p2[i][j] += p2[i - 1][j];
                if (j) p2[i][j] += p2[i][j - 1];
                if (i > 0 && j > 0) p2[i][j] -= p2[i - 1][j - 1];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) continue;
                if (g2(max(0, i - sh + 1), max(0, j - sw + 1), i, j) == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};