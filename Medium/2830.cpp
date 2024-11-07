class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<vector<int>>> end(n);
        for (auto offer : offers) {
            end[offer[1]].push_back({offer[0], offer[2]});
        }
        vector<int> dp(n);
        for (int i = 0; i <= n - 1; i++) {
            if (i) dp[i] = dp[i - 1];
            for (auto x : end[i]) {
                dp[i] = max(dp[i], x[1] + (x[0] ? dp[x[0] - 1] : 0));
            }
        }
        return dp[n - 1];
    }
};