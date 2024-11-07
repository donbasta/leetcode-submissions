class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = (s[i] == s[i + 1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                if (s[i] == s[i + len - 1]) dp[i][i + len - 1] = dp[i + 1][i + len - 2];
            }
        }
        for (int len = n; len >= 2; len--) {
            for (int i = 0; i + len - 1 < n; i++) {
                if (dp[i][i + len - 1]) return s.substr(i, len);
            }
        }
        return s.substr(0, 1);
    }
};