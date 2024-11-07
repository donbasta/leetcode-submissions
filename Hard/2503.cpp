struct DSU {
    vector<int> par, sz;
    DSU (int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    int fpar(int x) {
        return (par[x] == x ? x : (par[x] = fpar(par[x])));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int MX = 1e6;
        int sz[MX + 1];
        vector<pair<int, int>> pos[MX + 1];
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]].emplace_back(i, j);
            }
        }
        pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        DSU dsu(m * n);
        for (int i = 1; i <= MX; i++) {
            if (i > grid[0][0]) {
                sz[i] = dsu.sz[dsu.fpar(0)];
            } else {
                sz[i] = 0;
            }
            if (pos[i].empty()) continue;
            for (auto p : pos[i]) {
                for (int j = 0; j < 4; j++) {
                    int ni = p.first + dir[j].first, nj = p.second + dir[j].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (grid[ni][nj] > i) continue;
                    dsu.merge(p.first * n + p.second, ni * n + nj);
                }
            }
        }

        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(sz[q]);
        }
        return ans;
    }
};