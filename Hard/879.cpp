class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        // dp[j][k] --> tepat i orang dengan profit tepat k ada berapa cara 
        const int M = 100;
        const int MOD = 1e9 + 7;
        int dp[n + 1][minProfit + 1];
        // int all[n + 1];
        memset(dp, 0, sizeof(dp));
        // memset(all, 0, sizeof(all));
        dp[0][0]++;
        if (group[0] <= n) {
            for (int i = 0; i <= min(minProfit, profit[0]); i++) dp[group[0]][i]++;
        }

        int m = group.size();
        for (int i = 1; i < m; i++) {
            for (int j = n; j >= 0; j--) {
                if (j < group[i]) break;
                for (int k = minProfit; k >= 0; k--) {
                    dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = (ans + dp[i][minProfit]) % MOD;
        }
        return ans;
    }
};