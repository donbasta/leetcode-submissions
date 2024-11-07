class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = s[i] == s[i + 1];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                dp[i][i + len - 1] = (dp[i + 1][i + len - 2] && (s[i] == s[i + len - 1]));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};