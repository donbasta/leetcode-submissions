class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int res = grid[0][0] % x;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != res) return -1;
                grid[i][j] /= x;
            }
        }
        int l = 0, r = 1e4;
        const function<int(int)> f = [&](int pivot) -> int {
            int res = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res += abs(pivot - grid[i][j]);
                }
            }
            return res;
        };
        while (r - l >= 3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            int f1 = f(m1);
            int f2 = f(m2);
            if (f1 > f2) {
                l = m1 + 1;
            } else {
                r = m2;
            }
            // cout << l << ' ' << r << '\n';
        }
        const int INF = 2e9;
        int mn = INF;
        for (; l <= r; l++) {
            mn = min(mn, f(l));
        }
        return mn;
    }
};