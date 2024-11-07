class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        if (n <= 2) return n;
        int dp[n][n];
        int nx[n][4], prv[n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (i > 0) prv[i][j] = prv[i - 1][j];
                else prv[i][j] = -1;
            }
            prv[i][s[i] - 'a'] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (i < n - 1) nx[i][j] = nx[i + 1][j];
                else nx[i][j] = n;
            }
            nx[i][s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = 2;
        const int MOD = 1e9 + 7;
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) { //dp[i][i + len - 1]
                int cur = s[i + len - 1] - 'a';
                int tmp = dp[i][i + len - 2];
                int i1 = nx[i][cur];
                int i2 = prv[i + len - 2][cur];
                if (i1 >= i + len - 1) {
                    tmp = (tmp + 1) % MOD;
                } else if (i1 == i2) {
                    tmp = (tmp + 1) % MOD;
                    if (i1 + 1 <= i + len - 2) {
                        tmp = (tmp + dp[i1 + 1][i + len - 2]) % MOD;
                    }
                } else {
                    tmp = (tmp + dp[i1 + 1][i + len - 2]) % MOD;
                    if (i1 + 1 <= i2 - 1) {
                        tmp = (tmp - dp[i1 + 1][i2 - 1]) % MOD;
                    }
                }
                if (tmp < 0) tmp += MOD;
                dp[i][i + len - 1] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};