class Solution {
public:
    int countWinningSequences(string s) {
        int n = s.length();
        int dp[n][2 * n + 5][3];
        memset(dp, 0, sizeof(dp));
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'E') A[i] = 0;
            else if (s[i] == 'F') A[i] = 1;
            else if (s[i] == 'W') A[i] = 2;
        }
        const int MOD = 1e9 + 7;

        dp[0][1][A[0]] = 1;
        dp[0][0][(A[0] + 2) % 3] = 1;
        dp[0][2][(A[0] + 1) % 3] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 2 * (i + 1); j++) {
                for (int k = 0; k < 3; k++) {
                    for (int t = 1; t <= 2; t++) {
                        int turn = (k + t) % 3;
                        if (k == A[i]) {
                            if (j >= 1 && j - 1 <= 2 * i) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][turn]) % MOD;
                        } else if ((k == (A[i] + 1) % 3)) {
                            if (j >= 2) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 2][turn]) % MOD;
                        } else if ((k == (A[i] + 2) % 3)) {
                            if (j <= 2 * i) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][turn]) % MOD;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            ans = (ans + dp[n - 1][i][0]) % MOD;
            ans = (ans + dp[n - 1][i][1]) % MOD;
            ans = (ans + dp[n - 1][i][2]) % MOD;
        }
        return ans;
    }
};