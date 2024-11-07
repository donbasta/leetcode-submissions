struct DSU {
    int n;
    vector<int> par;
    DSU(int n) : n(n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int v) {
        if (v == par[v]) return v;
        return par[v] = fpar(par[v]);
    }
    void merge(int a, int b) {
        a = fpar(a), b = fpar(b);
        if (a == b) return;
        par[a] = b;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = 0;
                for (int k = 0; k < len; k++) {
                    if (strs[i][k] != strs[j][k]) diff++;
                }
                if (diff <= 2) dsu.merge(i, j);
            }
        }
        int group = 0;
        for (int i = 0; i < n; i++) {
            if (i == dsu.fpar(i)) group++;
        }
        return group;
    }
};