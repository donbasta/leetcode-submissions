struct DSU {
    vector<int> T, sz;
    vector<bool> stable;
    DSU(int n) {
        T.resize(n);
        iota(T.begin(), T.end(), 0);
        sz.assign(n, 1);
        stable.resize(n);
    }
    int fpar(int x) {
        return (x == T[x] ? x : T[x] = fpar(T[x]));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        T[y] = x;
        stable[x] = (stable[x] || stable[y]);
        sz[x] += sz[y];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        int sz = hits.size();
        vector<vector<int>> cur = grid;
        for (auto e : hits) {
            cur[e[0]][e[1]] = 0;
        }
        pair<int, int> dir[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        DSU dsu(m * n);
        for (int i = 0; i < n; i++) {
            dsu.stable[i] = true;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cur[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k].first, nj = j + dir[k].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (cur[ni][nj] == 0) continue;
                    dsu.merge(i * n + j, ni * n + nj);
                }
            }
        }
        vector<int> ret;
        for (int i = sz - 1; i >= 0; i--) {
            if (grid[hits[i][0]][hits[i][1]] == 0) {
                ret.push_back(0);
                continue;
            }
            int tmp = 0;
            bool stab = (hits[i][0] == 0);
            for (int k = 0; k < 4; k++) {
                int ni = hits[i][0] + dir[k].first, nj = hits[i][1] + dir[k].second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (cur[ni][nj] == 0) continue;
                if (dsu.stable[dsu.fpar(ni * n + nj)]) stab = true;
            }
            for (int k = 0; k < 4; k++) {
                int ni = hits[i][0] + dir[k].first, nj = hits[i][1] + dir[k].second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (cur[ni][nj] == 0) continue;
                if (dsu.fpar(hits[i][0] * n + hits[i][1]) == dsu.fpar(ni * n + nj)) continue;
                if (!dsu.stable[dsu.fpar(ni * n + nj)]) {
                    tmp += dsu.sz[dsu.fpar(ni * n + nj)];
                }
                dsu.merge(ni * n + nj, hits[i][0] * n + hits[i][1]);
            }
            cur[hits[i][0]][hits[i][1]] = 1;
            if (stab) {
                ret.push_back(tmp);
            } else {
                ret.push_back(0);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};