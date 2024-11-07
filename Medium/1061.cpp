struct DSU {
    vector<int> par;
    DSU(int n) : par(n + 1) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    bool merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return false;
        if (x < y) swap(x, y);
        par[x] = y;
        return true;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        DSU dsu(26);
        for (int i = 0; i < n; i++) {
            dsu.merge(s1[i] - 'a', s2[i] - 'a');
        }
        string ret = baseStr;
        for (auto& c : ret) {
            c = dsu.fpar(c - 'a') + 'a';
        }
        return ret;
    }
};