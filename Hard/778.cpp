class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        assert (m == n);
        vector<int> par(n * n);
        iota(par.begin(), par.end(), 0);
        const function<int(int)> fpar = [&](int v) -> int {
            if (par[v] == v) return v;
            return par[v] = fpar(par[v]);
        };
        const function<void(int, int)> merge = [&](int v, int w) -> void {
            v = fpar(v), w = fpar(w);
            par[v] = w;
        };
        vector<int> pos(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = i * n + j;
            }
        }
        vector<bool> basah(n * n);
        for (int i = 0; i < n * n; i++) {
            int cur = pos[i];
            int atas = cur - n, bawah = cur + n, kiri = cur - 1, kanan = cur + 1;
            if (atas >= 0 && basah[fpar(atas)]) {
                merge(atas, cur);
            }
            if (bawah < n * n && basah[fpar(bawah)]) {
                merge(bawah, cur);
            }
            if (kiri >= 0 && basah[fpar(kiri)] && (kiri / n == cur / n)) {
                merge(kiri, cur);
            }
            if (kanan < n * n && basah[fpar(kanan)] && (kanan / n == cur / n)) {
                merge(kanan, cur);
            }
            if (fpar(0) == fpar(n * n - 1)) {
                return i;
            }
            basah[fpar(cur)] = true;
        } 
        return -1;
    }
};