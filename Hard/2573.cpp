struct DSU {
    vector<int> par;
    DSU (int n) : par(n) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) { return x == par[x] ? x : par[x] = fpar(par[x]); }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        par[x] = y;
    }
};

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        DSU dsu(n);
        string emp;

        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return emp;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return emp;
                if (lcp[i][j] > 0) {
                    if (lcp[i][j] > n - max(i, j)) {
                        return emp;
                    }
                    if (i + 1 < n && j + 1 < n && lcp[i + 1][j + 1] != lcp[i][j] - 1) {
                        return emp;
                    }
                    dsu.merge(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] == 0 && dsu.fpar(i) == dsu.fpar(j)) {
                    return emp;
                }
            }
        }
        vector<int> ve(n, -1);
        string ret;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            int p = dsu.fpar(i);
            if (ve[p] == -1) {
                ve[p] = ptr++;
                if (ptr > 26) {
                    return emp;
                }
            }
            ret.push_back((char)(ve[p] + 'a'));
        }
        return ret;
    }
};