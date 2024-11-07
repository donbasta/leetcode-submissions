class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        int dp[n];
        bool is_prime[10];
        memset(is_prime, 0, sizeof(is_prime));
        is_prime[2] = is_prime[3] = is_prime[5] = is_prime[7] = true;

        for (int i = 0; i < n; i++) {
            if (i < minLength - 1) dp[i] = 0;
            else dp[i] = (is_prime[s[0] - '0'] && (!is_prime[s[i] - '0']));
        }

        for (int i = 2; i <= k; i++) {
            int pre[n], ndp[n];
            for (int j = 0; j < n; j++) {
                pre[j] = ((j ? pre[j - 1] : 0) + (j == n - 1 || is_prime[s[j + 1] - '0'] ? dp[j] : 0)) % MOD;
            }
            for (int j = 0; j < n; j++) {
                if (j < minLength * i - 1) {
                    ndp[j] = 0;
                    continue;
                }
                if (is_prime[s[j] - '0']) {
                    ndp[j] = 0;
                } else {
                    ndp[j] = pre[j - minLength];
                }
            }
            for (int i = 0; i < n; i++) dp[i] = ndp[i];
        }
        return dp[n - 1];
    }
};