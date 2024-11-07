class Solution {
public:
    int deleteString(string s) {
        int n = s.length();
        int dp[n], pre[n + 1];
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int i = 0; i <= n; i++) pre[i] = 0;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) pre[j] = pre[j + 1] + 1;
                else pre[j] = 0;
                if (pre[j] >= j - i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[0];
    }
};