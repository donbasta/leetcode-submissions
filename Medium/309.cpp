class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1), mdp(n + 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i] = max(dp[i], -prices[i] + prices[j] + mdp[min(n, j + 2)]); 
            }
            mdp[i] = max(mdp[i + 1], dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};