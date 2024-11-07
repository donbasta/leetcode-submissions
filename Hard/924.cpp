struct DSU {
    int n;
    vector<int> par, val;
    DSU(int n) : n(n), par(n), val(n, 0) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) { return x == par[x] ? x : par[x] = fpar(par[x]); }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        par[x] = y;
        val[y] |= val[x];
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        int mn = 2e9;
        int idx = -1;
        for (int i = 0; i < initial.size(); i++) {
            DSU dsu(n);
            for (auto e : initial) {
                if (e == initial[i]) continue;
                dsu.val[e] = 1;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (graph[i][j] == 1) {
                        dsu.merge(i, j);
                    }
                }
            }
            int infected = 0;
            for (int i = 0; i < n; i++) {
                if (dsu.val[dsu.fpar(i)] == 1) infected++;
            }
            // cout << infected << ' ' << initial[i] << '\n';
            if (infected < mn) {
                mn = infected, idx = initial[i];
            } else if (infected == mn) {
                idx = min(idx, initial[i]);
            }
        }
        return idx;
    }
};