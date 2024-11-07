class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ret;
        vector<vector<int>> prv(n);
        for (auto q : queries) {
            vector<int> dp(n, INT_MAX);
            dp[0] = 0;
            prv[q[1]].push_back(q[0]);
            for (int i = 1; i < n; i++) {
                dp[i] = dp[i - 1] + 1;
                for (auto c : prv[i]) {
                    dp[i] = min(dp[i], dp[c] + 1);
                }
            }
            ret.push_back(dp.back());
        }
        return ret;
    }
};