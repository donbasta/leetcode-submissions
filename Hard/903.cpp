class Solution {
public:
    const int MOD = 1e9 + 7;
    inline void norm(int& x) {
        if (x >= MOD) x -= MOD;
        if (x < 0) x += MOD;
    }

    int numPermsDISequence(string s) {
        int n = s.length();
        int dp[n + 1][n + 2];
        int pre[n + 2];

        dp[0][1] = 1;
        pre[0] = 0;
        pre[1] = 1;
        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            if (ch == 'D') {
                for (int j = 1; j <= i + 1; j++) {
                    dp[i][j] = (pre[i] - pre[j - 1]);
                    norm(dp[i][j]);
                }
            } else {
                for (int j = 1; j <= i + 1; j++) {
                    dp[i][j] = pre[j - 1];
                }
            }
            for (int j = 1; j <= i + 1; j++) {
                pre[j] = (pre[j - 1] + dp[i][j]);
                norm(pre[j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n + 1; i++) {
            ans = (ans + dp[n][i]);
            norm(ans);
        }
        return ans;
    }
};