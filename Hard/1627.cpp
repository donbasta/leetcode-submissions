struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    int fpar(int x) {
        if (x == par[x]) return x;
        return par[x] = fpar(par[x]);
    }
    void merge(int x, int y) {
        int px = fpar(x), py = fpar(y);
        if (px == py) return;
        if (sz[px] < sz[py]) swap(px, py);
        par[py] = px;
        sz[px] += sz[py]; 
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n + 1);
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                dsu.merge(j, i);
            }
        }
        vector<bool> ret;
        for (auto q : queries) {
            ret.push_back(dsu.fpar(q[0]) == dsu.fpar(q[1]));
        }
        return ret;
    }
};