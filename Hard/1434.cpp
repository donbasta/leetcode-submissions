class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        // dp[i][s] --> until topi ke i, set orang yang udah dapet

        int n = hats.size();
        vector<int> wants[41];
        for (int i = 0; i < n; i++) {
            for (auto h : hats[i]) {
                wants[h].push_back(i);
            }
        }
        int tot_mask = (1 << n) - 1;
        int dp[41][1 << n];
        memset(dp, 0, sizeof(dp));
        const int MOD = 1e9 + 7;

        dp[0][0] = 1;
        for (int i = 1; i <= 40; i++) {
            for (int j = 0; j < (1 << n); j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int k : wants[i]) {
                for (int j = 0; j < (1 << n); j++) {
                    if ((j >> k) & 1) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j ^ (1 << k)]) % MOD;
                    }
                }
            }
        }

        return dp[40][tot_mask];
    }

};