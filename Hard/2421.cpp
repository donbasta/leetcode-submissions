struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n + 1);
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int MX = 1e5;
        vector<vector<pair<int, int>>> from(MX + 1);
        for (auto e : edges) {
            int a = e[0], b = e[1];
            if (vals[a] > vals[b]) swap(a, b);
            from[vals[b]].emplace_back(make_pair(b, a));
        }

        int n = vals.size();
        vector<vector<int>> nodes(MX + 1);
        for (int i = 0; i < n; i++) {
            nodes[vals[i]].push_back(i);
        } 
        
        DSU dsu(n);

        int ret = 0;
        for (int i = 0; i <= MX; i++) {
            for (auto t : from[i]) {
                dsu.merge(t.first, t.second);
            }
            unordered_map<int, int> cnt;
            for (auto e : nodes[i]) {
                cnt[dsu.fpar(e)]++;
            }
            for (auto e : cnt) {
                ret += e.second * (e.second + 1) / 2;
            }
        }
        return ret;
    }
};