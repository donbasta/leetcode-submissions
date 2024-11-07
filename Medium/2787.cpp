class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<vector<int>> ndp(n + 1, vector<int>(n + 1));
        const function<int(int, int)> powx = [&](int a, int b) -> int {
            int ret = 1;
            for (int i = 0; i < b; i++) ret *= a;
            return ret;
        };
        
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) ndp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; powx(j, x) <= i; j++) {
                if (i == pow(j, x)) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = ndp[i - pow(j, x)][j - 1];
                }
            }
            for (int j = 1; j <= n; j++) {
                ndp[i][j] = (1ll * ndp[i][j - 1] + dp[i][j]) % MOD;
            }
            
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (1ll * ans + dp[n][i]) % MOD;
        }
        return ans;
    }
};