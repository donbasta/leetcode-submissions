struct DSU {
    vector<int> par, sz;
    DSU (int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    void clear() {
        iota(par.begin(), par.end(), 0);
        for (auto& e : sz) e = 1;
    }
    int fpar(int n) {
        if (n == par[n]) return n;
        return par[n] = fpar(par[n]);
    }
    bool merge(int a, int b) {
        int pa = fpar(a), pb = fpar(b);
        if (pa == pb) return false;
        par[pa] = pb;
        sz[pb] += sz[pa];
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        set<vector<int>> se;
        int idx = 0;
        for (auto e : edges) {
            se.insert({e[2], e[0], e[1], idx++});
        }
        int mst = 0;
        int tot = 0;
        DSU dsu(n);
        for (auto e : se) {
            if (!dsu.merge(e[1], e[2])) continue;
            tot++;
            mst += e[0];
            if (tot == n - 1) break;
        }
        vector<vector<int>> ret(2);
        if (tot < n - 1) return ret;
        idx = 0;
        for (auto e : edges) {
            se.erase(se.find({e[2], e[0], e[1], idx}));
            DSU dsu(n);

            int mst_check = 0;
            tot = 0;
            for (auto ee : se) {
                if (!dsu.merge(ee[1], ee[2])) continue;
                tot++;
                mst_check += ee[0];
                if (tot == n - 1) break;
            }
            int cc_size = dsu.sz[dsu.fpar(0)];
            if ((cc_size == n && mst_check > mst) || (cc_size < n)) {
                ret[0].push_back(idx);
                se.insert({e[2], e[0], e[1], idx++});
                continue;
            }

            mst_check = e[2];
            tot = 1;
            dsu.clear();
            dsu.merge(e[0], e[1]);
            for (auto ee : se) {
                if (!dsu.merge(ee[1], ee[2])) continue;
                tot++;
                mst_check += ee[0];
                if (tot == n - 1) break;
            }
            if (tot == n - 1 && mst_check == mst) ret[1].push_back(idx);
            se.insert({e[2], e[0], e[1], idx++});
        }

        return ret;
    }
};