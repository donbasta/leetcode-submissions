class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int A = 1000;
        int n = scores.size();
        vector<vector<int>> dp(n + 1, vector<int>(A + 1));
        vector<pair<int, int>> bruh;
        for (int i = 0; i < n; i++) {
            bruh.emplace_back(scores[i], ages[i]);
        }
        sort(bruh.begin(), bruh.end());
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 1; j <= bruh[i - 1].second; j++) {
                tmp = max(tmp, dp[i - 1][j]);
            }
            dp[i][bruh[i - 1].second] = tmp + bruh[i - 1].first;
            for (int j = 1; j <= A; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= A; i++) {
            ans = max(ans, dp[n][i]);
        }
        return ans;
    }
};