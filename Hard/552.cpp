class Solution {
public:
    int checkRecord(int n) {
        
        const int MOD = 1e9 + 7;
        const auto f = [&](int& a, int b) -> void {
            a = (a + b) % MOD;
        };
        
        int dp[n + 1][2][4]; //length, number of absent, state of last days
        int dps[n + 1][2];
        memset(dp, 0, sizeof(dp));
        memset(dps, 0, sizeof(dps));
        dps[0][0] = 1;
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            f(dp[i][1][0], dps[i - 1][0]); //add absent
            f(dp[i][0][0], dps[i - 1][0]); //add present
            f(dp[i][1][0], dps[i - 1][1]); //add present
            for (int j = 0; j < 2; j++) {
                f(dp[i][j][1], dp[i - 1][j][0]);
                f(dp[i][j][2], dp[i - 1][j][1]);
            }
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 2; k++) {
                    f(dps[i][k], dp[i][k][j]);
                }
            }
        }
        int ans = (dps[n][0] + dps[n][1]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};