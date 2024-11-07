class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int cur = 1;
        int last = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                cur++;
            } else {
                ans += 1ll * cur * (cur + 1) / 2;
                cur = 1;
            }
            last = prices[i - 1];
        }
        ans += 1ll * cur * (cur + 1) / 2;
        return ans;
    }
};