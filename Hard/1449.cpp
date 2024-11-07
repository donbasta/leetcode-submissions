class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int dp[target + 1], pr[target + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        const int INF = 2e9;
        for (int i = 1; i <= target; i++) {
            int tmp = -1;
            int prv = -1;
            for (int j = 0; j < 9; j++) {
                if (i < cost[j]) continue;
                if (dp[i - cost[j]] == -1) continue;
                if (dp[i - cost[j]] + 1 >= tmp) {
                    tmp = dp[i - cost[j]] + 1;
                    prv = j;
                }
            }
            if (tmp >= 1) {
                dp[i] = tmp;
                pr[i] = prv;
            }
        }
        if (dp[target] == -1) {
            return "0";
        }
        string ret;
        int cur = target;
        while (cur > 0) {
            ret.push_back(char(pr[cur] + '1'));
            cur -= cost[pr[cur]];
        }
        sort(ret.begin(), ret.end(), greater<>());
        return ret;
    }
};