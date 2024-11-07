class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int n = zero + one;
        
        const int MOD = 1e9 + 7;
        
        vector<vector<int>> dp0(n + 1, vector<int>(n + 1));
        vector<vector<int>> dp1(n + 1, vector<int>(n + 1));
        
        dp0[0][0] = dp1[0][0] = 1;
        dp0[1][1] = 1;
        dp1[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                {
                    int x = 0;
                    if (j >= 1) x = (x + dp0[i - 1][j - 1]) % MOD;
                    if (j >= 1) x = (x + dp1[i - 1][j - 1]) % MOD;
                    if (j >= limit + 1) x = (x - dp1[i - limit - 1][j - limit - 1]) % MOD;
                    if (x < 0) x += MOD;
                    dp0[i][j] = x;
                }
                {
                    int x = 0;
                    x = (x + dp0[i - 1][j]) % MOD;
                    x = (x + dp1[i - 1][j]) % MOD;
                    if (i >= limit + 1) x = (x - dp0[i - limit - 1][j]) % MOD;
                    if (x < 0) x += MOD;
                    dp1[i][j] = x;
                }
            }
        }
        
        int ans = (dp0[n][zero] + dp1[n][zero]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};