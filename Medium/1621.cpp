class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        
        int dp[n], prv[n];
        memset(prv, 0, sizeof(prv));
        for (int i = 0; i < n; i++) prv[i] = n - i;

        for (int j = 1; j <= k; j++) {
            for (int i = n - 2; i >= 0; i--) {
                dp[i] = prv[i + 1];
            }
            prv[n - 1] = 0; 
            for (int i = n - 2; i >= 0; i--) {
                prv[i] = (prv[i + 1] + dp[i]) % MOD;
            }
            for (int i = n - 2; i >= 0; i--) {
                prv[i] = (prv[i] + prv[i + 1]) % MOD;
            }
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};