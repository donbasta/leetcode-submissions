class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pre(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i][j] = mat[i][j];
                if (i) pre[i][j] += pre[i - 1][j];
                if (j) pre[i][j] += pre[i][j - 1];
                if ((i > 0) && (j > 0)) pre[i][j] -= pre[i - 1][j - 1];
            }
        }
        auto get = [&](int p, int q, int side) -> int {
            int ret = pre[p + side - 1][q + side - 1];
            if (p) ret -= pre[p - 1][q + side - 1];
            if (q) ret -= pre[p + side - 1][q - 1];
            if ((p > 0) && (q > 0)) ret += pre[p - 1][q - 1];
            return ret;
        };

        int ans = 0;
        int l = 1, r = min(m, n);
        while (l <= r) {
            int mid = (l + r) >> 1;
            bool ok = false;
            for (int j = 0; j + mid - 1 < m; j++) {
                for (int k = 0; k + mid - 1 < n; k++) {
                    if (get(j, k, mid) <= threshold) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};