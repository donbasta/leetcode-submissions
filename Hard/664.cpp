class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 1) return 1;
        int dp[n][n];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = 1 + (s[i] != s[i + 1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int tmp = INT_MAX;
                if (s[i] == s[j]) tmp = dp[i][j - 1];
                else {
                    tmp = 1 + dp[i][j - 1];
                    for (int k = i + 1; k <= j - 1; k++) {
                        if (s[k] == s[j]) tmp = min(tmp, dp[i][k - 1] + dp[k][j - 1]);
                    }
                }
                dp[i][j] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};