struct DSU {
    vector<int> p;
    DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int fpar(int n) { return n == p[n] ? n : p[n] = fpar(p[n]); }
    void merge(int x, int y) {  
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        p[x] = y;
    }
};

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        DSU dsu(n + 4);
        for (int i = 0; i < n; i++) {
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (abs(Y - y) <= r) dsu.merge(i, n);
            if (abs(x) <= r) dsu.merge(i, n + 1);
            if (abs(y) <= r) dsu.merge(i, n + 2);
            if (abs(X - x) <= r) dsu.merge(i, n + 3);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
                int x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
                int dx = x1 - x2, dy = y1 - y2;
                if (1ll * dx * dx + 1ll * dy * dy <= 1ll * (r1 + r2) * (r1 + r2)) {
                    dsu.merge(i, j);
                }
            }
        }
        if (dsu.fpar(n) == dsu.fpar(n + 2) || dsu.fpar(n) == dsu.fpar(n + 3) || dsu.fpar(n + 1) == dsu.fpar(n + 3) || dsu.fpar(n + 1) == dsu.fpar(n + 2)) return false;
        return true;
    }
};