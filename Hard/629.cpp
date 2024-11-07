class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        //dp[i][j] = dp[i - 1][j] + ... + dp[i - 1][j - i + 1]
        vector<int> pre(k + 1, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> tmp(k + 1);
            tmp[0] = 1;
            for (int j = 1; j <= k; j++) {
                tmp[j] = pre[j] - (j - i >= 0 ? pre[j - i] : 0);
                tmp[j] = (((tmp[j] % MOD) + MOD) % MOD);
            }
            pre[0] = tmp[0];
            for (int j = 1; j <= k; j++) {
                pre[j] = (pre[j - 1] + tmp[j]) % MOD;
            }
        }
        int ans = (pre[k] - (k ? pre[k - 1] : 0));
        ans %= MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};