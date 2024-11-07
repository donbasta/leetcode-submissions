struct DSU {
    vector<int> par;
    vector<bool> ok1, ok2;
    DSU(int n) {
        par.resize(n);
        ok1.resize(n);
        ok2.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        par[y] = x;
        ok1[x] = ok1[x] || ok1[y];
        ok2[x] = ok2[x] || ok2[y];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> T(row, vector<int>(col));
        for (auto e : cells) T[e[0] - 1][e[1] - 1] = 1;
        DSU dsu(row * col);
        for (int i = 0; i < col; i++) {
            dsu.ok1[i] = true;
            dsu.ok2[(row - 1) * col + i] = true;
        }

        pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (T[i][j] == 1) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k].first, nj = j + dir[k].second;
                    if (ni < 0 || ni >= row || nj < 0 || nj >= col) continue;
                    if (T[ni][nj] == 1) continue;
                    dsu.merge(i * col + j, ni * col + j);
                }
            }
        }
        int sz = cells.size();
        for (int i = sz - 1; i >= 0; i--) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k].first, ny = y + dir[k].second;
                if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if (T[nx][ny] == 1) continue;
                dsu.merge(x * col + y, nx * col + ny);
            }
            if (dsu.ok1[dsu.fpar(x * col + y)] && dsu.ok2[dsu.fpar(x * col + y)]) {
                return i;
            }
            T[x][y] = 0;
        }
        return 0;
    }
};