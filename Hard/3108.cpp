struct DSU {
    vector<int> par, ve;
    DSU (int n) : par(n), ve(n, (1 << 30) - 1) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int n) { return (n == par[n] ? n : par[n] = fpar(par[n])); }
    void merge(int a, int b) {
        a = fpar(a), b = fpar(b);
        if (a == b) return;
        par[a] = b;
        ve[b] &= ve[a];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto e : edges) {
            dsu.merge(e[0], e[1]);
            dsu.ve[dsu.fpar(e[0])] &= e[2];
        }
        vector<int> ret;
        for (auto q : query) {
            if (q[0] == q[1]) {
                ret.push_back(0);
            } else if (dsu.fpar(q[0]) != dsu.fpar(q[1])) {
                ret.push_back(-1);
            } else {
                ret.push_back(dsu.ve[dsu.fpar(q[0])]);
            }
        }
        return ret;
    }
};