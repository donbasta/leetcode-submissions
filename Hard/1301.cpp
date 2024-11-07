class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& B) {
        int n = B.size();

        const int MOD = 1e9 + 7;
        int M = 9 * (2 * n - 1);
        int dp[n][n][M + 1];
        bool can[n][n][M + 1];
        memset(dp, 0, sizeof(dp));
        memset(can, 0, sizeof(can));
        dp[n - 1][n - 1][0] = 1;
        can[n - 1][n - 1][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (B[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;
                int cur;
                if (i == 0 && j == 0) cur = 0;
                else cur = B[i][j] - '0';
                for (int sum = cur; sum <= M; sum++) {
                    if (j < n - 1) dp[i][j][sum] = (dp[i][j][sum] + dp[i][j + 1][sum - cur]) % MOD;
                    if (i < n - 1) dp[i][j][sum] = (dp[i][j][sum] + dp[i + 1][j][sum - cur]) % MOD;
                    if (i < n - 1 && j < n - 1) {
                        dp[i][j][sum] = (dp[i][j][sum] + dp[i + 1][j + 1][sum - cur]) % MOD;
                    }
                    if (j < n - 1) if (can[i][j + 1][sum - cur]) can[i][j][sum] = true;
                    if (i < n - 1) if (can[i + 1][j][sum - cur]) can[i][j][sum] = true;
                    if (i < n - 1 && j < n - 1) {
                        if (can[i + 1][j + 1][sum - cur]) can[i][j][sum] = true;
                    }
                }
            }
        }
        vector<int> ret(2, 0);
        for (int i = M; i >= 0; i--) {
            if (can[0][0][i]) {
                ret[0] = i;
                ret[1] = dp[0][0][i];
                return ret;
            }
        }
        return ret;
    }
};