struct DSU {
    vector<int> par;
    vector<int> sz;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    int get(int x) {
        return (par[x] == x ? x : (par[x] = get(par[x])));
    }
    void merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        DSU dsu(m * n);
        vector<int> from[m * n];
        int in[m * n];
        memset(in, 0, sizeof(in));
        for (int i = 0; i < m; i++) {
            pair<int, int> tmp[n];
            for (int j = 0; j < n; j++) tmp[j] = make_pair(matrix[i][j], i * n + j);
            sort(tmp, tmp + n);
            int last = tmp[0].first;
            int id = tmp[0].second;
            for (int j = 1; j < n; j++) {
                if (tmp[j].first == last) {
                    dsu.merge(tmp[j].second, id);
                } else {
                    last = tmp[j].first;
                    id = tmp[j].second;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            pair<int, int> tmp[m];
            for (int i = 0; i < m; i++) tmp[i] = make_pair(matrix[i][j], i * n + j);
            sort(tmp, tmp + m);
            int last = tmp[0].first;
            int id = tmp[0].second;
            for (int i = 0; i < m; i++) {
                if (tmp[i].first == last) {
                    dsu.merge(tmp[i].second, id);
                } else {
                    last = tmp[i].first;
                    id = tmp[i].second;
                }
            }
        }
        int par[m][n];
        memset(par, 0, sizeof(par));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                par[i][j] = dsu.get(i * n + j);
            }
        }
        for (int i = 0; i < m; i++) {
            pair<int, int> tmp[n];
            for (int col = 0; col < n; col++) tmp[col] = make_pair(matrix[i][col], par[i][col]);
            sort(tmp, tmp + n);
            for (int i = 1; i < n; i++) {
                if (tmp[i].second == tmp[i - 1].second) continue;
                from[tmp[i - 1].second].push_back(tmp[i].second);
                in[tmp[i].second]++;
            }
        }
        for (int j = 0; j < n; j++) {
            pair<int, int> tmp[m];
            for (int row = 0; row < m; row++) tmp[row] = make_pair(matrix[row][j], par[row][j]);
            sort(tmp, tmp + m);
            for (int i = 1; i < m; i++) {
                if (tmp[i].second == tmp[i - 1].second) continue;
                from[tmp[i - 1].second].push_back(tmp[i].second);
                in[tmp[i].second]++;
            }
        }
        queue<int> Q;
        bool vis[m * n];
        memset(vis, false, sizeof(vis));
        int val[m * n];
        memset(val, 0, sizeof(val));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = par[i][j];
                if (in[cur] == 0) {
                    if (vis[cur]) continue;
                    vis[cur] = true;
                    val[cur] = 1;
                    Q.push(cur);
                }
            }
        }
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto e : from[now]) {
                val[e] = max(val[e], val[now] + 1);
                --in[e];
                if (in[e] == 0) {
                    Q.push(e);
                }
            }
        }
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = val[par[i][j]];
            }
        }
        return ret;
    }
};