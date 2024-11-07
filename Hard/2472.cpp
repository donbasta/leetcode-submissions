class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1);
        vector<vector<bool>> pal(n + 1, vector<bool>(n + 1));
        for (int i = 1; i <= n; i++) {
            pal[i][i] = true;
        }
        for (int i = 1; i <= n - 1; i++) {
            if (s[i - 1] == s[i]) pal[i][i + 1] = true;
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                pal[i][i + len - 1] = (s[i - 1] == s[i + len - 2]) && (pal[i + 1][i + len - 2]);
            }
        }
        for (int i = k; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int j = i - k; j >= 0; j--) {
                if (pal[j + 1][i]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return dp[n];
    }
};