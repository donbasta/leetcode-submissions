class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) dp[i][i] = 1; 
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = (s[i] == s[i + 1] ? 2 : 1);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                dp[i][i + len - 1] = max(dp[i][i + len - 2], dp[i + 1][i + len - 1]);
                if (s[i] == s[i + len - 1]) dp[i][i + len - 1] = max(dp[i][i + len - 1], 2 + dp[i + 1][i + len - 2]);
            }
        }
        return dp[0][n - 1];
    }
};