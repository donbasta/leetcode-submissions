class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        int dp[n + 1][10];
        memset(dp, 0, sizeof(dp));
        vector<int> prv[10] = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4},
        };
        for (int i = 0; i < 10; i++) dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (auto c : prv[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][c]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + dp[n][i]) % MOD;
        }
        return ans;
    }
};