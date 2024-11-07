class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366);
        vector<bool> ada(366);
        for (auto e : days) ada[e] = true;
        for (int i = 1; i <= 365; i++) {
            int tmp = INT_MAX;
            if (i >= 1) tmp = min(tmp, min({costs[0], costs[1], costs[2]}) + dp[i - 1]);
            if (i >= 7) tmp = min(tmp, min(costs[1], costs[2]) + dp[i - 7]);
            if (i >= 30) tmp = min(tmp, costs[2] + dp[i - 30]);
            if (!ada[i]) tmp = min(tmp, dp[i - 1]);
            dp[i] = tmp;
        }
        return dp[365];
    }
};