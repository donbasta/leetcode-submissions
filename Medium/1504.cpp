class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> cnt(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i][j] = mat[i][j] + (j ? cnt[i][j - 1] : 0);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int st = -1, len = 0;
                for (int k = 0; k < m; k++) {
                    if (cnt[k][j] - (i ? cnt[k][i - 1] : 0) == (j - i + 1)) {
                        if (st == -1) st = k;
                        len++;
                    } else {
                        if (st != -1) {
                            int tot = k - st;
                            ans += tot * (tot + 1) / 2;
                        }
                        st = -1, len = 0;
                    }
                }
                if (st != -1) {
                    int tot = m - st;
                    ans += tot * (tot + 1) / 2;
                }
            }
        }

        return ans;
    }
};