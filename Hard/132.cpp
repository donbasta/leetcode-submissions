class Solution {
public:
    int minCut(string s) {
        int n = s.length();
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
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (pal[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] - 1;
    }
};