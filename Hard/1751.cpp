class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end(), [&](vector<int> a, vector<int> b) -> bool {
            return a[1] < b[1];
        });
        int n = events.size();
        // vector<int> end_day(n);
        int end_day[n];
        for (int i = 0; i < n; i++) {
            end_day[i] = events[i][1];
        }

        const int INF = 2e9;
        // vector<vector<int>> dp(n, vector<int>(k + 1));
        int dp[n][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = events[0][2];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][1] = max(dp[i][1], events[i][2]);
            for (int j = 1; j <= k; j++) {
                int t = lower_bound(end_day, end_day + n, events[i][0]) - end_day;
                if (t > 0 && j <= t + 1) {
                    dp[i][j] = max(dp[i][j], dp[t - 1][j - 1] + events[i][2]);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};