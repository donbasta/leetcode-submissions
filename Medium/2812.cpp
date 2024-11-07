struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        if (x == par[x]) return x;
        return par[x] = fpar(par[x]);
    }
    void merge(int x, int y) {
        int px = fpar(x), py = fpar(y);
        if (px == py) return;
        par[px] = py;
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (n == 1) return 0;
        queue<pair<int, int>> Q;
        vector<vector<int>> dis(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    Q.emplace(i, j);
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.first + dir[i].first;
                int ny = now.second + dir[i].second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (vis[nx][ny]) continue;
                dis[nx][ny] = dis[now.first][now.second] + 1;
                vis[nx][ny] = true;
                Q.emplace(nx, ny);
            }
        }
        vector<vector<int>> lmao(m + n + 5);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                lmao[dis[i][j]].push_back(i * n + j);
            }
        }
        
        DSU dsu(m * n);
        vector<vector<bool>> on(m, vector<bool>(n));
        for (int i = m + n; i >= 1; i--) {
            for (auto e : lmao[i]) {
                int x = e / n, y = e % n;
                on[x][y] = true;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dir[k].first, ny = y + dir[k].second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (!on[nx][ny]) continue;
                    dsu.merge(e, nx * n + ny);
                }
            }
            if (dsu.fpar(0) == dsu.fpar(m * n - 1)) return i;
        }
        return 0;
        
        
        
    }
};