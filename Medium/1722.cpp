struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) : n(_n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.assign(n + 1, 1);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x);
        y = fpar(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        par[y] = x;
        sz[x] += sz[y];
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        for (auto e : allowedSwaps) {
            dsu.merge(e[0], e[1]);
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[dsu.fpar(i)].push_back(i);
        }
        int same = 0;
        for (auto e : mp) {
            vector<int> idx = e.second;
            unordered_map<int, int> c1, c2;
            for (auto i : idx) {
                c1[source[i]]++;
                c2[target[i]]++;
            }
            for (auto e : c1) {
                same += min(e.second, c2[e.first]);
            }
        }
        return n - same;
    }
};