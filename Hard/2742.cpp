class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = 2e9;
        int dp[n + 500 + 1];
        for (int j = 0; j <= n + 500; j++) {
            dp[j] = INF;
        }
        dp[0] = 0;
        dp[time[0] + 1] = cost[0];
        for (int i = 1; i < n; i++) {
            for (int j = n + 500; j >= 0; j--) {
                if (j >= time[i] + 1 && dp[j - time[i] - 1] != INF) {
                    dp[j] = min(dp[j], dp[j - time[i] - 1] + cost[i]);
                }
            }
        }
        int ans = INF;
        for (int j = n; j <= n + 500; j++) {
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};