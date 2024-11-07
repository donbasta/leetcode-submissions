class Solution {
public:
    int numberOfCombinations(string num) {
        if (num[0] == '0') return 0;
        int n = num.length();
        const int MOD = 1e9 + 7;
        int pre[n][n];
        memset(pre, 0, sizeof(pre));
        int pf[n + 1][n + 1];
        memset(pf, 0, sizeof(pf));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (num[i] == num[j]) {
                    pf[i][j] = 1 + pf[i + 1][j + 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int tmp[n];
            tmp[0] = 1;
            for (int j = 1; j <= i; j++) {
                if (num[j] == '0') {
                    tmp[j] = 0;
                    continue;
                }
                int len = i - j + 1;
                tmp[j] = (pre[j - 1][j - 1] - ((j >= len) ? pre[j - 1][j - len] : 0)) % MOD;
                if (j >= len) {
                    if ((pf[j - len][j] >= len) || num[j - len + pf[j - len][j]] < num[j + pf[j - len][j]]) {
                        tmp[j] = (pre[j - 1][j - 1] - ((j >= len + 1) ? pre[j - 1][j - len - 1] : 0)) % MOD;
                    }
                } 
            }
            pre[i][0] = tmp[0];
            for (int j = 1; j <= i; j++) {
                pre[i][j] = (pre[i][j - 1] + tmp[j]) % MOD;
            }
        }

        int ans = pre[n - 1][n - 1];
        if (ans < 0) ans += MOD;
        return ans;
    }
};