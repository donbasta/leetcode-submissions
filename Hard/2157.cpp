struct DSU {
    vector<int> par, sz;
    int n;
    DSU(int n) : n(n), par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int v) {
        return (v == par[v] ? v : par[v] = fpar(par[v]));
    }
    void merge(int v, int w) {
        v = fpar(v), w = fpar(w);
        if (v == w) return;
        if (sz[v] > sz[w]) swap(v, w);
        par[v] = w;
        sz[w] += sz[v];
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        unordered_map<int, int> mp;
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            int freq = 0;
            for (auto c : words[i]) freq ^= (1 << (c - 'a'));
            if (mp.count(freq)) {
                dsu.merge(i, mp[freq]);
                continue;
            }
            for (int j = 0; j < 26; j++) {
                if (!((freq >> j) & 1)) {
                    freq ^= (1 << j);
                    if (mp.count(freq)) {
                        dsu.merge(i, mp[freq]);
                    }
                    freq ^= (1 << j);
                }
                if ((freq >> j) & 1) {
                    freq ^= (1 << j);
                    if (mp.count(freq)) {
                        dsu.merge(i, mp[freq]);
                    }
                    freq ^= (1 << j);
                    for (int k = 0; k < 26; k++) {
                        if (k == j) continue;
                        if ((freq >> k) & 1) continue;
                        freq ^= (1 << j);
                        freq ^= (1 << k);
                        if (mp.count(freq)) {
                            dsu.merge(i, mp[freq]);
                        }
                        freq ^= (1 << j);
                        freq ^= (1 << k);
                    }
                }
            }
            mp[freq] = i;
        }
        int gr = 0, sz = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.fpar(i) == i) {
                gr++;
                sz = max(sz, dsu.sz[i]);
            }
        }
        return vector<int>{gr, sz};
    }
};