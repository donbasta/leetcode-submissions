class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        if (ans < 0) ans += MOD;
        return ans;
    }
};