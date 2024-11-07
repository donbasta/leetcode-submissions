struct DSU {
    vector<int> par, sz;
    DSU(int n) : par(n + 1), sz(n + 1, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    bool merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return false;
        if (sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edges_by_type[4];
        for (auto e : edges) {
            edges_by_type[e[0]].push_back(vector<int>{e[1], e[2]});
        }
        DSU d1(n), d2(n);
        int ret = 0;
        for (auto e : edges_by_type[3]) {
            if (!d1.merge(e[0], e[1])) {
                ret++;
            }
            d2.merge(e[0], e[1]);
        }
        for (auto e : edges_by_type[1]) {
            if (!d1.merge(e[0], e[1])) ret++;
        }
        for (auto e : edges_by_type[2]) {
            if (!d2.merge(e[0], e[1])) ret++;
        }
        if (d1.sz[d1.fpar(1)] != n || d2.sz[d1.fpar(1)] != n) {
            return -1;
        }
        return ret;
    }
};