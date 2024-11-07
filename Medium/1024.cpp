class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        const int M = 100, INF = 200;
        vector<int> prv(M + 1, INF), dp(M + 1, -1);
        for (auto c : clips) {
            prv[c[1]] = min(prv[c[1]], c[0]);
        }
        for (int i = 1; i <= M; i++) {
            if (prv[i] == 0) {
                dp[i] = 1;
            } else if (prv[i] != INF) {
                for (int j = prv[i]; j < i; j++) {
                    if (dp[j] != -1) {
                        if (dp[i] == -1) dp[i] = dp[j] + 1;
                        else dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = time; i <= M; i++) {
            if (dp[i] != -1) {
                ans = min(ans, dp[i]);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};