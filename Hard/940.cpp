class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        const int MOD = 1e9 + 7;
        int dp[n], le[n], last[26];
        memset(last, -1, sizeof(last));
        for (int i = 0; i < n; i++) {
            le[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }
        dp[0] = 2;
        for (int i = 1; i < n; i++) {
            dp[i] = (dp[i - 1] * 2) % MOD;
            if (le[i] >= 0) {
                dp[i] = (dp[i] - (le[i] ? dp[le[i] - 1] : 1)) % MOD;
            }
        }
        int ret = (dp[n - 1] - 1) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }
};