class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int sum[1 << n];
        for (int mask = 0; mask < (1 << n); mask++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) tmp += jobs[j];
            }
            sum[mask] = tmp;
        }

        int dp[1 << n][k];
        const int INF = 2e9;
        for (int i = 0; i < (1 << n); i++) for (int j = 0; j < k; j++) dp[i][j] = INF;
        for (int i = 0; i < (1 << n); i++) dp[i][0] = sum[i]; 
        for (int i = 1; i < k; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[mask][i] = dp[mask][i - 1];
                for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                    assert ((mask & submask) == submask);
                    dp[mask][i] = min(dp[mask][i], max(dp[mask ^ submask][i - 1], sum[submask]));
                }
            }
        }

        return dp[(1 << n) - 1][k - 1];
    }
};