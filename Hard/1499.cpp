class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<int> ar(n), x(n), y(n);
        for (int i = 0; i < n; i++) {
            x[i] = points[i][0];
            y[i] = points[i][1];
            ar[i] = y[i] - x[i];
        }
        vector<int> log(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        vector<vector<int>> st(n + 1, vector<int>(log[n] + 1));
        for (int i = 0; i < n; i++) {
            st[i][0] = ar[i];
        }
        for (int j = 1; j <= log[n]; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        const auto getMax = [&](int l, int r) -> int {
            int j = log[r - l + 1];
            return max(st[l][j], st[r - (1 << j) + 1][j]);
        };
        int ans = -2e9;
        for (int i = 1; i < n; i++) {
            int lb = lower_bound(x.begin(), x.end(), x[i] - k) - x.begin();
            if (lb >= i) continue;
            ans = max(ans, x[i] + y[i] + getMax(lb, i - 1));
        }
        return ans;
    }
};