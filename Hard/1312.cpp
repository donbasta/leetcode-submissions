class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        const int INF = 2e9;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len < n; i++) {
                int tmp = 0;
                tmp = min(1 + dp[i][i + len - 1], 1 + dp[i + 1][i + len]);
                if (s[i] == s[i + len]) {
                    tmp = min(tmp, dp[i + 1][i + len - 1]);
                }
                dp[i][i + len] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};