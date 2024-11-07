class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        vector<vector<long long>> dp(ns + 1, vector<long long>(nt + 1, 0));
        const long long MOD = 1e10;
        for (int i = 0; i <= ns; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= nt; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }
        long long ans = dp[ns][nt] % MOD;
        if (ans < 0) ans += MOD;
        return (int) ans;
    }
};